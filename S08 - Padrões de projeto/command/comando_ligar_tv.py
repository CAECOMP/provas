from comando import Comando
from dispositivo_eletronico import DispositivoEletronico


class ComandoLigarTV(Comando):
    def __init__(self, dispositivo: DispositivoEletronico):
        self.dispositivo = dispositivo

    def executar(self):
        self.dispositivo.ligar()

