from produto import Produto


class ItemVendido:
    def __init__(self, produto: Produto, quantidade_unidades_compradas: int):
        self.__produto: Produto = produto
        self.__quantidade_unidades_compradas: int = quantidade_unidades_compradas

    def calcular_valor_total_do_item(self) -> float:
        return self.__quantidade_unidades_compradas * self.__produto.valor_unitario
