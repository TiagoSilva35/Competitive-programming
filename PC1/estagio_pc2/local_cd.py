#!/usr/bin/env python3

from typing import TextIO, List, Tuple, Optional, cast, NewType, Any, TypeVar
from collections.abc import Sequence, MutableSet, Iterable
from dataclasses import dataclass
from math import sqrt
from copy import copy
from itertools import chain

import api.classes
from api.utils import or_default, pairwise, sample2

WeightMatrix = NewType('WeightMatrix', Tuple[Tuple[float, ...], ...])

class CommunityDetection():
    def __init__(self, w: WeightMatrix) -> None:
        self.w = w
        self.nv = len(self.w)
        self.ub = 0
        for i in range(len(w)):
            for l in range(1+i, len(w[i])):
                if w[i][l] > 0:
                    self.ub += w[i][l]
        
    @classmethod
    def from_textio(cls, f: TextIO) -> 'CommunityDetection':
        """
        Create a problem from a text I/O source `f`
        """
        L = map(int, f.read().strip().split())
        n = next(L)
        w = [n*[0] for _ in range(n)]
        for i in range(n):
            for j in range(i, n):
                w[j][i] = w[i][j] = next(L)
        return cls(WeightMatrix(tuple(map(tuple, w))))

    def empty_solution(self) -> 'Solution':
        """
        Create an empty solution (i.e. with no components).
        """
        return Solution(self, [], 0, [set() for _ in range(self.nv)],self.ub)

class Solution():
    def __init__(self, problem, clique, nc, comunities,ub):
        """
        Initialize a solution
        """
        self.problem = problem
        self.clique = clique
        self.nc = nc
        self.ub = ub
        self.comunities = comunities

    def output(self) -> str:
        """
        Generate the output string for this solution
        """
        lis =[]
        for i in range(self.nc):
            linha =[]
            
            for j in range (len(self.clique)):
            
                if self.clique[j] == i:
                    linha.append(str(j))
            lis.append(" ".join(linha))
        return "\n".join(lis)
                    
                    

    def copy(self):
        """
        Return a copy of this solution.

        Note: changes to the copy must not affect the original
        solution. However, this does not need to be a deepcopy.
        """
        return Solution(self.problem, self.clique.copy(), self.nc ) 

    def is_feasible(self) -> bool:
        """
        Return whether the solution is feasible or not
        """
        return self.problem.nv == len(self.clique)

    def objective(self) -> Optional[float]:
        """
        Return the objective value for this solution if defined, otherwise
        should return None
        """
        
        #objv = 0
        #for c in self.comunities:
            #for u in c:
                #for v in c:
                    #if u != v:
                        #objv += self.problem.w[u][v]                
        #return objv
        if self.is_feasible():
            return -self.ub 
        else: 
            return None
            

    def lower_bound(self) -> Optional[float]:
        """
        Return the lower bound value for this solution if defined,
        otherwise return None
        """
        return -self.ub

    def add_moves(self) -> Iterable['Component']:
        """
        Return an iterable (generator, iterator, or iterable object)
        over all components that can be added to the solution
        """
        v=len(self.clique)
        
        if v<self.problem.nv:
            for c in range(self.nc+1):
                yield Component(v,c)

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
        v = component.v
        c = component.c
        
        self.comunities[c].add(v)
        
        self.clique.append(c)
        if c == self.nc:
            self.nc += 1
        self.ub -= self.lower_bound_incr_add(component)

    def step(self, lmove: 'LocalMove') -> None:
        """
        Apply a local move to the solution.

        Note: this invalidates any previously generated components and
        local moves.
        """
        raise NotImplementedError

    def objective_incr_local(self, lmove: 'LocalMove') -> Optional[float]:
        """
        Return the objective value increment resulting from applying a
        local move. If the objective value is not defined after
        applying the local move return None.
        """
        raise NotImplementedError

    def lower_bound_incr_add(self, component: 'Component') -> Optional[float]:
        """
        Return the lower bound increment resulting from adding a
        component. If the lower bound is not defined after adding the
        component return None.
        """
        v = component.v
        c = component.c
        delta = 0
        for i in range(len(self.clique)):
            if (self.clique[i] == c):
                if (self.problem.w[i][v] < 0):
                    delta += self.problem.w[i][v]
            else:
                if (self.problem.w[i][v] > 0):
                    delta -= self.problem.w[i][v]
        return -delta

    def perturb(self, ks: int) -> None:
        """
        Perturb the solution in place. The amount of perturbation is
        controlled by the parameter ks (kick strength)
        """
        raise NotImplementedError

@dataclass
class Component():
    v: int
    c: int

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

    p = CommunityDetection.from_textio(args.infile)
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