from interface_sujeito import InterfaceSujeito


class Sujeito(InterfaceSujeito):
    def requisicao(self) -> None:
        print("Tratamento de requisição.")
