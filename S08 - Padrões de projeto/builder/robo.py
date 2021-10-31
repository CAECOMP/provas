from interface_robo import InterfaceRobo


class Robo(InterfaceRobo):
    _cabeca: str
    _tronco: str
    _bracos: str
    _pernas: str

    def __str__(self) -> str:
        return f"cabeça: {self._cabeca}\ntronco: {self._tronco}\nbracos: {self._bracos}\npernas: {self._pernas}"

    def criar_cabeca(self, cabeca: str) -> None:
        self._cabeca = cabeca

    def criar_troco(self, tronco: str) -> None:
        self._tronco = tronco
    
    def criar_bracos(self, bracos: str) -> None:
        self._bracos = bracos
    
    def criar_pernas(self, pernas: str) -> None:
        self._pernas = pernas

    @property
    def cabeca(self) -> str:
        return self._cabeca
    
    @property
    def tronco(self) -> str:
        return self._tronco

    @property
    def bracos(self) -> str:
        return self._cabeca

    @property
    def pernas(self) -> str:
        return self._pernas
