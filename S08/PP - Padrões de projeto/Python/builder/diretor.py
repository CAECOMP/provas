from interface_robo import InterfaceRobo
from interface_construtor_robo import InterfaceConstrutorRobo
from robo import Robo


class Diretor:
    _construtor: InterfaceConstrutorRobo

    def __init__(self, construtor_de_robo: InterfaceConstrutorRobo):
        self.definir_construtor(construtor_de_robo)

    def definir_construtor(self, construtor_de_robo: InterfaceConstrutorRobo):
        self._construtor = construtor_de_robo

    def criar_robo(self) -> Robo:
        self._construtor.criar_cabeca_robo()
        self._construtor.criar_tronco_robo()
        self._construtor.criar_bracos_robo()
        self._construtor.criar_pernas_robo()

    def retornar_robo_criado(self) -> Robo:
        return self._construtor.retornar_robo_criado()

