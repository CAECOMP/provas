from abc import ABC, abstractmethod


class Hoagie(ABC):
    def fazer_sanduba(self):
        self.cortar_pao()

        if self.cliente_quer_carne():
            self.adicionar_carne()

        if self.cliente_quer_queijo():
            self.adicionar_queijo()

        if self.cliente_quer_verduras():
            self.adicionar_verduras()

        if self.cliente_quer_condimentos():
            self.adicionar_condimentos()

        self.embalar_sanduba()

    def cortar_pao(self):
        print(f"O sanduba foi cortado!")

    @abstractmethod
    def adicionar_carne(self):
        pass

    @abstractmethod
    def adicionar_queijo(self):
        pass

    @abstractmethod
    def adicionar_verduras(self):
        pass

    @abstractmethod
    def adicionar_condimentos(self):
        pass

    @staticmethod
    def cliente_quer_carne():
        return True

    @staticmethod
    def cliente_quer_queijo():
        return True

    @staticmethod
    def cliente_quer_verduras():
        return True

    @staticmethod
    def cliente_quer_condimentos():
        return True

    def embalar_sanduba(self):
        print("\nEmbalando o sanduba!")
