from componente_cancao import ComponenteCancao
from typing import List
from collections.abc import Iterator


class GrupoCancao(ComponenteCancao):
    def __init__(self, nome: str, descricao: str):
        self._nome: str = nome
        self._descricao: str = descricao
        self.elementos: List["GrupoCancao", ComponenteCancao] = []

    @property
    def nome(self):
        return self._nome

    @property
    def descricao(self):
        return self._descricao

    def adicionar(self, cancao: ComponenteCancao) -> None:
        self.elementos.append(cancao)

    def remover(self, cancao: ComponenteCancao) -> None:
        self.elementos.remove(cancao)

    def obter_componente(self, indice: int) -> ComponenteCancao:
        return self.elementos.__getitem__(indice)

    def obter_nome_cancao(self) -> None:
        super(GrupoCancao, self).obter_nome_cancao()

    def obter_nome_da_banda(self) -> None:
        super(GrupoCancao, self).obter_nome_da_banda()

    def obter_ano_de_lancaomento(self) -> None:
        super(GrupoCancao, self).obter_ano_de_lancaomento()

    def mostrar_informacoes_da_cancao(self) -> None:
        print(f"\nnome do grupo: {self.nome}"
              f"\ndescricao: {self.descricao}")

        for elemento in self.elementos:
            elemento.mostrar_informacoes_da_cancao()


