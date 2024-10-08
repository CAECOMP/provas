from abc import ABC, abstractmethod
from excecoes import *


class ComponenteCancao(ABC):
    @abstractmethod
    def adicionar(self, cancao) -> None:
        raise OperacaoDeAdicaoInvalida("Operação não supoerta: Não é possível adicionar uma nova canção")

    @abstractmethod
    def remover(self, cancao) -> None:
        raise OperacaoDeRemocaoInvalida("Operação não supoerta: Não é possível remove essa canção")

    @abstractmethod
    def obter_componente(self, indice: int) -> "ComponenteCancao":
        raise OperacaoNaoSuportada("Operação não supoerta: Não é possível obter um componente")

    @abstractmethod
    def obter_nome_cancao(self) -> None:
        raise OperacaoNaoSuportada("Operação não supoerta: Não é possível obter o nome dessa canção")

    @abstractmethod
    def obter_nome_da_banda(self) -> None:
        raise OperacaoNaoSuportada("Operação não supoerta: Não é possível obter o nome da banda")

    @abstractmethod
    def obter_ano_de_lancaomento(self) -> None:
        raise OperacaoNaoSuportada("Operação não supoerta: Não é possível obter o ano de lançamento")

    @abstractmethod
    def mostrar_informacoes_da_cancao(self) -> None:
        raise OperacaoNaoSuportada("Operação não supoerta: Não é possível obter as informações da canção")
