from tanque_inimigo import TanqueInimigo
from robo_inimigo import RoboInimigo
from adaptador_robo_inimigo import AdaptadorRoboInimigo


if __name__ == "__main__":
    tanque_rx7: TanqueInimigo = TanqueInimigo()
    fred: RoboInimigo = RoboInimigo()
    adaptador: AdaptadorRoboInimigo = AdaptadorRoboInimigo(fred)

    print("O robô...")
    fred.reagir_ao_humano("Paul")
    fred.ande_para_frente()
    fred.esmagar_com_as_maos()

    print("\nO tanque inimigo...")
    tanque_rx7.atribuir_motorista("Frank")
    tanque_rx7.seguir_em_frente()
    tanque_rx7.atirar()

    print("\nO robô com o adaptador...")
    adaptador.atribuir_motorista("Mark")
    adaptador.seguir_em_frente()
    adaptador.atirar()
