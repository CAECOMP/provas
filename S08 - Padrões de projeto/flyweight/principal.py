from typing import Dict
from fabrica import FabricaFlyweight


def adicionando_carro_ao_banco_de_dados_da_policia(
    fabrica: FabricaFlyweight, placa: str, nome_do_dono: str,
    marca: str, modelo: str, cor: str
) -> None:
    print("\n\nCliente: Adicionando carro...")
    flyweight = fabrica.obter_flyweight([marca, modelo, cor])
    flyweight.operacao([placa, nome_do_dono])


if __name__ == "__main__":
    """
    The client code usually creates a bunch of pre-populated flyweights in the
    initialization stage of the application.
    """

    fabrica = FabricaFlyweight([
        ["Chevrolet", "Camaro2018", "pink"],
        ["Mercedes Benz", "C300", "black"],
        ["Mercedes Benz", "C500", "red"],
        ["BMW", "M5", "red"],
        ["BMW", "X6", "white"],
    ])

    fabrica.listar_flyweights()

    adicionando_carro_ao_banco_de_dados_da_policia(
        fabrica, "CL234IR", "James Doe", "BMW", "M5", "red")

    adicionando_carro_ao_banco_de_dados_da_policia(
        fabrica, "CL234IR", "James Doe", "BMW", "X1", "red")

    print("\n")

    fabrica.listar_flyweights()
