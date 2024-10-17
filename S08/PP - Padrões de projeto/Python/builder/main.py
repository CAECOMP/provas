from construtor_robo_antigo import ConstrutorRoboAntigo
from construtor_robo_moderno import ConstrutorRoboModerno
from diretor import Diretor


if __name__ == "__main__":
    construtor = ConstrutorRoboAntigo()
    diretor = Diretor(construtor_de_robo=construtor)
    diretor.criar_robo()
    robo_criado = diretor.retornar_robo_criado()

    print("Robo antigo criado:")
    print(robo_criado)

    construtor = ConstrutorRoboModerno()
    diretor.definir_construtor(construtor)
    diretor.criar_robo()
    robo_criado = diretor.retornar_robo_criado()

    print("\nRobo moderno criado:")
    print(robo_criado)



    
