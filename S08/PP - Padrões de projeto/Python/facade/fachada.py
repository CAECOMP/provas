from numero_conta import NumeroContaDoBanco
from codigo_seguranca import CodigoSeguranca
from fundos import Fundos
from banco_boas_vindas import BancoBoasVindas


class ContaBancoFachada:
    def __init__(self, novo_numero_conta: int, novo_codigo_segunranca: int):
        self.numero_da_conta = novo_numero_conta
        self.codigo_seguranca = novo_codigo_segunranca

        self.banco = BancoBoasVindas()
        self.checagem_numero_conta = NumeroContaDoBanco()
        self.checagem_codigo_seguranca = CodigoSeguranca()
        self.checagem_fundos = Fundos()

    def retirar_dinheiro(self, valor: float):
        if (
            self.checagem_numero_conta.validar_numero_conta(self.numero_da_conta)
            and self.checagem_codigo_seguranca.validar_codigo_seguranca(
                self.codigo_seguranca
            )
            and self.checagem_fundos.tem_dinheiro_suficiente(valor)
        ):
            print("Transação completada!!!")
        else:
            print("Transação falhou!!!")

    def depositar_dinheiro(self, valor: float):
        if self.checagem_numero_conta.validar_numero_conta(
            self.numero_da_conta
        ) and self.checagem_codigo_seguranca.validar_codigo_seguranca(
            self.codigo_seguranca
        ):
            self.checagem_fundos.fazer_deposito(valor)
            print("Transação completada!!!")
        else:
            print("Transação falhou!!!")
