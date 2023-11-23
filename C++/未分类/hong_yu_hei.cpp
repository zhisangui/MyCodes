#include<stdio.h>
#include<iostream>
using namespace std;
struct que{
	int x, y;
}q[1000];
char a[30][30];
int vis[30][30];
int main(){
	int w, h;
	while((scanf("%d %d",&w, &h)) != EOF && (w != 0 || h != 0)){
		getchar();
		int sum = 1;
		int f = 1, r = 1;
		int dx[4] = {0, 0, 1, -1};
		int dy[4] = {1, -1, 0, 0};
		for(int i = 1; i <= h; i ++){
			for(int j = 1; j <= w; j ++){
				cin >> a[i][j];
				vis[i][j] = 0;
				if(a[i][j] == '@'){
					q[1].x = i;
					q[1].y = j;
					vis[i][j] = 1;
				}	
			}
			getchar();
		}
		while(f <= r){
		
			for(int i = 0; i < 4; i ++){
				int nx = q[f].x + dx[i];
				int ny = q[f].y + dy[i];
				if(!vis[nx][ny] && nx<=h && nx>=1 && ny<=w && ny >= 1){
					if(a[nx][ny] == '.'){
						r ++;
						sum ++;
						vis[nx][ny] = 1;
						q[r].x = nx;
						q[r].y = ny;
					}
				}
			}
			f ++;
		}
		cout << sum << endl;
	}
	return 0;
}
