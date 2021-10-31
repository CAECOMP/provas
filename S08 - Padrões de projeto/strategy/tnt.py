from frete_servico import FreteServico


class Tnt(FreteServico):
    def calcula(self, peso: float) -> float:
        return peso * 5.0 + 10.0
