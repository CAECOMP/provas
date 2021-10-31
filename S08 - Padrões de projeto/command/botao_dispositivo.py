from comando import Comando


class BotaoDispositivo:
    def __init__(self, comando: Comando):
        self.comando = comando

    def apertar(self):
        self.comando.executar()
