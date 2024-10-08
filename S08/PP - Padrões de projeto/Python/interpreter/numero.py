from operador import Operador


class Numero(Operador):
    def __init__(self, valor: int):
        self._valor: int = valor

    def interpretar(self) -> int:
        return self._valor
