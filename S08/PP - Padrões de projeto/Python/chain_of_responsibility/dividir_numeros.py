from interface_cadeia import Cadeia
from numeros import Numeros


class DividirNumeros(Cadeia):
    def __init__(self):
        self._proximo_na_cadeia: Cadeia = None

    def definir_proximo_na_cadeia(self, proxima_cadeia: Cadeia):
        self._proximo_na_cadeia = proxima_cadeia

    def calcular(self, requisicao: Numeros):
        if requisicao.calculo_desejado == "dividir":
            print(f"{requisicao.numero_1} / {requisicao.numero_2} = {requisicao.numero_1 / requisicao.numero_2}")
        else:
            print("As operações disponíveis até o momento são somar, subtrair, multiplicar e dividir")

