from typing import cast, TypeVar, Union, Any, List, Tuple, Protocol, Optional
from collections.abc import Iterable
from operator import itemgetter

T = TypeVar('T')

class Objective(Protocol):
    def __lt__(self: T, other: T) -> bool: ...
    def __add__(self: T, other: T) -> T: ...

TObjective = TypeVar('TObjective', bound=Objective, covariant=True)
TComponent = TypeVar('TComponent')
TSelfSolution = TypeVar('TSelfSolution', bound='Solution')

class Solution(Protocol[TObjective, TComponent]):
    def objective(self) -> Optional[TObjective]: ...
    def lower_bound(self) -> Optional[TObjective]: ...
    def copy(self: TSelfSolution) -> TSelfSolution: ...
    def is_feasible(self) -> bool: ...
    def add_moves(self) -> Iterable[TComponent]: ...
    def lower_bound_incr_add(self, component: TComponent) -> Optional[TObjective]: ...
    def add(self, component: TComponent) -> None: ...

TSolution = TypeVar('TSolution', bound=Solution)

BSList = List[Tuple[Objective, TSolution]]
BSCandidates = List[Tuple[Objective, TSolution, TComponent]]

def candidates(prev: BSList) -> BSCandidates:
    result: BSCandidates = []
    for lb, s in prev:
        result.extend(map(lambda c: (lb + cast(Objective, s.lower_bound_incr_add(c)), s, c),
                          s.add_moves()))
    return result

def evolve(candidates: BSCandidates, bw: int) -> BSList:
    result: BSList = []
    candidates.sort(key=itemgetter(0))
    for lb, s, c in candidates[:bw]:
        ns = s.copy()
        ns.add(c)
        result.append((lb, ns))
    return result

def beam_search(solution: TSolution, bw: int = 10) -> TSolution:
    best = solution
    bestobj = best.objective()
    v = [(cast(Objective, solution.lower_bound()), solution)]
    while True:
        c = candidates(v)
        if len(c) == 0:
            break
        v = evolve(c, bw)
        for _, s in v:
            if s.is_feasible():
                obj = cast(Objective, s.objective())
                if bestobj is None or obj < bestobj:
                    best, bestobj = s, obj
    return best
