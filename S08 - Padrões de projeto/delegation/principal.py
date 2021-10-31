from conta import Conta
from conversor import Conversor
from conversor_para_dolar import ConversorDolar


if __name__ == '__main__':
    conta: Conta = Conta()
    conta.saldo = 10.0

    conversor: Conversor = ConversorDolar()
    print(f"saldo normal: {conta.saldo}")

    valor_convertido = conversor.converter(valor=conta.saldo)
    print(f"saldo em dolar: {valor_convertido}")
