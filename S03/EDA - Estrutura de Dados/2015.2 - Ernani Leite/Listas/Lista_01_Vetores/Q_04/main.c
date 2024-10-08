#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE !FALSE

int primo(int n){
    int divisoes, i;
    divisoes = 0;
    if(n <= 0)
        return FALSE;
    if(n == 1)
        return TRUE;
    for(i = 1; i <= n; i++){
        if(!(n%i))
            divisoes++;
    }
    if(divisoes == 2)
        return TRUE;
    else
        return FALSE;
}
int main()
{
    int n, i, aux, ehPrimo;
    do{
        ehPrimo = FALSE;
        printf("Digite o valor de N que seja primo:\n");
        scanf("%d",&n);
        if(primo(n)){
            printf("Primo\n");
            ehPrimo = TRUE;
        }
        else
            printf("Não é primo\n");
    }while(!ehPrimo);
    printf("Primos anteriores:\n");
    aux = 0;
    for(i = n-1; i > 0; i--){
        if(primo(i))
        {
            printf("%d\n", i);
            aux++;
        }
        if(aux >= 2)
            break;
    }
    printf("Primos seguintes:\n");
    aux = 0;

    for(i = n+1; TRUE; i++){
        if(primo(i)){
            printf("%d\n", i);
            aux++;
        }
        if(aux >= 2)
            break;
    }
    return 0;
}
