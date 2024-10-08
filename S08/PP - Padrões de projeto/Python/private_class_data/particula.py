from velocidade import Velocidade
from math import pow


class Particula:
    def __init__(self, valor_velocidade: float, massa: float):
        self.__velocidade: Velocidade = Velocidade(valor_velocidade)
        self.__massa: float = massa

    def calcular_energia_cinetica(self):
        resultado = self.__massa * pow(self.__velocidade.obter_valor(), 2)
        resultado = resultado / 2

        return resultado
