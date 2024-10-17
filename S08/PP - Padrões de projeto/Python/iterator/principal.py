from cardapio import Cardapio


if __name__ == "__main__":

    cardapio = Cardapio()
    cardapio.adicionar_novo_item("Tilápia")
    cardapio.adicionar_novo_item("Carne do Sol")
    cardapio.adicionar_novo_item("Macaxeira")

    print("Percorrendo na ordem normal:")
    print("\n".join(cardapio))
    print("")

    print("Percorrendo inversamente:")
    print("\n".join(cardapio.get_reverse_iterator()), end="")
