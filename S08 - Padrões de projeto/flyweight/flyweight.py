import json


class Flyweight:
    def __init__(self, estado_compartilhado: str) -> None:
        self._estado_compartilhado = estado_compartilhado

    def operacao(self, estado_unico: str) -> None:
        compartilhado = json.dumps(self._estado_compartilhado)
        unico = json.dumps(estado_unico)
        print(f"Flyweight: Exibindo compartilhado ({compartilhado}) e o estado ({unico}) único.", end="")
