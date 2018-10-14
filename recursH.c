#include <stdio.h>
#include <string.h>
void comparaciones(char arreglo1[], char arreglo2[], unsigned long inicializar, unsigned long veces, unsigned long tamanno2, int *resultado){
    int i;
    if(inicializar<=veces){
        for(i=0; i<tamanno2; i++){
            if(arreglo1[i+inicializar]==arreglo2[i]){
                *resultado=(*resultado)+1;
            }
        }
        comparaciones(arreglo1, arreglo2, inicializar+1, veces, tamanno2, resultado);
    }
}
int main(int argc, char *argv[]) {
    char segundapalabra[2000000];
    char primerpalabra[2000000];
    int veces=0;
    unsigned long tamanno1, tamanno2, reiteraciones;
    scanf("%c", &segundapalabra);
    scanf("%c", &primerpalabra);
    tamanno1=strlen(primerpalabra);
    tamanno2=strlen(segundapalabra);
    reiteraciones=tamanno1-tamanno2;
    comparaciones(primerpalabra, segundapalabra, 0, reiteraciones, tamanno2, &veces);
    printf("%d", veces);
    return 0;
}