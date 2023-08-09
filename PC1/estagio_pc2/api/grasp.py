from typing import cast, TypeVar, Protocol, Optional, Union
from collections.abc import Callable, Iterable
from time import perf_counter
from operator import itemgetter
import random

Objective = Union[float, int]

TObjective = TypeVar('TObjective', bound=Objective, covariant=True)
TComponent = TypeVar('TComponent')
TSelfSolution = TypeVar('TSelfSolution', bound='Solution')

class Solution(Protocol[TObjective, TComponent]):
    def lower_bound(self) -> Optional[TObjective]: ...
    def objective(self) -> Optional[TObjective]: ...
    def copy(self: TSelfSolution) -> TSelfSolution: ...
    def is_feasible(self) -> bool: ...
    def add_moves(self) -> Iterable[TComponent]: ...
    def lower_bound_incr_add(self, component: TComponent) -> Optional[TObjective]: ...
    def add(self, component: TComponent) -> None: ...

T = TypeVar('T', bound=Solution)
    
class LocalSearch(Protocol[T]):
    def __call__(self, s: T, **kwargs) -> Optional[T]: ...

def grasp(solution: T,
          budget: float,
          alpha: float = 0.1,
          seed: Optional[int] = None,
          local_search: Optional[LocalSearch] = None,
          **kwargs) -> Optional[T]:
    if seed is not None:
        random.seed(seed)
    start = perf_counter()
    best, bestobj = None, None
    while perf_counter() - start < budget:
        s = solution.copy()
        b, bobj = (s.copy(), s.objective()) if s.is_feasible() else (None, None)
        C = [(cast(Objective, s.lower_bound_incr_add(c)), c) for c in s.add_moves()]
        while len(C) != 0:
            cmin = min(C, key=itemgetter(0))[0]
            cmax = max(C, key=itemgetter(0))[0]
            thresh = cmin + alpha * (cmax - cmin)
            RCL = [c for decr, c in C if decr <= thresh]
            c = random.choice(RCL)
            s.add(c)
            if s.is_feasible():
                obj = cast(Objective, s.objective())
                if bobj is None or obj < bobj:
                    b, bobj = s.copy(), obj
            C = [(cast(Objective, s.lower_bound_incr_add(c)), c) for c in s.add_moves()]
        if b is not None:
            if local_search is not None:
                b = local_search(b, **kwargs)
                if b is not None and b.is_feasible():
                    bobj = cast(Objective, b.objeive())
            if bestobj is None or bobj < bestobj:
                best, bestobj = b, bobj
    return best
