#include <stdio.h>
int formula(int n);
int main(int argc, char *argv[]) {
	int n;
	scanf("%d",&n);
	printf("%d",formula(n));
	return 0;
}

int formula(int n){
	if(n<=5){
		return 1;
	}else{
		return formula(n-2)*5;
	}
}