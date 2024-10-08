from componente_cancao import ComponenteCancao


class TocadorDeDiscos:
    def __init__(self, lista_de_cancoes: ComponenteCancao):
        self._lista_de_cancoes: ComponenteCancao = lista_de_cancoes

    def obter_lista_de_cancoes(self):
        self._lista_de_cancoes.mostrar_informacoes_da_cancao()
