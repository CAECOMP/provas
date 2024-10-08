from tv_remoto_mudo import TvRemotaMuda
from tv_remoto_pausa import TvRemotaPausa
from tv import Tv

if __name__ == '__main__':
    botao_remoto_tv_1 = TvRemotaMuda(Tv(1, 200))
    botao_remoto_tv_2 = TvRemotaPausa(Tv(1, 200))

    print("Teste da tv mutada")
    botao_remoto_tv_1.botao_cinco_pressionado()
    botao_remoto_tv_1.botao_seis_pressionado()
    botao_remoto_tv_1.botao_nove_pressionado()

    print("\nTeste da tv pausada")
    botao_remoto_tv_2.botao_cinco_pressionado()
    botao_remoto_tv_2.botao_seis_pressionado()
    botao_remoto_tv_2.botao_seis_pressionado()
    botao_remoto_tv_2.botao_seis_pressionado()
    botao_remoto_tv_2.botao_seis_pressionado()
    botao_remoto_tv_2.botao_nove_pressionado()
    botao_remoto_tv_2.feedback_do_dispositivo()
