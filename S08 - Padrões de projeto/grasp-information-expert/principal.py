from venda import Venda
from item_vendido import ItemVendido
from produto import Produto


if __name__ == '__main__':
    leite_condensado: Produto = Produto(nome="leite moça", valor_unitario=6.50)
    nescau: Produto = Produto(nome="nescau 150ml", valor_unitario=1.50)

    venda: Venda = Venda()
    venda.adicionar_item_na_compra(ItemVendido(produto=leite_condensado, quantidade_unidades_compradas=2))
    venda.adicionar_item_na_compra(ItemVendido(produto=nescau, quantidade_unidades_compradas=10))

    valor_final = venda.calcular_valor_total_da_venda()

    print(f"o valor total da compra foi: {valor_final}")
