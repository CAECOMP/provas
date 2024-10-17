from observer_interface import Observador
from subject_interface import Assunto


class ObservadorAcoes(Observador):
    def __init__(self, identificador: int, assunto: Assunto):
        self.__preco_ibm: float = 100.0
        self.__preco_apple: float = 100.0
        self.__preco_google: float = 100.0
        self.__identificador: int = identificador
        self.__assunto: Assunto = assunto

        print(f"Novo observador id -> {self.__identificador}")
        self.__assunto.registrar_novo_observador(novo_observador=self)

    def atualizar(
        self, preco_ibm: float, preco_apple: float, preco_google: float
    ) -> None:
        self.__preco_ibm: float = preco_ibm
        self.__preco_apple: float = preco_apple
        self.__preco_google: float = preco_google

        print(f"id do observador: {self.__identificador}")
        self.printar_valores_atuais()

    @property
    def preco_ibm(self) -> float:
        return self.__preco_ibm

    @property
    def preco_apple(self) -> float:
        return self.__preco_apple

    @property
    def preco_google(self) -> float:
        return self.__preco_google

    def printar_valores_atuais(self) -> None:
        print(f"ibm: {self.__preco_ibm}")
        print(f"apple: {self.__preco_apple}")
        print(f"google: {self.__preco_google}")
