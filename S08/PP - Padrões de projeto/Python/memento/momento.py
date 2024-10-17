class Momento:
    def __init__(self, artigo_para_salvar: str):
        self.__artigo: str = artigo_para_salvar

    def obter_artigo_salvo(self) -> str:
        return self.__artigo
