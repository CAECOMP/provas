from abc import ABC, abstractmethod


class InterfaceRobo(ABC):
    @abstractmethod
    def criar_cabeca(self, cabeca: str) -> None:
        pass

    @abstractmethod
    def criar_troco(self, tronco: str) -> None:
        pass
    
    @abstractmethod
    def criar_bracos(self, bracos: str) -> None:
        pass
    
    @abstractmethod
    def criar_pernas(self, pernas: str) -> None:
        pass
