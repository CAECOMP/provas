from sedex import Sedex
from tnt import Tnt
from frete_servico import FreteServico

class Frete:
    def __init__(self, empresa_que_fara_o_frete: FreteServico):
        self._empresa = empresa_que_fara_o_frete

    @property
    def empresa(self):
        return self._empresa

    @empresa.setter
    def empresa(self, empresa: FreteServico):
        self._empresa = empresa

    def calcular_valor(self, peso: float) -> float:
        return self._empresa.calcula(peso)


if __name__ == "__main__":
    frete = Frete(empresa_que_fara_o_frete=Sedex())
    resultado = frete.calcular_valor(10)
    print(resultado)

    frete.empresa = Tnt()
    resultado = frete.calcular_valor(10)
    print(resultado)
