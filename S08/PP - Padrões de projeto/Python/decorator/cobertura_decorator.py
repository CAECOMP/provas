from abc import ABC
from pizza import Pizza


class CoberturaDecorator(Pizza, ABC):
    def __init__(self, pizza: Pizza):
        self._pizza = pizza

    def pegar_descricao(self) -> str:
        return self._pizza.pegar_descricao()

    def pegar_valor(self) -> float:
        return self._pizza.pegar_valor()
