import abc


class FreteServico(metaclass=abc.ABCMeta):
  
  @abc.abstractmethod
  def calcula(self, peso: float) -> float:
    pass
