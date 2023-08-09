from time import perf_counter
from typing import cast, Union, TypeVar, Protocol, Optional, Union
from collections.abc import Iterable

Objective = Union[float, int]

TObjective = TypeVar('TObjective', bound=Objective, covariant=True)
TLocalMove = TypeVar('TLocalMove')

class Solution(Protocol[TObjective, TLocalMove]):
    def local_moves(self) -> Iterable[TLocalMove]: ...
    def objective_incr_local(self, lmove: TLocalMove) -> Optional[TObjective]: ...
    def step(self, lmove: TLocalMove) -> None: ...

TSolution = TypeVar('TSolution', bound=Solution)

def best_improvement(solution: TSolution, budget: float) -> TSolution:
    "First-improvement local search"
    start = perf_counter()
    while perf_counter() - start < budget:
        best_incr: Objective = 0
        best_move = None
        for move in solution.local_moves():
            delta = cast(Objective, solution.objective_incr_local(move))
            if delta < best_incr:
                best_incr = delta
                best_move = move
            if perf_counter() - start >= budget:
                break
        if best_move is not None:
            solution.step(best_move)
        else:
            break
    return solution

