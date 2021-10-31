from cobertura_decorator import CoberturaDecorator


class Mussarela(CoberturaDecorator):
    def __init__(self, pizza):
        super().__init__(pizza)

        print("Adicionando massa")
        print("Adicionando mussarela")

    def pegar_descricao(self) -> str:
        return self._pizza.pegar_descricao() + ", mussarela"

    def pegar_valor(self) -> float:
        return self._pizza.pegar_valor() + 0.50
