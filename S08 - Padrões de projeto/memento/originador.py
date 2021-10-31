from momento import Momento


class Originador:
    def __init__(self):
        self.__artigo = ""

    def modificar_artigo(self, novo_artigo: str):
        print(f"Do originador: versão atual do artigo\n{self.__artigo}")
        self.__artigo = novo_artigo

    def salvar_momento(self) -> Momento:
        print(f"Do originador: salvando estado atual no momento")
        return Momento(artigo_para_salvar=self.__artigo)

    @staticmethod
    def restaurar_versao_do_momento(momento: Momento) -> str:
        artigo = momento.obter_artigo_salvo()
        print(f"Do originador: versão anteriormente salva no momento: {artigo}")

        return artigo

    pass
