from navio_inimigo import NavioInimigo
from navio_inimigo_ufo import NavioInimigoUFO
from navio_inimigo_foguete import NavioInimigoFoguete
from grande_navio_inimigo_ufo import GrandeNavioInimigoUFO


class FabricaDeNavios:
    def __init__(self, tipo_navio_inimigo: str):
        self.navio = None
        if tipo_navio_inimigo == "U":
            self.navio = NavioInimigoUFO()
        elif tipo_navio_inimigo == "R":
            self.navio = NavioInimigoFoguete()
        elif tipo_navio_inimigo == "B":
            self.navio = GrandeNavioInimigoUFO()

        self.retornar_navio_fabricado

    def retornar_navio_fabricado(self) -> NavioInimigo:
        return self.navio
