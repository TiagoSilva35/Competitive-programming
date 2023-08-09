from typing import Protocol, TypeVar, Any, Optional, Tuple
from collections.abc import Iterable, Callable
from operator import itemgetter
from itertools import tee
from math import ceil, log2
import random

T = TypeVar('T')

def argmax(v: Iterable[T]) -> int:
    return max(enumerate(v), key=itemgetter(1))[0]

def argmin(v: Iterable[T]) -> int:
    return min(enumerate(v), key=itemgetter(1))[0]

def or_default(v: Optional[T], default: Callable[[], T]) -> T:
    return v if v is not None else default()

def non_repeating_lcg(n: int, seed: Optional[int] = None) -> Iterable[int]:
    if seed is not None:
        random.seed(seed)
    "Pseudorandom sampling without replacement in O(1) space"
    if n > 0:
        a = 5 # always 5
        m = 1 << ceil(log2(n))
        if m > 1:
            c = random.randrange(1, m, 2)
            x = random.randrange(m)
            for _ in range(m):
                if x < n: yield x
                x = (a * x + c) % m
        else:
            yield 0

def sample(n: int, seed: Optional[int] = None) -> Iterable[int]:
    for v in non_repeating_lcg(n, seed):
        yield v

def sample2(n: int, m: int, seed: Optional[int] = None) -> Iterable[Tuple[int, int]]:
    for v in non_repeating_lcg(n*m, seed):
        i = v // m
        j = v % m
        yield (i, j)

# FIXME(3.10): This can be replaced by itertools.pairwise if we use
# python 3.10
def pairwise(iterable: Iterable[T]) -> Iterable[Tuple[T, T]]:
    a, b = tee(iterable)
    next(b, None)
    return zip(a, b)
