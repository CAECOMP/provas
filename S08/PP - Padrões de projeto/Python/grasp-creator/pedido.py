from typing import List
from pedido_item import PedidoItem
from produto import Produto


class Pedido:
    def __init__(self):
        self.__items: List[PedidoItem] = []

    def adicionar_item_na_compra(self, produto: Produto):
        item: PedidoItem = PedidoItem(produto=produto)
        self.__items.append(item)

    def calcular_valor_total_da_venda(self) -> float:
        valor_total: float = 0.0
        for item in self.__items:
            valor_total += item.calcular_valor_total_do_item()

        return valor_total
