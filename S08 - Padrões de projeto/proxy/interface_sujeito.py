from abc import ABC, abstractmethod


class InterfaceSujeito(ABC):
    @abstractmethod
    def requisicao(self) -> None:
        pass
