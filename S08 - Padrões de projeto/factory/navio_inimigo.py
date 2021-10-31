class NavioInimigo:
    def __init__(self, nome: str, quantidade_de_dano: float):
        self.__nome: str = nome
        self.__quantidade_de_dano: float = quantidade_de_dano

    @property
    def nome(self) -> str:
        return self.__nome

    @nome.setter
    def nome(self, novo_nome: str) -> None:
        self.__nome = novo_nome

    @property
    def quantidade_de_dano(self) -> float:
        return self.__quantidade_de_dano

    @quantidade_de_dano.setter
    def quantidade_de_dano(self, nova_quantidade_de_dano: float) -> None:
        self.__quantidade_de_dano = nova_quantidade_de_dano

    def seguir_navio_do_heroi(self) -> None:
        print(f"{self.__nome} está seguindo o herói")

    def exibir_navio_inimigo_na_tela(self) -> None:
        print(f"{self.__nome} está na tela")

    def atirar(self) -> None:
        print(
            f"{self.__nome} está atacando e causando {self.__quantidade_de_dano} de dano"
        )
