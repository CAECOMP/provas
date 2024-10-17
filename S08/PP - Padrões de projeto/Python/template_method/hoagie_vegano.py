from hoagie import Hoagie


class HoagieVegano(Hoagie):
    def __init__(self):
        self.vegetais_usados = ["alface", "tomate", "cebolas", "pimenta doce"]
        self.condimentos_usados = ["óleo", "vinagre"]

    def adicionar_verduras(self):
        print("adicionando verdura: ", end="")
        for vegetal in self.vegetais_usados:
            print(f"{vegetal}", end=" ")

    def adicionar_condimentos(self):
        print("\nadicionando condimento: ", end="")
        for condimento in self.condimentos_usados:
            print(f"{condimento}", end=" ")

    def adicionar_carne(self):
        pass

    def adicionar_queijo(self):
        pass

    def cliente_quer_carne(self):
        return False

    def cliente_quer_queijo(self):
        return False
