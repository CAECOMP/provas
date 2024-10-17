from abc import ABC, abstractmethod
from computador import ComputadorAbstrato, ComputadorModeloA, ComputadorModeloB
from teclado import TecladoAbstrato, TecladoModeloA, TecladoModeloB


class FabricaAbstrataKit(ABC):
    @abstractmethod
    def criar_computador(self) -> ComputadorAbstrato:
        pass

    @abstractmethod
    def criar_teclado(self) -> TecladoAbstrato:
        pass


class Kit1(FabricaAbstrataKit):
    def criar_computador(self) -> ComputadorAbstrato:
        return ComputadorModeloA()

    def criar_teclado(self) -> TecladoAbstrato:
        return TecladoModeloA()


class Kit2(FabricaAbstrataKit):
    def criar_computador(self) -> ComputadorAbstrato:
        return ComputadorModeloB()

    def criar_teclado(self) -> TecladoAbstrato:
        return TecladoModeloB()
