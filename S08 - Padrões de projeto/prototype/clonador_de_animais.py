from animal import Animal


class ClonadorDeAnimais:
    def clonar_animal(self, animal_a_ser_clonado: Animal):
        return animal_a_ser_clonado.clonar()
