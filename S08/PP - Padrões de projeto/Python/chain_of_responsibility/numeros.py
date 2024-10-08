class Numeros:
    def __init__(self, numero_1: int, numero_2: int, calculo_desejado: str):
        self._numero_1: int = numero_1
        self._numero_2: int = numero_2
        self._calculo_desejado: str = calculo_desejado

    @property
    def numero_1(self) -> int:
        return self._numero_1

    @property
    def numero_2(self) -> int:
        return self._numero_2

    @property
    def calculo_desejado(self) -> str:
        return self._calculo_desejado
