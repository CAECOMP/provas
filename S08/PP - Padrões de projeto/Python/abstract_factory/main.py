from fabrica import FabricaAbstrataKit, Kit1, Kit2


def kit_do_cliente(kit: FabricaAbstrataKit) -> None:

    computador = kit.criar_computador()
    teclado = kit.criar_teclado()

    print(f"{computador.detalhes_do_hardware()}")
    print(f"{teclado.detalhes()}")


if __name__ == "__main__":
    print("Testando o primeiro tipo de factory")
    print("Detalhes do kit 1")
    kit_do_cliente(Kit1())

    print("\n")

    print("Mesmo cliente só que estando o segundo tipo de factory")
    print("Detalhes do kit 2")
    kit_do_cliente(Kit2())
