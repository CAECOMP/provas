from produto import Produto


class PedidoItem:
    def __init__(self, produto: Produto):
        self.__nome: str = produto.nome
        self.__preco_unitario: float = produto.valor_unitario
        self.__quantidade_unidades_compradas: int = 2

    def calcular_valor_total_do_item(self) -> float:
        return self.__quantidade_unidades_compradas * self.__preco_unitario
