from gerenciador import Gerenciador
from reutilizavel import Reutilizavel
from time import sleep


if __name__ == "__main__":
    gerenciador: Gerenciador = Gerenciador(10)
    sleep(5)

    print("Cliente requisitando um objeto disponível no gerenciador...")
    objeto_reusavel: Reutilizavel = gerenciador.adquirir()
    print("Cliente está usando o objeto reutilizável...")
    sleep(5)

    print("Terminou de usar. Devolvendo ao gerenciador...")
    gerenciador.adicionar(objeto_reusavel)
