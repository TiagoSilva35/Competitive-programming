from typing import TypeVar, Protocol, Optional

Component = TypeVar('Component')

class Solution(Protocol[Component]):
    def heuristic_add_move(self) -> Optional[Component]: ...
    def add(self, component: Component) -> None: ...

T = TypeVar('T', bound=Solution)

def heuristic_construction(solution: T) -> T:
    c = solution.heuristic_add_move()
    while c is not None:
        solution.add(c)
        c = solution.heuristic_add_move()
    return solution
