#include <stdio.h>

int vis[102][102];
int color;
int n, m;
int xf, yf;
char mapa[102][102];

void busqueda(int x, int y, int l){
	if(x<=0 || y<=0 || x>n || y>m)
		return;
	if(vis[x][y]==color)
		return;
	if(mapa[x][y]=='.')
		return;
	vis[x][y]=color;
	busqueda(x, y+1, l);
	busqueda(x, y-1, l);
	for(int i=1; i<=l; i++){
		busqueda(x+i, y, l);
		busqueda(x-i, y, l);    
	}    
}

int main(){
	scanf("%d %d",&n,&m);
	scanf("%d %d",&xf,&yf);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			scanf("%s",mapa[i][j]);    
		}    
	}
	for(int i=0; i<=n; i++){
		color++;
		busqueda(n, 1, i);
		if(vis[xf][yf]==color){
			printf("%d\n",i);
			break;    
		}    
	}
	return 0;
}
