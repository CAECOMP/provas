from abc import ABC, abstractmethod


class DispositivoDeEntretenimento(ABC):
    def __init__(self):
        self.estado_do_dispositivo = 0
        self.configuracao_maxima = 0
        self.volume = 0

    @abstractmethod
    def botao_cinco_pressionado(self):
        pass

    @abstractmethod
    def botao_seis_pressionado(self):
        pass

    @abstractmethod
    def botao_sete_pressionado(self):
        self.volume += 1
        print(f"Volume em {self.volume}")

    @abstractmethod
    def botao_oito_pressionado(self):
        self.volume -= 1
        print(f"Volume em {self.volume}")

    @abstractmethod
    def feedback_do_dispositivo(self):
        if self.estado_do_dispositivo > self.configuracao_maxima or self.estado_do_dispositivo < 0:
            self.estado_do_dispositivo = 0

        print(f"No canal {self.estado_do_dispositivo}")
