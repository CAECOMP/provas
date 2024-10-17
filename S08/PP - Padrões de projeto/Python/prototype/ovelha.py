from animal import Animal
from copy import copy, deepcopy


class Ovelha(Animal):
    def __init__(self):
        self._tamanho = 10.0
        print("ovelha criada bééééééé")

    def __str__(self):
        return f"tamanho: {self._tamanho}"

    @property
    def tamanho(self) -> str:
        return str(self._tamanho)

    @tamanho.setter
    def tamanho(self, novo_tamanho: float):
        self._tamanho = novo_tamanho

    def clonar(self):
        print("clonei a ovelha")
        return copy(self)
