class Produto:
    def __init__(self, nome: str, valor_unitario: float):
        self.__nome: str = nome
        self.__valor_unitario: float = valor_unitario

    @property
    def valor_unitario(self) -> float:
        return self.__valor_unitario

    @property
    def nome(self) -> str:
        return self.__nome
