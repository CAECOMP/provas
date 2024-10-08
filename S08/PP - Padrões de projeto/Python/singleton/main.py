from singleton import ConexaoBancoDeDados
from threading import Thread


def criando_conexao_banco(valor: str) -> None:
    banco = ConexaoBancoDeDados(valor)
    print(banco.nome_da_conexao)


if __name__ == "__main__":
    # Código do cliente

    print(
        "Teste com threads para ver se é criada apenas uma conexão.\n\n"
        "Se você ver o mesmo valor, então a conexão com o banco está sendo reusada (ieeeeei \o/)\n"
        "Se os valores forem diferentes, "
        "então duas conexões distintas foram criadas. Ou seja, deu ruim, pessoal!! :(\n\n"
        "Resultado:\n"
    )

    conexao_1 = Thread(target=criando_conexao_banco, args=("Mongo",))
    conexao_2 = Thread(target=criando_conexao_banco, args=("Postgres",))
    conexao_1.start()
    conexao_2.start()
