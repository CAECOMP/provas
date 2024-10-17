"""
class Pedido {

    private List itens;

    public void criarNovoPedidoItem(Produto produto) {
        //Criamos a instancia de pedido item
        PedidoItem pedidoItem = new PedidoItem(produto);
        this.itens.add(pedidoItem);
    }
}

class Produto {

    private String nome;
    private String preco;

}

class PedidoItem {

    private String nome;
    private String precoUnitario;
    private int quantidade;

    public PedidoItem(Produto produto){
        this.nome = produto.getNome();
        this.precoUnitario = produto.getPreco();
        this.quantidade = 1;
    }

}
"""
from produto import Produto
from pedido import Pedido


if __name__ == '__main__':
    pedido: Pedido = Pedido()

    leite_condensado: Produto = Produto(nome="leite moça", valor_unitario=6.50)
    nescau: Produto = Produto(nome="nescau 150ml", valor_unitario=1.50)

    pedido.adicionar_item_na_compra(leite_condensado)
    pedido.adicionar_item_na_compra(nescau)

    valor_final = pedido.calcular_valor_total_da_venda()

    print(f"o valor total da compra foi: {valor_final}")
