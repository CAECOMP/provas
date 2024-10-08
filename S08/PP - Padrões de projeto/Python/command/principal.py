from controle_tv import ControleRemoto
from comando_ligar_tv import ComandoLigarTV
from comando_desligar_tv import ComandoDesligarTV
from comando_aumentar_volume_tv import ComandoAumentarVolumeTV
from comando_diminuir_volume_tv import ComandoDiminuirVolumeTV
from botao_dispositivo import BotaoDispositivo


if __name__ == '__main__':
    tv = ControleRemoto.pegar_dispositivo_eletronico()

    ligar_tv = ComandoLigarTV(dispositivo=tv)
    botao = BotaoDispositivo(comando=ligar_tv)
    botao.apertar()

    aumentar_volume = ComandoAumentarVolumeTV(dispositivo=tv)
    botao = BotaoDispositivo(comando=aumentar_volume)
    botao.apertar()
    botao.apertar()
    botao.apertar()
    botao.apertar()
    botao.apertar()

    diminuir_volume = ComandoDiminuirVolumeTV(dispositivo=tv)
    botao = BotaoDispositivo(comando=diminuir_volume)
    botao.apertar()
    botao.apertar()

    desligar_tv = ComandoDesligarTV(dispositivo=tv)
    botao = BotaoDispositivo(comando=desligar_tv)
    botao.apertar()

