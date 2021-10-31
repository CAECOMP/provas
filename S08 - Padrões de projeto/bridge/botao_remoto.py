from abc import ABC, abstractmethod
from dispositivo_de_entretenimento import DispositivoDeEntretenimento


class BotaoRemoto(ABC):
    def __init__(self, dispositivo: DispositivoDeEntretenimento):
        self._dispositivo = dispositivo

    @abstractmethod
    def botao_cinco_pressionado(self):
        self._dispositivo.botao_cinco_pressionado()

    @abstractmethod
    def botao_seis_pressionado(self):
        self._dispositivo.botao_seis_pressionado()

    @abstractmethod
    def feedback_do_dispositivo(self):
        self._dispositivo.feedback_do_dispositivo()

    @abstractmethod
    def botao_nove_pressionado(self):
        pass
