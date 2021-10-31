from ovelha import Ovelha
from clonador_de_animais import ClonadorDeAnimais

if __name__ == "__main__":
    clonador = ClonadorDeAnimais()
    ovelha_dolly = Ovelha()
    ovelha_fofolete = clonador.clonar_animal(ovelha_dolly)

    print("\novelha dolly:")
    print(ovelha_dolly)
    print(f"id: {id(ovelha_dolly)}\n")

    print("ovelha_fofolete:")
    print(ovelha_fofolete)
    print(f"id: {id(ovelha_fofolete)}\n")
    msg = (
        "Objetos iguais"
        if id(ovelha_dolly) == id(ovelha_fofolete)
        else "Objetos diferentes"
    )
    print(msg)

    ovelha_dolly.tamanho = 20.0

    print("\novelha dolly:")
    print(ovelha_dolly)
    print(f"id: {id(ovelha_dolly)}\n")

    print(id(ovelha_fofolete))
    print(ovelha_fofolete)
    print(f"id: {id(ovelha_fofolete)}\n")

    msg = (
        "A mudança no tamanho não afetou os dois. Ou seja, deu certo"
        if ovelha_dolly.tamanho != ovelha_fofolete.tamanho
        else "Deu ruim"
    )
    print(msg)
