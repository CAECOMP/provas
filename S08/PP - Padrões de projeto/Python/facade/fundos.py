class Fundos:
    def __init__(self):
        self.dinheiro_em_conta = 1000.0

    def retirar_dinheiro_da_conta(self, valor: float):
        self.dinheiro_em_conta -= valor

    def depositar_dinheiro_na_conta(self, valor: float):
        self.dinheiro_em_conta += valor

    def tem_dinheiro_suficiente(self, valor_para_retirar: float) -> float:
        if valor_para_retirar > self.dinheiro_em_conta:
            print("Erro: Você não tem dinheiro o suficiente")
            print(f"Valor atual em conta: {self.dinheiro_em_conta}")
            return False
        else:
            self.retirar_dinheiro_da_conta(valor=valor_para_retirar)
            print(
                f"Retirada finalizada com sucesso. Novo saldo: {self.dinheiro_em_conta}"
            )
            return True

    def fazer_deposito(self, valor_a_depositar: float):
        self.depositar_dinheiro_na_conta(valor=valor_a_depositar)
        print(f"Depósito concluído com sucesso. Novo saldo: {self.dinheiro_em_conta}")
