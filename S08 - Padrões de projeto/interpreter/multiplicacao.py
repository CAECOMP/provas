from operador import Operador


class Multiplicar(Operador):
    def __init__(self, esquerda: Operador, direita: Operador):
        self._esquerda: Operador = esquerda
        self._direita: Operador = direita

    def interpretar(self) -> int:
        return self._esquerda.interpretar() * self._direita.interpretar()
