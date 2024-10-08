from frete_servico import FreteServico


class Sedex(FreteServico):
    def calcula(self, peso: float) -> float:
        return peso * 10.0 + 10.0

