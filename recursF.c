#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long retorno (long numero);
float raiz(long numero);
float resta(long numero);
float dividirentre2(long numero);
int main(int argc, char **argv){
    long obsoleto1, obsoleto2, obsoleto3, numero;
    scanf("%ld %ld %ld %ld", &obsoleto1, &obsoleto2, &obsoleto3, &numero);
    printf("%ld", retorno(numero));
    return 0;
}
float raiz(long numero){
    float raiz1;
    raiz1=powf(2*numero-1, (float)1/(float)2);
    return raiz1;
}
float resta(long numero){
    return raiz(numero)-1;
}
float dividirentre2(long numero){
    float ret;
    ret=resta(numero)/(float)2;
    return ret;
}
long retorno(long numero){
    long ret;
    ret=(long)ceil(dividirentre2(numero));
    return ret;
}