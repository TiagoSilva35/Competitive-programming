from time import perf_counter
from typing import cast, Union, TypeVar, Protocol, Optional, Union
from collections.abc import Iterable

Objective = Union[float, int]

TObjective = TypeVar('TObjective', bound=Objective, covariant=True)
TLocalMove = TypeVar('TLocalMove')

class Solution(Protocol[TObjective, TLocalMove]):
    def random_local_moves_wor(self) -> Iterable[TLocalMove]: ...
    def objective_incr_local(self, lmove: TLocalMove) -> Optional[TObjective]: ...
    def step(self, lmove: TLocalMove) -> None: ...

TSolution = TypeVar('TSolution', bound=Solution)

def first_improvement(solution: TSolution, budget: float) -> TSolution:
    "First-improvement local search"
    start = perf_counter()
    while perf_counter() - start < budget:
        # for move in solution.enumLocalMove():
        for move in solution.random_local_moves_wor():
            incr = cast(Objective, solution.objective_incr_local(move))
            if incr < 0:
                solution.step(move)
                break
            if perf_counter() - start >= budget:
                return solution
        else:
            break
    return solution
