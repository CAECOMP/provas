from operador import Operador
from numero import Numero
from soma import Somar
from subtracao import Subtrair
from multiplicacao import Multiplicar
from divisao import Dividir


if __name__ == '__main__':
    somar: Operador = Somar(Numero(1), Numero(4))
    # 1 + 4 = 5
    print(f"resultado da soma: {somar.interpretar()}")

    # 5 - 2 = 3
    subtrair: Operador = Subtrair(somar, Numero(2))
    print(f"resultado da subtração: {subtrair.interpretar()}")

    # 5 * 3 = 15
    multiplicar: Operador = Multiplicar(subtrair, somar)
    print(f"resultado da multiplicação: {multiplicar.interpretar()}")

    # 30 / 15 = 2
    dividir: Operador = Dividir(Numero(30), multiplicar)
    print(f"resultado da divisão: {dividir.interpretar()}")
