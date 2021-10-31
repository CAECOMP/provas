from dispositivo_eletronico import DispositivoEletronico


class Televisao(DispositivoEletronico):
    _volume = 0

    def ligar(self):
        print("Televisão ligada")

    def desligar(self):
        print("Televisão desligada")

    def aumentar_volume(self):
        self._volume += 1
        print(f"O volume da televisão é {self._volume}")

    def diminuir_volume(self):
        self._volume -= 1
        print(f"O volume da televisão é {self._volume}")

