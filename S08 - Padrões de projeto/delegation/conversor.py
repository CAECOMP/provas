from abc import ABC, abstractmethod


class Conversor(ABC):
    @abstractmethod
    def converter(self, valor: float) -> float:
        pass
