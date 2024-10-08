from abc import abstractmethod, ABC


class AtacanteInimigo(ABC):
    @abstractmethod
    def atirar(self) -> None:
        pass

    @abstractmethod
    def seguir_em_frente(self) -> None:
        pass

    @abstractmethod
    def atribuir_motorista(self, nome_motorista: str) -> None:
        pass
