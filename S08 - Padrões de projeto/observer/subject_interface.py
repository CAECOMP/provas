import abc
from observer_interface import Observador


class Assunto(metaclass=abc.ABCMeta):
    @abc.abstractmethod
    def registrar_novo_observador(self, novo_observador: Observador) -> None:
        pass

    @abc.abstractmethod
    def cancelar_registro_de_um_observador(self, observador: Observador) -> None:
        pass

    @abc.abstractmethod
    def notificar_observadores(self) -> None:
        pass
