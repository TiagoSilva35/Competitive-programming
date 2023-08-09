#!/usr/bin/env python3

from typing import TextIO, List, Tuple, Optional, cast, NewType, Any, TypeVar
from collections.abc import Sequence, MutableSet, Iterable
from dataclasses import dataclass
from math import sqrt
from copy import copy
from itertools import chain

import api.classes
from api.utils import or_default, pairwise, sample2

@dataclass
class Node:
    x: int
    y: int
    h: int
    b: int

NodeList = NewType('NodeList', Sequence[Node])
DistMatrix = NewType('DistMatrix', Tuple[Tuple[int, ...], ...])

def manhattan_dist(a: Node, b: Node) -> int:
    return abs(a.x - b.x) + abs(a.y - b.y)

def distance_matrix(nodes: NodeList) -> DistMatrix:
    mat = []
    for a in nodes:
        row = []
        for b in nodes:
            row.append(manhattan_dist(a, b))
        mat.append(tuple(row))
    return DistMatrix(tuple(mat))

class CandleRace():
    def __init__(self, nodes: NodeList) -> None:
        self.n = len(nodes)
        self.nodes = nodes
        self.dist = distance_matrix(nodes)
        
    @classmethod
    def from_textio(cls, f: TextIO) -> 'CandleRace':
        """
        Create a problem from a text I/O source `f`
        """
        n = int(f.readline())
        nodes = []
        x, y = map(int, f.readline().strip().split())
        nodes.append(Node(x, y, 0, 0))
        for _ in range(1, n):
            x, y, h, b = map(int, f.readline().strip().split())
            nodes.append(Node(x, y, h, b))
        return cls(NodeList(tuple(nodes)))

    def empty_solution(self) -> 'Solution':
        """
        Create an empty solution (i.e. with no components).
        """
        unused = set(range(1,self.n))
        return Solution(self,[0],unused,0,0)

class Solution():
    def __init__(self,problem,path,unused,score,timer):
        """
        Initialize a solution
        """
        self.problem = problem
        self.path = path
        self.unused = unused
        self.score = score
        self.timer = timer

    def output(self) -> str:
        """
        Generate the output string for this solution
        """
        return "\n".join(map(str,(self.path)))

    def copy(self):
        """
        Return a copy of this solution.

        Note: changes to the copy must not affect the original
        solution. However, this does not need to be a deepcopy.
        """
        

    def is_feasible(self) -> bool:
        """
        Return whether the solution is feasible or not
        """
        return len(self.unused)==0

    def objective(self) -> Optional[int]:
        """
        Return the objective value for this solution if defined, otherwise
        should return None
        """
        if not self.is_feasible():
            return None
        else:
            last = self.path[-1]
            first = self.path[0]
            return self.score + self.problem.dist[last][first]

    def lower_bound(self) -> Optional[int]:
        """
        Return the lower bound value for this solution if defined,
        otherwise return None
        """
        raise NotImplementedError

    def add_moves(self) -> Iterable['Component']:
        """
        Return an iterable (generator, iterator, or iterable object)
        over all components that can be added to the solution
        """
        u = self.path[-1]
        h = self.problem.nodes[u].h
        b = self.problem.nodes[u].b
        for i in self.unused:
            yield Component(u,i,h,b)

    def local_moves(self) -> Iterable['LocalMove']:
        """
        Return an iterable (generator, iterator, or iterable object)
        over all local moves that can be applied to the solution
        """
        raise NotImplementedError

    def random_local_move(self) -> Optional['LocalMove']:
        """
        Return a random local move that can be applied to the solution.

        Note: repeated calls to this method may return the same
        local move.
        """
        raise NotImplementedError

    def random_local_moves_wor(self) -> Iterable['LocalMove']:
        """
        Return an iterable (generator, iterator, or iterable object)
        over all local moves (in random order) that can be applied to
        the solution.
        """
        raise NotImplementedError

    def heuristic_add_move(self) -> Optional['Component']:
        """
        Return the next component to be added based on some heuristic
        rule.
        """
        raise NotImplementedError

    def add(self, component: 'Component') -> None:
        """
        Add a component to the solution.

        Note: this invalidates any previously generated components and
        local moves.
        """
        h = component.h
        b = component.b
        u = component.u
        assert u == self.path[-1]
        v = component.v
        self.path.append(v)
        self.unused.remove(v)
        self.timer += self.problem.dist[u][v]
        self.score +=  h - (self.timer*b)

    def step(self, lmove: 'LocalMove') -> None:
        """
        Apply a local move to the solution.

        Note: this invalidates any previously generated components and
        local moves.
        """
        raise NotImplementedError

    def objective_incr_local(self, lmove: 'LocalMove') -> Optional[int]:
        """
        Return the objective value increment resulting from applying a
        local move. If the objective value is not defined after
        applying the local move return None.
        """
        raise NotImplementedError

    def lower_bound_incr_add(self, component: 'Component') -> Optional[int]:
        """
        Return the lower bound increment resulting from adding a
        component. If the lower bound is not defined after adding the
        component return None.
        """
        u = component.u
        v = component.v
        return self.problem.dist[u][v]

    def perturb(self, ks: int) -> None:
        """
        Perturb the solution in place. The amount of perturbation is
        controlled by the parameter ks (kick strength)
        """
        raise NotImplementedError

@dataclass
class Component():
    u : int
    v : int
    h : int 
    b : int

@dataclass
class LocalMove():
    ...

if __name__ == '__main__':
    from api.solvers import *
    from time import perf_counter
    import argparse
    import sys

    parser = argparse.ArgumentParser()
    parser.add_argument('csearch', choices=['beam', 'grasp', 'greedy', 'heuristic', 'none'])
    parser.add_argument('lsearch', choices=['bi', 'fi', 'ils', 'rls', 'sa', 'none'])
    parser.add_argument('infile', nargs='?', type=argparse.FileType('r'), default=sys.stdin)
    args = parser.parse_args()

    p = CandleRace.from_textio(args.infile)
    s: Optional[Solution] = p.empty_solution()

    start = perf_counter()

    if s is not None:
        if args.csearch == 'beam':
            s = beam_search(s, 10)
        elif args.csearch == 'grasp':
            s = grasp(s, 5, alpha = 0.001)
        elif args.csearch == 'greedy':
            s = greedy_construction(s)
        elif args.csearch == 'heuristic':
            s = heuristic_construction(s)

    if s is not None:
        if args.lsearch == 'bi':
            s = best_improvement(s, 5)
        elif args.lsearch == 'fi':
            s = first_improvement(s, 5)
        elif args.lsearch == 'ils':
            s = ils(s, 5)
        elif args.lsearch == 'rls':
            s = rls(s, 5)
        elif args.lsearch == 'sa':
            s = sa(s, 5, 10)

    end = perf_counter()

    if s is not None:
        print(s.output())
        print(f"Objective: {s.objective():.3f}", file=sys.stderr)
    else:
        print("Objective: no solution found", file=sys.stderr)

    print(f"Time:      {end-start:.4f}", file=sys.stderr)
