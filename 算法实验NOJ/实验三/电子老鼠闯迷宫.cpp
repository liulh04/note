#include<iostream>
#include<queue>
using namespace std;
 
void init();
void dfs();
int cando(int xu, int yu, int i);
 
struct address{
	queue<int> row;
	queue<int> col;
}address;
 
char map[12][12];
bool used[12][12];
int xf, yf, xt, yt;
int step[12][12];
int x[4] = {0, 1, 0, -1};
int y[4] = {-1, 0, 1, 0};
 
int main(){
     init();
	 dfs();
}
 
void init(){
    int i, j;
	cin >> xf >> yf >> xt >> yt;
	for(i = 0; i < 12; i++){
		for(j = 0; j < 12; j++){
		    cin >> map[i][j];
			if(map[i][j] == 'X'){
			    used[i][j] = false;
			}
			else{
				used[i][j] = true;
		}
	}
	used[xf-1][yf-1] = false;
	step[xf-1][yf-1] = 0;
	address.row.push(xf-1);
	address.col.push(yf-1);
    }
}
 
void dfs(){
	int xu, yu, xv, yv;
	while(!address.row.empty()){
	    xu = address.row.front();
		yu = address.col.front();
		address.row.pop();
		address.col.pop();
		if(xu == xt-1 && yu == yt-1){
		    cout << step[xu][yu] << endl;
		}
		else{
			for(int i = 0; i < 4; i++){
				if(cando(xu, yu, i)){
				    xv = xu + x[i];
					yv = yu + y[i];
					address.row.push(xv);
					address.col.push(yv);
					used[xv][yv] = false;
					step[xv][yv] = step[xu][yu] +1;
				}
			}
		}
	}
}
 
int cando(int xu, int yu, int i){
    int xv, yv;
	xv = xu + x[i];
	yv = yu + y[i];
	if(xv < 0 || xv >=12 || yv < 0 || yv >=12 ||!used[xv][yv]){
	    return 0;
	}
	else{
	    return 1;
	}
}
