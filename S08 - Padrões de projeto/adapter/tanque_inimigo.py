from interface_atacante_inimigo import AtacanteInimigo
from random import randint


class TanqueInimigo(AtacanteInimigo):
    def __init__(self):
        self.dano: int = 0
        self.movimento: int = 0

    def atirar(self) -> None:
        self.dano: int = randint(1, 10)
        print(f"O tanque causa {self.dano} de dano")

    def seguir_em_frente(self) -> None:
        self.movimento = randint(1, 5)
        print(f"O tanque se moveu {self.movimento} casas")

    def atribuir_motorista(self, nome_motorista: str) -> None:
        print(f"{nome_motorista} está dirigindo o tanque")
