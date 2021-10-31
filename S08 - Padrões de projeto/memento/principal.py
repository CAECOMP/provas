from originador import Originador
from zelador import Zelador


if __name__ == '__main__':
    zelador: Zelador = Zelador()
    origem: Originador = Originador()
    quantidade_de_arquivos_salvos: int = 0

    for _ in range(3):
        artigo: str = input("Digite algo no artigo e aperte ENTER: ")
        origem.modificar_artigo(artigo)
        zelador.adicionar_versao(origem.salvar_momento())
        quantidade_de_arquivos_salvos += 1
        print(f"versão salva: {quantidade_de_arquivos_salvos}\n")

    print("\n========================================================")
    artigo_restaurado: str = origem.restaurar_versao_do_momento(
        zelador.obter_versao(indice=2)
    )
    print(f"versão recuperada número 3: {artigo_restaurado}")

    print("\n========================================================")
    artigo_restaurado: str = origem.restaurar_versao_do_momento(
        zelador.obter_versao(indice=1)
    )
    print(f"versão recuperada número 2: {artigo_restaurado}")

    print("\n========================================================")
    artigo_restaurado: str = origem.restaurar_versao_do_momento(
        zelador.obter_versao(indice=0)
    )
    print(f"versão recuperada número 1: {artigo_restaurado}")
