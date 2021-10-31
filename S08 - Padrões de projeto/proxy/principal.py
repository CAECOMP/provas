from interface_sujeito import InterfaceSujeito
from sujeito import Sujeito
from proxy import Proxy


def executar_cliente(sujeito: InterfaceSujeito) -> None:
    sujeito.requisicao()


if __name__ == "__main__":
    print("Cliente: Executando cliente com o sujeito concreto:")
    sujeito_real = Sujeito()
    executar_cliente(sujeito_real)

    print()

    print("Cliente: Executando o mesmo cliente utilizando o proxy:")
    proxy = Proxy(sujeito_real)
    executar_cliente(proxy)
