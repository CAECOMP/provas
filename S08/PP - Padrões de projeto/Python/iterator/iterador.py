from collections.abc import Iterator
from typing import List


class IteradorDoCardapio(Iterator):

    _posicao: int = None
    _percorrer_reversamente: bool = False

    def __init__(self, items_do_cardapio: List[str], percorrer_reversamente: bool = False) -> None:
        self._items_do_cardapio = items_do_cardapio
        self._percorrer_reversamente = percorrer_reversamente
        self._posicao = 0
        if percorrer_reversamente:
            self._posicao = -1

    def __next__(self):
        try:
            valor = self._items_do_cardapio[self._posicao]

            indice_a_ser_somado = 1
            if self._percorrer_reversamente:
                indice_a_ser_somado = -1

            self._posicao += indice_a_ser_somado
        except IndexError:
            raise StopIteration()

        return valor
