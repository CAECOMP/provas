from navio_inimigo_foguete import NavioInimigoFoguete
from navio_inimigo_ufo import NavioInimigoUFO
from navio_inimigo import NavioInimigo

from fabrica_de_navios import FabricaDeNavios

from typing import Optional


def ataque_inimigo(navio: Optional[NavioInimigo]):
    if navio:
        navio.exibir_navio_inimigo_na_tela()
        navio.seguir_navio_do_heroi()
        navio.atirar()
    else:
        print("Digite U ou R ou B na próxima vez ;)")


if __name__ == "__main__":
    tipo_navio_inimigo = input(
        "Qual tipo de navio inimigo você quer criar? (digite U / R / B) -> "
    ).upper()
    fabrica = FabricaDeNavios(tipo_navio_inimigo)

    ataque_inimigo(fabrica.retornar_navio_fabricado())
