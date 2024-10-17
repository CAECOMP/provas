from pizza import Pizza


class PizzaSimples(Pizza):
    def pegar_descricao(self) -> str:
        return "massa fina"

    def pegar_valor(self) -> float:
        return 4.0
