from __future__ import annotations
from abc import ABC


class Mediador(ABC):
    def notificar(self, remetente: object, evento: str) -> None:
        pass


class MediadorConcreto(Mediador):
    def __init__(self, componente_1: Componente1, componente_2: Componente2) -> None:
        self._componente_1 = componente_1
        self._componente_1.mediador = self
        self._componente_2 = componente_2
        self._componente_2.mediador = self

    def notificar(self, remetente: object, evento: str) -> None:
        if evento == "A":
            print("O mediador reage com A e dispara as seguintes operações:")
            self._componente_2.para_c()
        elif evento == "D":
            print("O mediador reage com D e dispara as seguintes operações:")
            self._componente_1.para_b()
            self._componente_2.para_c()


class ComponenteBase:
    def __init__(self, mediador: Mediador = None) -> None:
        self._mediador = mediador

    @property
    def mediador(self) -> Mediador:
        return self._mediador

    @mediador.setter
    def mediador(self, mediator: Mediador) -> None:
        self._mediador = mediator


class Componente1(ComponenteBase):
    def para_a(self) -> None:
        print("Componente 1 dispara A")
        self.mediador.notificar(self, "A")

    def para_b(self) -> None:
        print("Componente 1 dispara B")
        self.mediador.notificar(self, "B")


class Componente2(ComponenteBase):
    def para_c(self) -> None:
        print("Componente 2 dispara C")
        self.mediador.notificar(self, "C")

    def para_d(self) -> None:
        print("Componente 2 dispara D")
        self.mediador.notificar(self, "D")


if __name__ == "__main__":
    componente_1 = Componente1()
    componente_2 = Componente2()
    mediator = MediadorConcreto(componente_1, componente_2)

    print("Cliente dispara a operação A.")
    componente_1.para_a()

    print("\n", end="")

    print("Cliente dispara a operação D.")
    componente_2.para_d()
