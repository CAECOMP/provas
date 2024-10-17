from random import randint


class RoboInimigo:
    def __init__(self):
        self.dano = 0
        self.movimento = 0

    def esmagar_com_as_maos(self):
        self.dano = randint(1, 10)
        print(f"O robô iminigo causa {self.dano} de dano com suas mãos")

    def ande_para_frente(self):
        self.movimento = randint(1, 5)
        print(f"O robô iminigo anda {self.movimento} casas para frente")

    def reagir_ao_humano(self, nome_motorista):
        print(f"O robô inimigo vai para cima do {nome_motorista}")
