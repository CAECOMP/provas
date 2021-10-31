from cobertura_decorator import CoberturaDecorator


class MolhoDeTomate(CoberturaDecorator):
    def __init__(self, pizza):
        super().__init__(pizza)

        print("Adicionando tomate")

    def pegar_descricao(self) -> str:
        return self._pizza.pegar_descricao() + ", molho de tomate"

    def pegar_valor(self) -> float:
        return self._pizza.pegar_valor() + 0.35
