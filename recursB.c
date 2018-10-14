#include <stdio.h>
int main(int argc, const char * argv[]){
    int veces, i;
    long long dato;
    scanf("%d", &veces);
    long long matriz[veces][2];
    for (i=1; i<=veces; i++){
        scanf("%lld", &dato);
        matriz[i][1]=dato;
        matriz[i][2]=(dato*2)+1;
    }
    for(i=1; i<=veces; i++){
        if(matriz[i][1]==0)
            printf("%lld\n", matriz[i][1]);
        else
            printf("%lld/%lld\n", matriz[i][1], matriz[i][2]);
    }
    return 0;
}