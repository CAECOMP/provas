from pizza import Pizza
from molho_de_tomate import MolhoDeTomate
from mussarela import Mussarela
from pizza_simples import PizzaSimples


if __name__ == '__main__':
    minha_pizza: Pizza = MolhoDeTomate(Mussarela(PizzaSimples()))
    print(f"ingredientes: {minha_pizza.pegar_descricao()}")
    print(f"valor: {minha_pizza.pegar_valor()}")

