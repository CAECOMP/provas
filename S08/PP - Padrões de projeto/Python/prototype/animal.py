from abc import ABC, abstractmethod


class Animal(ABC):
    @abstractmethod
    def clonar(self):
        pass
