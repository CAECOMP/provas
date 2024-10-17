from componente_cancao import ComponenteCancao


class Cancao(ComponenteCancao):
    def adicionar(self, cancao) -> None:
        super(Cancao, self).adicionar()

    def remover(self, cancao) -> None:
        super(Cancao, self).remover()

    def obter_componente(self, indice: int) -> "ComponenteCancao":
        super(Cancao, self).obter_componente()

    def obter_nome_cancao(self) -> None:
        super(Cancao, self).obter_nome_cancao()

    def obter_nome_da_banda(self) -> None:
        super(Cancao, self).obter_nome_da_banda()

    def obter_ano_de_lancaomento(self) -> None:
        super(Cancao, self).obter_ano_de_lancaomento()

    def __init__(self, nome: str, nome_da_banda: str, ano_de_lancamento: int):
        self._nome = nome
        self._nome_da_banda = nome_da_banda
        self._ano_de_lancamento = ano_de_lancamento

    @property
    def nome(self):
        return self._nome

    @property
    def nome_da_banda(self):
        return self._nome_da_banda

    @property
    def ano_de_lancamento(self):
        return self._ano_de_lancamento

    def mostrar_informacoes_da_cancao(self) -> None:
        print(f"{self.nome} foi gravado por {self.nome_da_banda} no ano de {self.ano_de_lancamento}")