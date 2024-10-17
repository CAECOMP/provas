from televisao import Televisao
from dispositivo_eletronico import DispositivoEletronico


class ControleRemoto:
    @classmethod
    def pegar_dispositivo_eletronico(cls) -> DispositivoEletronico:
        return Televisao()
