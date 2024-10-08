from threading import Lock


class SingletonMeta(type):
    _instancias = {}

    _lock: Lock = Lock()

    def __call__(cls, *args, **kwargs):
        with cls._lock:
            if cls not in cls._instancias:
                instancia = super().__call__(*args, **kwargs)
                cls._instancias[cls] = instancia

        return cls._instancias[cls]


class ConexaoBancoDeDados(metaclass=SingletonMeta):
    nome_da_conexao: str = None

    def __init__(self, nome_da_conexao: str) -> None:
        self.nome_da_conexao = nome_da_conexao

    def alguma_logica_de_negocio(self):
        pass
