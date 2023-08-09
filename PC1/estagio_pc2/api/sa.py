from time import perf_counter
from typing import cast, Optional, Union, TypeVar, Protocol
from math import exp
from collections.abc import Callable, Iterable
import random

Objective = TypeVar('Objective', bound=Union[float, int], covariant=True)
LocalMove = TypeVar('LocalMove')
SelfSolution = TypeVar('SelfSolution', bound='Solution')

class Solution(Protocol[Objective, LocalMove]):
    def objective(self) -> Objective: ...
    def copy(self: SelfSolution) -> SelfSolution: ...
    def random_local_moves_wor(self) -> Iterable[LocalMove]: ...
    def objective_incr_local(self, lmove: LocalMove) -> Optional[Objective]: ...
    def step(self, lmove: LocalMove) -> None: ...

T = TypeVar('T', bound=Solution)

class LinearDecay:
    def __init__(self, init_temp: float) -> None:
        self.init_temp = init_temp

    def __call__(self, t: float) -> float:
        return t * self.init_temp

class ExponentialAcceptance:
    def __init__(self) -> None:
        ...

    def __call__(self, incr: float, t: float) -> float:
        if incr <= 0:
            return 1.0
        else:
            return exp(-incr / t)

def sa(solution: T,
       budget: float,
       init_temp: float,
       seed: Optional[int] = None,
       temperature: Optional[Callable[[float], float]] = None,
       acceptance: Optional[Callable[[float, float], float]] = None) -> T:
    if seed is not None:
        random.seed(seed)
        
    if temperature is None:
        temperature = LinearDecay(init_temp)

    if acceptance is None:
        acceptance = ExponentialAcceptance()
       
    start = perf_counter()
    best = solution.copy()
    bestobj = best.objective()
    while perf_counter() - start < budget:
        for move in solution.random_local_moves_wor():
            t = temperature(1 - (perf_counter()-start) / budget)
            if t <= 0:
                break
            incr = cast(Union[float, int], solution.objective_incr_local(move))
            if acceptance(incr, t) >= random.random():
                solution.step(move)
                obj = cast(Union[float, int], solution.objective())
                if bestobj is None or obj < bestobj:
                    best = solution.copy()
                    bestobj = obj
                break
    return best
