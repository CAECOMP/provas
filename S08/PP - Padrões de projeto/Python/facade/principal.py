from fachada import ContaBancoFachada

if __name__ == "__main__":
    conta = ContaBancoFachada(novo_numero_conta=123456, novo_codigo_segunranca=1234)
    conta.retirar_dinheiro(50.0)
    conta.retirar_dinheiro(900.0)
    conta.retirar_dinheiro(900.0)
    conta.depositar_dinheiro(200)
