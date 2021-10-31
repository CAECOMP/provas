from botao_remoto import BotaoRemoto
from dispositivo_de_entretenimento import DispositivoDeEntretenimento


class TvRemotaPausa(BotaoRemoto):
    def botao_cinco_pressionado(self):
        super(TvRemotaPausa, self).botao_cinco_pressionado()

    def botao_seis_pressionado(self):
        super(TvRemotaPausa, self).botao_seis_pressionado()

    def feedback_do_dispositivo(self):
        super(TvRemotaPausa, self).feedback_do_dispositivo()

    def __init__(self, dispotivo: DispositivoDeEntretenimento):
        super().__init__(dispositivo=dispotivo)

    def botao_nove_pressionado(self):
        print(f"A tv foi pausada")
