from componente_cancao import ComponenteCancao
from grupo_cancao import GrupoCancao
from cancao import Cancao
from tocador_de_disco import TocadorDeDiscos


if __name__ == '__main__':
    industrial: ComponenteCancao = GrupoCancao(nome="\nindustrial", descricao="vai 1")
    heavy_metal: ComponenteCancao = GrupoCancao(nome="\nheavy metal", descricao="vai 2")
    pisadinha: ComponenteCancao = GrupoCancao(nome="\npisadinha", descricao="vai 3")

    tudo: ComponenteCancao = GrupoCancao(nome="grupo de músicas", descricao="todas as músicas disponíveis")
    tudo.adicionar(industrial)
    industrial.adicionar(Cancao(nome="Head Like a Hole", nome_da_banda="NIN", ano_de_lancamento=1990))
    industrial.adicionar(Cancao(nome="Head Hunter", nome_da_banda="Front 242", ano_de_lancamento=1988))

    industrial.adicionar(pisadinha)
    pisadinha.adicionar(
        Cancao(
            nome="Basta Você Me Ligar (part. Xand Avião)",
            nome_da_banda="Os Barões da Pisadinha",
            ano_de_lancamento=2020
        )
    )

    tudo.adicionar(heavy_metal)
    heavy_metal.adicionar(Cancao(nome="To Tame a Land", nome_da_banda="Iron Maiden", ano_de_lancamento=1983))

    tocador: TocadorDeDiscos = TocadorDeDiscos(lista_de_cancoes=tudo)
    tocador.obter_lista_de_cancoes()
