from abc import ABC, abstractmethod
from numeros import Numeros


class Cadeia(ABC):
    @abstractmethod
    def definir_proximo_na_cadeia(self, proxima_cadeia: "Cadeia"):
        pass

    @abstractmethod
    def calcular(self, requisicao: Numeros):
        pass