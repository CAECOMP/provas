from typing import List, Dict
from flyweight import Flyweight


class FabricaFlyweight:
    _flyweights: Dict[str, Flyweight] = {}

    def __init__(self, flyweights_iniciais: List) -> None:
        for estado in flyweights_iniciais:
            self._flyweights[self.obter_chave(estado)] = Flyweight(estado)

    def obter_chave(self, estado: Dict) -> str:
        return "_".join(sorted(estado))

    def obter_flyweight(self, estado_compartilhado: Dict) -> Flyweight:
        chave = self.obter_chave(estado_compartilhado)

        if not self._flyweights.get(chave):
            print("Fábrica: Não foi achado o flyweight. Criando um novo.")
            self._flyweights[chave] = Flyweight(estado_compartilhado)
        else:
            print("Fábrica: Reutilizano um flyweight já existente.")

        return self._flyweights[chave]

    def listar_flyweights(self) -> None:
        quantidade_de_objetos = len(self._flyweights)
        print(f"Fábrica: Temos {quantidade_de_objetos} flyweights:")
        print("\n".join(map(str, self._flyweights.keys())), end="")
