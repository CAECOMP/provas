from conversor import Conversor


class Conta:
    def __init__(self):
        self.__valor_total = 100.0

    @property
    def saldo(self) -> float:
        return self.__valor_total

    @saldo.setter
    def saldo(self, novo_valor: float):
        self.__valor_total = novo_valor

    def obter_saldo_convertido(self, conversao: Conversor) -> float:
        return conversao.converter(valor=self.__valor_total)
