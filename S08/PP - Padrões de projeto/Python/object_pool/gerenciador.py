from reutilizavel import Reutilizavel


class Gerenciador:
    """
    Gerenciar objetos Reutilizáveis para uso por objetos Cliente.
    """

    def __init__(self, size):
        print(f"Instanciando gerenciador com {size} objetos que os clientes podem reutilizar")
        self.__objetos_reutilizaveis = [Reutilizavel() for _ in range(size)]

    def adquirir(self):
        print("Adquirindo um obejto reutilizável")
        return self.__objetos_reutilizaveis.pop()

    def adicionar(self, objeto_para_reutilizar: Reutilizavel):
        print("Adicionando um objeto reutilizável ao gerenciador")
        self.__objetos_reutilizaveis.append(objeto_para_reutilizar)

