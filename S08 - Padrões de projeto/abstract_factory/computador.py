from abc import ABC, abstractmethod
from teclado import TecladoAbstrato


class ComputadorAbstrato(ABC):
    @abstractmethod
    def detalhes_do_hardware(self) -> str:
        pass


class ComputadorModeloA(ComputadorAbstrato):
    def detalhes_do_hardware(self) -> str:
        return "Processador Core 2 + 8G Memória RAM + 1Tb de ssd"


class ComputadorModeloB(ComputadorAbstrato):
    def detalhes_do_hardware(self) -> str:
        return "Processador Core 8 + 16G Memória RAM + 2Tb de ssd"
