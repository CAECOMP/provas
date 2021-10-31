from interface_construtor_robo import InterfaceConstrutorRobo
from robo import Robo


class ConstrutorRoboModerno(InterfaceConstrutorRobo):
    _robo: Robo

    def __init__(self):
        self.resetar()

    def criar_cabeca_robo(self) -> None:
        self._robo.criar_cabeca("cabeça de fibra de carbono")

    def criar_tronco_robo(self) -> None:
        self._robo.criar_troco("tronco de fibra de carbono")
    
    def criar_bracos_robo(self) -> None:
        self._robo.criar_bracos("braços de fibra de carbono")
    
    def criar_pernas_robo(self) -> None:
        self._robo.criar_pernas("pernas de fibra de carbono")

    def resetar(self) -> None:
        self._robo = Robo()
    
    def retornar_robo_criado(self) -> Robo:
        robo_pronto = self._robo
        self.resetar()
        return robo_pronto