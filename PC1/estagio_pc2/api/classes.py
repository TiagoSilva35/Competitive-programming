from abc import ABC, abstractmethod
from typing import TypeVar, Optional, Generic, TextIO, Any
from collections.abc import Iterable, Hashable

TProblem = TypeVar('TProblem', bound='Problem')
TObjective = TypeVar('TObjective')
TComponent = TypeVar('TComponent', bound='Component')
TLocalMove = TypeVar('TLocalMove', bound='LocalMove')

# FIXME(3.11): these can be replaced by Self in 3.11
SelfSolution = TypeVar('SelfSolution', bound='Solution')
SelfProblem = TypeVar('SelfProblem', bound='Problem')

class Solution(ABC, Generic[TProblem, TObjective, TComponent, TLocalMove]):
    def copy(self: SelfSolution) -> SelfSolution:
        """
        Return a copy of this solution.

        Note: changes to the copy must not affect the original
        solution. However, this does not need to be a deepcopy.
        """
        raise NotImplementedError

    def is_feasible(self) -> bool:
        """
        Return whether the solution is feasible or not
        """
        raise NotImplementedError

    def objective(self) -> Optional[TObjective]:
        """
        Return the objective value for this solution if defined, otherwise
        should return None
        """
        raise NotImplementedError

    def lower_bound(self) -> Optional[TObjective]:
        """
        Return the lower bound value for this solution if defined,
        otherwise return None
        """
        raise NotImplementedError

    def add_moves(self) -> Iterable[TComponent]:
        """
        Return an iterable (generator, iterator, or iterable object)
        over all components that can be added to the solution
        """
        raise NotImplementedError

    def local_moves(self) -> Iterable[TLocalMove]:
        """
        Return an iterable (generator, iterator, or iterable object)
        over all local moves that can be applied to the solution
        """
        raise NotImplementedError

    def random_add_move(self) -> Optional[TComponent]:
        """
        Return a random component that can be added to the solution.

        Note: repeated calls to this method may return the same
        component.
        """
        raise NotImplementedError

    def random_local_move(self) -> Optional[TLocalMove]:
        """
        Return a random local move that can be applied to the solution.

        Note: repeated calls to this method may return the same
        local move.
        """
        raise NotImplementedError

    def random_add_moves_wor(self) -> Iterable[TComponent]:
        """
        Return an iterable (generator, iterator, or iterable object)
        over all components (in random order) that can be added to the
        solution.
        """
        raise NotImplementedError

    def random_local_moves_wor(self) -> Iterable[TLocalMove]:
        """
        Return an iterable (generator, iterator, or iterable object)
        over all local moves (in random order) that can be applied to
        the solution.
        """
        raise NotImplementedError

    def heuristic_add_move(self) -> Optional[TComponent]:
        """
        Return the next component to be added based on some heuristic
        rule.
        """
        raise NotImplementedError

    def add(self, component: TComponent) -> None:
        """
        Add a component to the solution.

        Note: this invalidates any previously generated components and
        local moves.
        """
        raise NotImplementedError

    def step(self, localmove: TLocalMove) -> None:
        """
        Apply a local move to the solution.

        Note: this invalidates any previously generated components and
        local moves.
        """
        raise NotImplementedError

    def objective_incr_add(self, component: TComponent) -> Optional[TObjective]:
        """
        Return the objective value increment resulting from adding a
        component. If the objective value is not defined after adding
        the component return None.
        """
        raise NotImplementedError

    def objective_incr_local(self, localmove: TLocalMove) -> Optional[TObjective]:
        """
        Return the objective value increment resulting from applying a
        local move. If the objective value is not defined after
        applying the local move return None.
        """
        raise NotImplementedError

    def lower_bound_incr_add(self, component: TComponent) -> Optional[TObjective]:
        """
        Return the lower bound increment resulting from adding a
        component. If the lower bound is not defined after adding the
        component return None.
        """
        raise NotImplementedError

    def lower_bound_incr_local(self, localmove: TLocalMove) -> Optional[TObjective]:
        """
        Return the lower bound increment resulting from applying a
        local move. If the lower bound is not defined after applying
        the local move return None.
        """
        raise NotImplementedError

    def perturb(self, ks: int) -> None:
        """
        Perturb the solution in place. The amount of perturbation is
        controlled by the parameter ks (kick strength)
        """
        raise NotImplementedError


class Component(ABC):
    def id(self) -> Hashable:
        """
        Get the id of a component, used for algorithm such as ACO
        """
        raise NotImplementedError


class LocalMove(ABC):
    ...

class Problem(ABC):
    @classmethod
    def from_textio(cls: type[SelfProblem], f: TextIO) -> SelfProblem:
        """
        Create a problem from a text I/O source `f`
        """
        raise NotImplementedError

    def empty_solution(self) -> Solution:
        """
        Create an empty solution (i.e. with no components).
        """
        raise NotImplementedError

    def random_solution(self, seed: Optional[Any]) -> Solution:
        """
        Create a random solution from an optional seed.
        """
        raise NotImplementedError

    def solution_from_textio(self, fileo: TextIO) -> Solution:
        """
        Create a solution from a text I/O source
        """
        raise NotImplementedError
