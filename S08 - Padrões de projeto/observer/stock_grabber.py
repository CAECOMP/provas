from subject_interface import Assunto
from observer_interface import Observador
from typing import List


class AdministradorAcoes(Assunto):
    def __init__(self):
        self.__observadores: List[Observador] = []
        self.__preco_ibm: float = 0.0
        self.__preco_apple: float = 0.0
        self.__preco_google: float = 0.0

    def registrar_novo_observador(self, novo_observador: Observador) -> None:
        self.__observadores.append(novo_observador)
        print("observador adicionado")

    def cancelar_registro_de_um_observador(self, observador: Observador) -> None:
        self.__observadores.remove(observador)
        print("observador removido")

    def notificar_observadores(self) -> None:
        print("atualizando os valores dos observadores")
        for observador in self.__observadores:
            observador.atualizar(
                preco_ibm=self.__preco_ibm,
                preco_apple=self.__preco_apple,
                preco_google=self.__preco_google,
            )

    @property
    def preco_ibm(self) -> float:
        return self.__preco_ibm

    @property
    def preco_apple(self) -> float:
        return self.__preco_apple

    @property
    def preco_google(self) -> float:
        return self.__preco_google

    @preco_ibm.setter
    def preco_ibm(self, novo_valor: float) -> None:
        self.__preco_ibm = novo_valor
        self.notificar_observadores()

    @preco_apple.setter
    def preco_apple(self, novo_valor: float) -> None:
        self.__preco_apple = novo_valor
        self.notificar_observadores()

    @preco_google.setter
    def preco_google(self, novo_valor: float) -> None:
        self.__preco_google = novo_valor
        self.notificar_observadores()
