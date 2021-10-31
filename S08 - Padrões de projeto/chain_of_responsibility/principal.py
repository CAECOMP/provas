from somar_numeros import AdicionarNumeros
from subtrair_numeros import SubtrairNumeros
from multiplicar_numeros import MultiplicarNumeros
from dividir_numeros import DividirNumeros
from interface_cadeia import Cadeia
from numeros import Numeros


if __name__ == '__main__':
    cadeia_1: Cadeia = AdicionarNumeros()
    cadeia_2: Cadeia = SubtrairNumeros()
    cadeia_3: Cadeia = MultiplicarNumeros()
    cadeia_4: Cadeia = DividirNumeros()

    cadeia_1.definir_proximo_na_cadeia(proxima_cadeia=cadeia_2)
    cadeia_2.definir_proximo_na_cadeia(proxima_cadeia=cadeia_3)
    cadeia_3.definir_proximo_na_cadeia(proxima_cadeia=cadeia_4)

    print("operação de soma")
    requisicao: Numeros = Numeros(numero_1=20, numero_2=10, calculo_desejado="somar")
    cadeia_1.calcular(requisicao=requisicao)

    print("\noperação de subtração")
    requisicao: Numeros = Numeros(numero_1=20, numero_2=10, calculo_desejado="subtrair")
    cadeia_1.calcular(requisicao=requisicao)

    print("\noperação de multiplicação")
    requisicao: Numeros = Numeros(numero_1=20, numero_2=10, calculo_desejado="multiplicar")
    cadeia_1.calcular(requisicao=requisicao)

    print("\noperação de divisão")
    requisicao: Numeros = Numeros(numero_1=20, numero_2=10, calculo_desejado="dividir")
    cadeia_1.calcular(requisicao=requisicao)

    print("\noperação que não existe na cadeia -> raiz quadrada")
    requisicao: Numeros = Numeros(numero_1=20, numero_2=10, calculo_desejado="raiz quadrada")
    cadeia_1.calcular(requisicao=requisicao)
