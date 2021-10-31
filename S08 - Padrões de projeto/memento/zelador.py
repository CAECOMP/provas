from typing import List
from momento import Momento


class Zelador:
    def __init__(self):
        self.__artigos_salvos: List[Momento] = []

    def adicionar_versao(self, versao: Momento) -> None:
        self.__artigos_salvos.append(versao)

    def obter_versao(self, indice: int) -> Momento:
        return self.__artigos_salvos.__getitem__(indice)

    pass
