from __future__ import annotations
from abc import ABC, abstractmethod


class Contexto:
    _estado_atual = None

    def __init__(self, estado: Estado) -> None:
        self.transitar_para(estado)

    def transitar_para(self, state: Estado):
        print(f"Contexto: Transitando para o estado {type(state).__name__}")
        self._estado_atual = state
        self._estado_atual.contexto = self

    def requisicao_1(self):
        self._estado_atual.lidar_com_requisicao_1()

    def requisicao_2(self):
        self._estado_atual.lidar_com_requisicao_2()


class Estado(ABC):
    def __init__(self, contexto = None):
        self._contexto = contexto

    @property
    def contexto(self) -> Contexto:
        return self._contexto

    @contexto.setter
    def contexto(self, contexto: Contexto) -> None:
        self._contexto = contexto

    @abstractmethod
    def lidar_com_requisicao_1(self) -> None:
        pass

    @abstractmethod
    def lidar_com_requisicao_2(self) -> None:
        pass


class EstadoA(Estado):
    def lidar_com_requisicao_1(self) -> None:
        print("Estado A resolvendo a requisição 1.")
        print("O estado A deseja alterar o estado do contexto.")
        self.contexto.transitar_para(EstadoB())

    def lidar_com_requisicao_2(self) -> None:
        print("Estado A resolvendo a requisição 2.")


class EstadoB(Estado):
    def lidar_com_requisicao_1(self) -> None:
        print("Estado B resolvendo a requisição 1.")

    def lidar_com_requisicao_2(self) -> None:
        print("Estado B resolvendo a requisição 2.")
        print("O estado B deseja alterar o estado do contexto.")
        self.contexto.transitar_para(EstadoA())


if __name__ == "__main__":
    contexto = Contexto(EstadoA())
    contexto.requisicao_1()
    contexto.requisicao_2()
