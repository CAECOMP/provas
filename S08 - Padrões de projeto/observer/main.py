from stock_grabber import AdministradorAcoes
from stock_observer import ObservadorAcoes
from time import sleep


if __name__ == "__main__":
    administrador = AdministradorAcoes()
    observador_1 = ObservadorAcoes(identificador=1, assunto=administrador)

    print("\nprimeira atualização...")
    administrador.preco_ibm = 200.0
    sleep(1)

    print("\nsegunda atualização...")
    administrador.preco_apple = 300.0
    sleep(1)

    print("\nterceira atualização...")
    administrador.preco_google = 400.0
    sleep(1)

    print()
    observador_2 = ObservadorAcoes(identificador=2, assunto=administrador)

    print("\nquarta atualização...")
    administrador.preco_ibm = 20000.0
    sleep(1)

    print("\nquinta atualização...")
    administrador.preco_apple = 30000.0
    sleep(1)

    print("\nsexta atualização...")
    administrador.preco_google = 40000.0
    sleep(1)
