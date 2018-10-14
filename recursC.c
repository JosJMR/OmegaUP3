#include <stdio.h>
int MCD(int a,int b);
int main(int argc, char *argv[]) {
	int a,b;
	scanf("%d", &a);
	scanf("%d", &b);
	printf("%d",MCD(a,b));
}

int MCD(int a,int b){
	if(b==0){
		return a;
	}else{
		return MCD(b,a%b);
	}
	
}