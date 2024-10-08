#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

//============================ METODOS AUXILIARES ============================//

 typedef struct {
    int tam;
    double** matriz;
} MatrizSL;

double** alocaMatriz(int l, int c){
    int i, j;
    double **m;
    m = malloc(sizeof(double*) * l);
    if(m == NULL)
        return NULL;
    for(i=0;i<l;i++){
        m[i] = malloc(sizeof(double)*c);
        if(m[i] == NULL){
            for (j = 0; j < i; j++)
                free(m[j]);
            free(m);
            return NULL;
        }
    }
    return m;
}

double* alocaVetor(int c){
    double *m;
    m = malloc(sizeof(double) * c);
    if(m == NULL)
        return NULL;
    return m;
}

void imprimeMatriz(double **m, int l, int c){
    int i;
    int j;
    for(i=0; i < l; i++){
        for (j = 0; j < c; j++){
            printf("%9.3lf \n", m[i][j]);
        }
        printf("\n");
    }
}

void leMatrizLagrange(double **m, int l, int c){
    int i = 0, j;
    do {
        printf("Informe A%d : ", c-i-1);
        scanf(" %lf", &m[0][0]);
        if(m[0][0] <= 0)
            printf("Lembrar: Termo A%d obrigatoriamente positivo e nao-nulo.\n", c-i-1);
    } while(m[0][0] <= 0);

    for (i = 1; i < c-1; i++){
        printf("Informe A%d: ", c-i-1);
        scanf(" %lf", &m[0][i]);
    }

    do {
        printf("Informe A%d : ", 0);
        scanf(" %lf", &m[0][c-1]);
        if(m[0][c-1] == 0)
            printf("Lembrar: A0 obrigatoriamente diferente de 0.\n");
    } while(m[0][c-1] == 0);

    m[0][c] = 0; m[0][c+1] = 0;

    for(i=1; i < l; i++){
        for(j=0; j<c+2; j++) {
            m[i][j] = 0;
        }
    }
    imprimeMatriz(m,l,c);
}

MatrizSL* lerArquivo(){
    int  n, i, j;
    double **matrix;
    char nomeArquivo[20];
    FILE *fp;

    printf("Digite o nome do arquivo: ");
    scanf(" %s", nomeArquivo);
    fp = fopen(nomeArquivo, "r");

    if(fp == NULL){
        printf("O arquivo nao existe.\n");
        return NULL;
    }
    fscanf(fp, " %d", &n);
    
    matrix = alocaMatriz(n, n+1);

    for (i = 0; i < n; i++){
        for (j = 0; j < n + 1; j++){
            fscanf(fp, " %lf", &matrix[i][j]);
        }
    }
    fclose(fp);
    MatrizSL* mSL = (MatrizSL*)malloc(sizeof(MatrizSL));;

    if(mSL == NULL)
        return NULL;
    mSL->matriz = matrix;
    mSL->tam = n;

    return mSL;
}
//============================ METODOS AUXILIARES ============================//
//============================ METODO DE LAGRANGE ============================//
int perguntaGrauEquacao() {
    int grauEq;
    do {
        printf("Informe grau da equação: ");
        scanf(" %d", &grauEq);
        printf("\n");
    } while(grauEq < 0);
    return grauEq;
}

void metodoDeLagrange() {
    int i, j;
    int mTam  = perguntaGrauEquacao() + 1;
    double** ml = alocaMatriz(4, mTam + 2);
    double* limites = alocaVetor(4);

    leMatrizLagrange(ml, 1, mTam);

    for(i=0; i<mTam; i++) {
        ml[1][mTam-1-i] = ml[0][i];
        ml[2][i] = i%2==0 ? ml[0][i] : -1*ml[0][i];
        ml[3][mTam-1-i] = i%2==0 ? ml[0][i] : -1*ml[0][i];
    }

    imprimeMatriz(ml, 4, mTam);

    //calculando o k e b respectivamente
    for(j=0; j<4; j++) {
        for(i=0; i<mTam; i++) {
            ml[j][mTam] = ((ml[j][i] < 0) && ((mTam-i-1) > ml[j][mTam])) ? (mTam-i-1) : ml[j][mTam];
            ml[j][mTam+1] = (ml[j][i] < ml[j][mTam+1]) ? ml[j][i] : ml[j][mTam+1];
        }

        ml[j][mTam+1] = fabs(ml[j][mTam+1]);
    }

    //calculando os limites
    for(i=0; i<4; i++) {
        limites[i] = (1.0 + pow(ml[i][mTam+1]/ml[i][0], 1.0/(mTam-1-ml[i][mTam]))) * (i<2 ? 1 : -1);
    }

    printf("Os limites para a equacao sao:\n");
    printf("Superiores: %.4f  <= x <=  %.4f\n", 1.0/limites[1], limites[0]);
    printf("Inferiores: %.4f <= x <= %.4f\n", limites[2], 1.0/limites[3]);
}
//============================ METODO DE LAGRANGE ============================//








//============================ METODO DE GAUSS-SEIDEL ============================//


//retorna 1 para bem condicionada. -1 para mal condicionada
int checarCriterioDasLinhasEColunas(double** m) {
    int nVariaveis = 3, i, j;
    double pivo, somaLinha, somaColuna;

    for (i = 0; i < nVariaveis; i++){
        somaLinha = 0.0;
        somaColuna = 0.0;
        pivo = fabs(m[i][i]);

        for (j = 0; j < nVariaveis; j++){
            if (i != j){
                somaLinha = somaLinha + fabs(m[i][j]);
                somaColuna = somaColuna + fabs(m[j][i]);
            }

            if (somaLinha > pivo || somaColuna > pivo)
                return -1;
        }
    }
    return 1;
}
/*
*   @brief
*   @params
*/
void metodoDeGaussSeidel() {
    MatrizSL* mSL = lerArquivo();

    if(mSL == NULL) {
        printf("Houve um erro ao ler a matriz ou o arquivo.\n");
        return;
    }

    double** m = mSL->matriz;

    if (checarCriterioDasLinhasEColunas(m) == -1) {
        printf("\nMatriz não satisfaz criterio das linhas e colunas\n");
        return;
    }
    //verificar condicionamento
    double divisor, valorLinha;
    int i, j, h = 0;
    int nVariaveis = mSL->tam;
    double valores[nVariaveis];
    double valoresAnteriores[nVariaveis];

    for(i=0;i<nVariaveis;i++){
        valores[i] = 0.0;
        valoresAnteriores[i] = 0.0;
    }

    int difMinimaAlcancada = 0;
    while (h<1000 && difMinimaAlcancada == 0){
        for(i=0; i<nVariaveis; i++) {
            valorLinha = 0.0;
            divisor = m[i][i];
            for(j=0; j<nVariaveis; j++){
                if(i!=j) {
                    valorLinha = valorLinha - (valores[j] * m[i][j]);
                }
            }

            valores[i] = (valorLinha + m[i][nVariaveis])/divisor;
        }
        printf("%d\n", h);
        difMinimaAlcancada = 1;

        for(i=0; i<nVariaveis; i++) {
            difMinimaAlcancada = (fabs(valoresAnteriores[i]-valores[i]) < 0.00000001) && (difMinimaAlcancada == 1) ? 1 : 0;
            valoresAnteriores[i] = valores[i];
        }
        h++;
    }

    printf("Numero de iteracoes: %d\n", h);
    printf("Solucao encontrada:\n");
    for(i=0;i<nVariaveis;i++){
        printf("x%d: %f\n", i+1, valores[i]);
    }

    printf("\n");
}
//============================ METODO DE GAUSS-SEIDEL ============================//
// double metodoDeNewton(){
//   int grau, i, count = 0;
//   double *vcoef, *limites;

// //  TEORICAMENTE TA TUDO NO MÉTODO DE LAGRANGE 
// //   printf("Digite o grau da equacao: ");
// //   scanf(" %d", &grau);

// //   // Alocando espaço para o vetor de vvcoeficientes.
// //   vcoef = malloc(sizeof(double) * (grau+1));
// //   if(vcoef == NULL)
// //     return -1;
  
// //   // Lendo teclado e atribuindo valores.
// //   for (i = 0; i < grau+1; i++){
// //     printf("Digite o coeficiente %d da equacao: ", i+1);
// //     scanf(" %lf", &vcoef[i]);
// //   }

//   // Verificando as restricoes do método.
//   if(vcoef[0] <= 0 || vcoef[grau] == 0){
//     printf("\nOs coeficientes devem satisfazer os requisitos: An > 0 e A0 != 0\n");
//     return -1;
//   }  
//   // for(int j=0;j<4;j++)
//   //   printf("%lf\t", vcoef[j]);

//   limites = metodoDeLagrange(grau, vcoef);
//   double aux, aux_linha, xi, xiprox = NULL;
//   xi = limites[1];
//   while(count < 1000 || abs(xi - xiprox) < 0.00000001){
//     aux = 0;
//     aux_linha = 0;
    
//     if(xiprox != NULL)
//       xi = xiprox;

//     for (i = 0; i < grau + 1; i++){
//       aux += vcoef[i] * pow(xi, grau - i);
//       aux_linha += (grau-i) * vcoef[i] * pow(xi, grau - (1 + i));
//     }
//     xiprox = xi - (aux/aux_linha);
//     count += 1;
//   }

//   return 0.0;
// }

/*
*   @brief  método auxiliar para checar os valores quando for imprimir
*           na base hexxadecimal.
*   @params value, valor a ser verificado. Se for entre 10 - 15,imprime
*           a respectiva letra, caso nao, imprime o proprio value.*/
void checkValue(int value){
  switch (value){
    case 10: printf("A");
      break;
    case 11: printf("B");
      break;
    case 12: printf("C");
      break;
    case 13: printf("D");
      break;
    case 14: printf("E");
      break;
    case 15: printf("F");
      break;
    default: printf("%d", value);
      break;
  }
}

/*
*   @brief  método que converte de decimal para binário
*   @params i, valor da parte inteira do decimal.
*           f, valor da parte fracionária do decimal.
*/
void convertBin(int i, double f){
    int res_int[10], index_int = 0, index_frac = 0;
    double f_aux = f,  res_fra[20];

    while(i >= 2){
      res_int[index_int] = i%2;
      i = (i - i%2)/2;
      index_int++;
    }
    res_int[index_int] = i;

    while(f_aux > 0 && index_frac < 20){
      double k;
      f_aux = modf(f_aux * 2, &k);
      res_fra[index_frac] = k;
      index_frac++;
    }
    // Imprimindo valores convertidos
    printf("Binário: ");
    for(i=index_int; i>=0; i--)
      printf("%d", res_int[i]);
    if(f > 0){
      printf(".");
      for(i=0; i<index_frac; i++)
        printf("%d", (int)res_fra[i]);
    }
    printf("\n");
}

/*
*   @brief  método que converte de decimal para hexadecimal.
*   @params i, valor da parte inteira do decimal.
*           f, valor da parte fracionária do decimal.
*/
void convertHex(int i, double f){
  int res_int[10], index_int = 0, index_frac = 0;
  double f_aux = f,res_fra[20];

  while(i >= 16){
    res_int[index_int] = i%16;
    i = (i - i%16)/16;
    index_int++;
  }
  res_int[index_int] = i;

  while(f_aux > 0 && index_frac < 20){
    double k;
    f_aux = modf(f_aux * 16, &k);
    res_fra[index_frac] = k;
    index_frac++;
  }
  // Imprimindo valores convertidos
  printf("Hexadecimal: ");
  for(i=index_int; i>=0; i--)
    checkValue(res_int[i]);
  if(f > 0){
    printf(".");
    for(i=0; i<index_frac; i++)
      checkValue((int)res_fra[i]);
  }
  printf("\n");
}

/*
*   @brief  método que converte de decimal para octadecimal.
*   @params i, valor da parte inteira do decimal.
*           f, valor da parte fracionária do decimal.
*/
void convertOct(int i, double f){
  int res_int[10], index_int = 0, index_frac = 0;
  double f_aux = f, res_fra[20];

  while(i >= 8){
    res_int[index_int] = i%8;
    i = (i - i%8)/8;
    index_int++;
  }
  res_int[index_int] = i;

  while(f_aux > 0 && index_frac < 20){
    double k;
    f_aux = modf(f_aux * 8, &k);
    res_fra[index_frac] = k;
    index_frac++;
  }
  // Imprimindo valores convertidos
  printf("Octadecimal: ");
  for(i=index_int; i>=0; i--)
    printf("%d", res_int[i]);
  if(f > 0){
    printf(".");
    for(i=0; i<index_frac; i++)
      printf("%d",(int)res_fra[i]);
  }
  printf("\n");
}

int main(int argc, char* argv[]){
    setlocale(LC_ALL, "");

    char input;
    do {
      printf("C - Conversão \n");
      printf("S - Sistema Linear \n");
      printf("E - Equação Algébrica \n");
      printf("F - Finalizar \n");
      scanf(" %c", &input);
        switch(input){
          double value, intpart, fracpart;
          case 'C':
            // Conversão de base
            printf("Digite o número a ser convertido: ");
            scanf(" %lf", &value);
            fracpart = modf(value, &intpart);
            convertBin(intpart, fracpart);
            convertOct(intpart, fracpart);
            convertHex(intpart, fracpart);
            printf("\n");
            break;
          case 'S':
            metodoDeGaussSeidel();
            break;
          case 'E':
            metodoDeLagrange();
            break;
          case 'F':
            printf("Finalizando a aplicação...\n");
            return 0;
          default:
            printf("Comando inválido!\n");
            break;
        }
    } while(1);
}
