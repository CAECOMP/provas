from abc import abstractmethod, ABC


class Pizza(ABC):
    @abstractmethod
    def pegar_descricao(self) -> str:
        pass

    @abstractmethod
    def pegar_valor(self) -> float:
        return 4.0
