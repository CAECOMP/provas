from comando import Comando
from dispositivo_eletronico import DispositivoEletronico


class ComandoDiminuirVolumeTV(Comando):
    def __init__(self, dispositivo: DispositivoEletronico):
        self.dispositivo = dispositivo

    def executar(self):
        self.dispositivo.diminuir_volume()

