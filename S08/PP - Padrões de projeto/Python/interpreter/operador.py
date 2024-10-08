from abc import ABC, abstractmethod


class Operador(ABC):
    @abstractmethod
    def interpretar(self) -> int:
        pass
