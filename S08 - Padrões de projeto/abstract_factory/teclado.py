from abc import ABC, abstractmethod


class TecladoAbstrato(ABC):
    @abstractmethod
    def detalhes(self) -> str:
        pass


class TecladoModeloA(TecladoAbstrato):
    def detalhes(self) -> str:
        return "Teclado de membrana"


class TecladoModeloB(TecladoAbstrato):
    def detalhes(self) -> str:
        return "Teclado mecânico"
