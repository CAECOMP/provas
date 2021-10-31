from abc import ABC, abstractmethod
from robo import Robo


class InterfaceConstrutorRobo(ABC):
    @abstractmethod
    def criar_cabeca_robo(self) -> None:
        pass

    @abstractmethod
    def criar_tronco_robo(self) -> None:
        pass
    
    @abstractmethod
    def criar_bracos_robo(self) -> None:
        pass
    
    @abstractmethod
    def criar_pernas_robo(self) -> None:
        pass

    @abstractmethod
    def resetar(self) -> None:
        pass

    @abstractmethod
    def retornar_robo_criado(self) -> Robo:
        pass
    