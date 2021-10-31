class NumeroContaDoBanco:
    def __init__(self):
        self.numero_conta = 123456

    def validar_numero_conta(self, numero: int):
        resultado = False
        if numero == self.numero_conta:
            resultado = True

        return resultado
