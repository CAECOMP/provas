from interface_atacante_inimigo import AtacanteInimigo
from robo_inimigo import RoboInimigo


class AdaptadorRoboInimigo(AtacanteInimigo):
    def __init__(self, robo: RoboInimigo):
        self.robo: RoboInimigo = robo

    def atirar(self) -> None:
        self.robo.esmagar_com_as_maos()

    def seguir_em_frente(self) -> None:
        self.robo.ande_para_frente()

    def atribuir_motorista(self, nome_motorista: str) -> None:
        self.robo.reagir_ao_humano(nome_motorista=nome_motorista)
