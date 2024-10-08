from abc import ABC, abstractmethod


class Comando(ABC):
    @abstractmethod
    def executar(self):
        pass
