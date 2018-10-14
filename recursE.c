#include <stdio.h>
#include <stdlib.h>

typedef struct nodo nodo;

struct nodo{
    int dato;
    nodo *siguiente;
    nodo *anterior;
};

nodo *inicio = NULL;
nodo *fin = NULL;
nodo *inicio2 = NULL;
nodo *fin2 = NULL;

nodo *nuevonodo(int dato){
	nodo *nuevo=(nodo*)malloc(sizeof(nodo));
	nuevo->dato=dato;
	nuevo->siguiente=NULL;
	nuevo->anterior=NULL;
	return nuevo;
}

int colavacia(){
	if((inicio==NULL)&&(fin==NULL)){
		return 1;
	}else{
		return 0;
	}
}

int pilavacia(){
	if((inicio2==NULL)&&(fin2==NULL)){
		return 1;
	}else{
		return 0;
	}
}

void encolar(int dato){
	nodo *nuevo=nuevonodo(dato);
	if(colavacia()){
		inicio=nuevo;
		fin=nuevo;
	}else{
		fin->siguiente=nuevo;
		nuevo->anterior=fin;
		fin=nuevo;
	}
}

void push(int dato){
	nodo *nuevo=nuevonodo(dato);
	if(pilavacia()){
		inicio2=nuevo;
		fin2=nuevo;
	}else{
		inicio2->siguiente=nuevo;
		nuevo->anterior=inicio2;
		inicio2=nuevo;
	}
}

int desencolar(){
	nodo *aux;
	if(colavacia()){
		return 0;
	}else{
		aux=inicio;
		inicio=inicio->siguiente;
		aux->siguiente=NULL;
		if(inicio!=NULL){
			inicio->anterior=NULL;
		}else{
			fin=NULL;
		}
	}
	int resultado=aux->dato;
	free(aux);
	return resultado;
}

int pop(){
	nodo *aux;
	if(pilavacia()){
		return 0;
	}else{
		aux=inicio2;
		inicio2=inicio2->anterior;
		aux->anterior=NULL;
		if(inicio2!=NULL){
			inicio2->siguiente=NULL;
		}else{
			fin2=NULL;
		}
	}
	int resultado=aux->dato;
	free(aux);
	return resultado;
}

void ordenaSubs(int a, int *sub){
	if(a==0){
		sub[a]=sub[a];
	}else{
		if(sub[a]<sub[a-1]){
			int ax;
			ax=sub[a];
			sub[a]=sub[a-1];
			sub[a-1]=ax;
		}
		ordenaSubs(a-1,sub);
	}
}

void mergeSort(int n){
	int ac=0;
	nodo *aux=inicio;
  nodo *aux2=inicio2;
	while(aux!=NULL && aux2!=NULL){
			if(aux->dato<=aux2->dato){
        printf("%d ", desencolar());
        aux = inicio;
			}else{
        printf("%d ", pop());
        aux2 = inicio2;
			}
			ac++;
	}
  while(aux!=NULL){
    printf("%d ", desencolar());
    ac++;
    aux = inicio;
  }
  while(aux2!=NULL){
    printf("%d ", pop());
    aux2 = inicio2;
    ac++;
  }
}

int main(){
	int n,datos;
	scanf("%d", &n);
	int arr[n];
	for(int i=0; i<n; i++){
		scanf("%d", &datos);
		arr[i]= datos;
	}

	if(n%2==0){
    int ac=0;
		int sub1[n/2];
		int sub2[n/2];
		for(int j=0;j<(n/2);j++){
			sub1[j]=arr[j];
			ordenaSubs(j,sub1);
		}
    for(int j=0;j<(n/2);j++){
			encolar(sub1[j]);
		}
		for(int k=n/2;k<n;k++){
			sub2[ac]=arr[k];
			ordenaSubs(ac,sub2);
      ac++;
		}
    for(int j=0;j<(n/2);j++){
			push(sub2[j]);
		}
	}
	else{
		int sub1[(n+1)/2];
		int sub2[(n-1)/2];
    int ac=0;
		for(int i=0;i<((n+1)/2);i++){
			sub1[i]=arr[i];
			ordenaSubs(i,sub1);
		}
    for(int j=0;j<(n+1)/2;j++){
			encolar(sub1[j]);
		}
		for(int m=((n+1)/2);m<n;m++){
			sub2[ac]=arr[m];
			ordenaSubs(ac,sub2);
      ac++;
		}
    for(int j=0;j<(n-1)/2;j++){
			push(sub2[j]);
		}
	}
  mergeSort(n);
    return 0;
}
