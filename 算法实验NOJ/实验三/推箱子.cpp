#include<iostream>
#include<queue>
 
using namespace std;
 
char map[10][10];
int used[10][10][10][10] = {0};
int step[10][10][10][10];
int rx, ry, bx, by, tx, ty;
 
struct game{
	int rrow;
	int rcol;
	int brow;
	int bcol;
};
 
queue <game> q;
 
void readdata();
void init();
int bfs();
game rgo(game u, int dir);
 
int main(){
    readdata();
	init();
	cout << bfs() << endl;
}
 
void readdata(){
    int i, j;
	for(i = 0; i < 10; i++){
		for(j = 0; j < 10; j++){
		    cin >> map[i][j];
			if(map[i][j] == '4'){
			    rx = i; ry = j;
			}
			if(map[i][j] == '3'){
			    tx = i; ty = j;
			}
			if(map[i][j] == '2'){
			    bx = i; by = j;
			}
		}
	}
}
 
void init(){
    game u;
	u.rrow = rx;
	u.rcol = ry;
	u.brow = bx;
	u.bcol = by;
	q.push(u);
	used[rx][ry][bx][by] = 1;
	step[rx][ry][bx][by] = 0;
}
 
int bfs(){
    game u, v;
	while(!q.empty()){
	    u = q.front();
		q.pop();
		if(u.brow == tx && u.bcol == ty){
		    return(step[u.rrow][u.rcol][u.brow][u.bcol]);
		}
		for(int i = 0; i < 4; i++){
		    v = rgo(u, i);
			if(v.rrow < 0 || v.rrow >=10 || v.rcol < 0 || v.rcol >= 10 || map[v.rrow][v.rcol] == '1'){
			    continue;
			}
			else{
				if(!(v.rrow == v.brow && v.rcol == v.bcol) && !used[v.rrow][v.rcol][v.brow][v.bcol]){
				    q.push(v);
					used[v.rrow][v.rcol][v.brow][v.bcol] = 1;
					step[v.rrow][v.rcol][v.brow][v.bcol] = step[u.rrow][u.rcol][u.brow][u.bcol] + 1;
				}
				else if(v.rrow == v.brow && v.rcol == v.bcol){
					if(i == 0 && !used[v.rrow][v.rcol][v.brow][v.bcol+1] && v.bcol<9 && map[v.brow][v.bcol+1] != '1'){
					    v.bcol = v.bcol + 1;
			            q.push(v);
						used[v.rrow][v.rcol][v.brow][v.bcol] = 1;
					    step[v.rrow][v.rcol][v.brow][v.bcol] = step[u.rrow][u.rcol][u.brow][u.bcol] + 1;
					}
					else if(i == 1 && !used[v.rrow][v.rcol][v.brow+1][v.bcol] && v.brow<9 && map[v.brow+1][v.bcol] != '1'){
					    v.brow = v.brow + 1;
						q.push(v);
						used[v.rrow][v.rcol][v.brow][v.bcol] = 1;
					    step[v.rrow][v.rcol][v.brow][v.bcol] = step[u.rrow][u.rcol][u.brow][u.bcol] + 1;
					}
					else if(i == 2 && !used[v.rrow][v.rcol][v.brow][v.bcol-1] && v.bcol>0 && map[v.brow][v.bcol-1] != '1'){
					    v.bcol = v.bcol - 1;
						q.push(v);
						used[v.rrow][v.rcol][v.brow][v.bcol] = 1;
					    step[v.rrow][v.rcol][v.brow][v.bcol] = step[u.rrow][u.rcol][u.brow][u.bcol] + 1;
					}
					else if(i == 3 && !used[v.rrow][v.rcol][v.brow-1][v.bcol] && v.brow>0 && map[v.brow-1][v.bcol] != '1'){
					    v.brow = v.brow - 1 ;
						q.push(v);
						used[v.rrow][v.rcol][v.brow][v.bcol] = 1;
					    step[v.rrow][v.rcol][v.brow][v.bcol] = step[u.rrow][u.rcol][u.brow][u.bcol] + 1;
					}
				}
			}
		}
	}
	return -1;
}
 
game rgo(game u, int dir){
	int row[4] = {0, 1, 0, -1};
	int col[4] = {1, 0, -1, 0};
	u.rrow += row[dir];
	u.rcol += col[dir];
	return u;
}

