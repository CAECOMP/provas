from interface_sujeito import InterfaceSujeito
from sujeito import Sujeito


class Proxy(InterfaceSujeito):
    def __init__(self, sujeito_real: Sujeito) -> None:
        self._sujeito = sujeito_real

    def requisicao(self) -> None:
        if self.verificar_acesso():
            self._sujeito.requisicao()
            self.registro_de_acesso()

    def verificar_acesso(self) -> bool:
        print("Proxy: Verificar acesso antes de fazer requisição.")
        return True

    def registro_de_acesso(self) -> None:
        print("Proxy: Registrando a hora da solicitação.", end="")

