from particula import Particula


if __name__ == '__main__':
    particula_1 = Particula(valor_velocidade=10.0, massa=2.0)
    resultado_energia_cinetica = particula_1.calcular_energia_cinetica()
    print(f"valor da energia cinética: {resultado_energia_cinetica}\n")

    particula_2 = Particula(valor_velocidade=5.0, massa=10.0)
    resultado_energia_cinetica = particula_2.calcular_energia_cinetica()
    print(f"valor da energia cinética: {resultado_energia_cinetica}\n")
