from abc import ABC, abstractmethod


class DispositivoEletronico(ABC):
    @abstractmethod
    def ligar(self):
        pass

    @abstractmethod
    def desligar(self):
        pass

    @abstractmethod
    def aumentar_volume(self):
        pass

    @abstractmethod
    def diminuir_volume(self):
        pass


