from conversor import Conversor


class ConversorDolar(Conversor):
    def converter(self, valor: float) -> float:
        return valor * 5.5
