from hoagie import Hoagie


class HoagieItaliano(Hoagie):
    def __init__(self):
        self.carnes_usadas = ["peperoni", "salame", "presunto de capicola"]
        self.queijos_usados = ["provolone"]
        self.vegetais_usados = ["alface", "tomate", "cebolas", "pimenta doce"]
        self.condimentos_usados = ["óleo", "vinagre"]

    def adicionar_carne(self):
        print("adicionando a carne: ", end="")
        for carne in self.carnes_usadas:
            print(f"{carne}", end=" ")

    def adicionar_queijo(self):
        print("\nadicionando o queijo: ", end="")
        for queijo in self.queijos_usados:
            print(f"{queijo}", end=" ")

    def adicionar_verduras(self):
        print("\nadicionando verdura: ", end="")
        for vegetal in self.vegetais_usados:
            print(f"{vegetal}", end=" ")

    def adicionar_condimentos(self):
        print("\nadicionando condimento: ", end="")
        for condimento in self.condimentos_usados:
            print(f"{condimento}", end=" ")
