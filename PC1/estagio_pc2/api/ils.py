from time import perf_counter
from typing import cast, Union, TypeVar, Optional, Protocol
from collections.abc import Iterable

Objective = Union[float, int]

TObjective = TypeVar('TObjective', bound=Objective, covariant=True)
TLocalMove = TypeVar('TLocalMove')
TSelfSolution = TypeVar('TSelfSolution', bound='Solution')

class Solution(Protocol[TObjective, TLocalMove]):
    def objective(self) -> TObjective: ...
    def copy(self: TSelfSolution) -> TSelfSolution: ...
    def random_local_moves_wor(self) -> Iterable[TLocalMove]: ...
    def objective_incr_local(self, lmove: TLocalMove) -> Optional[TObjective]: ...
    def step(self, lmove: TLocalMove) -> None: ...
    def perturb(self, ks: int) -> None: ...

TSolution = TypeVar('TSolution', bound=Solution)

def ils(solution: TSolution, budget: float, ks: int = 3) -> TSolution:
    start = perf_counter()
    best = solution.copy()
    best_obj = cast(Objective, best.objective())
    while perf_counter() - start < budget:
        # for move in solution.enumLocalMove():
        for move in solution.random_local_moves_wor():
            incr = cast(Objective, solution.objective_incr_local(move))
            if incr < 0:
                solution.step(move)
                break
            if perf_counter() - start >= budget:
                obj = cast(Objective, solution.objective())
                if obj < best_obj:
                    return solution
                else:
                    return best
        else:
            # Local optimum found
            obj = cast(Objective, solution.objective())
            if obj <= best_obj:
                best = solution.copy()
                best_obj = obj
            else:
                solution = best.copy()
            solution.perturb(ks)
    obj = cast(Objective, solution.objective())
    if obj < best_obj:
        return solution
    else:
        return best
