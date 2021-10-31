import abc


class Observador(metaclass=abc.ABCMeta):
    @abc.abstractmethod
    def atualizar(
        self, preco_ibm: float, preco_apple: float, preco_google: float
    ) -> None:
        pass
