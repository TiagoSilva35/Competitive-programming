from typing import cast, Protocol, TypeVar, Optional
from collections.abc import Iterable
from operator import itemgetter

class Lt(Protocol):
    def __lt__(self, other) -> bool: ...

Objective = TypeVar('Objective', bound=Lt, covariant=True)
Component = TypeVar('Component')

class Solution(Protocol[Objective, Component]):
    def add_moves(self) -> Iterable[Component]: ...
    def add(self, component: Component) -> None: ...
    def lower_bound_incr_add(self, component: Component) -> Optional[Objective]: ...

T = TypeVar('T', bound=Solution)

def greedy_construction(solution: T) -> T:
    while True:
        best = min(filter(lambda v: v[0] is not None,
                          map(lambda c: (solution.lower_bound_incr_add(c), c),
                              solution.add_moves())),
                   default = None,
                   key = itemgetter(0))
        if best is None:
            break
        solution.add(best[1])
    return solution
