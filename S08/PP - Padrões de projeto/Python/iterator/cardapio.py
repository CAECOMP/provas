from collections.abc import Iterable
from iterador import IteradorDoCardapio


class Cardapio(Iterable):

    def __init__(self, cardapio_inicial=None) -> None:
        if cardapio_inicial is None:
            cardapio_inicial = []

        self._items_do_cardapio = cardapio_inicial

    def __iter__(self) -> IteradorDoCardapio:
        return IteradorDoCardapio(self._items_do_cardapio)

    def get_reverse_iterator(self) -> IteradorDoCardapio:
        return IteradorDoCardapio(items_do_cardapio=self._items_do_cardapio, percorrer_reversamente=True)

    def adicionar_novo_item(self, item: str):
        self._items_do_cardapio.append(item)