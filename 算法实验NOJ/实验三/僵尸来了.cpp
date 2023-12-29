#include <iostream>
#include <queue>
using namespace std;
 
struct rec {
	int x, y;//僵尸当前坐标
	bool useful;//该状态是否有效
	int t;//僵尸当前生命值
	int step;//僵尸当前步数
};
queue<rec> q;
rec st, ed;
char maze[201][201];//地图
int visited[201][201][10];
int m, n, t;
 
int dx[4] = {0, 0, -1, 1};//左右上下四个方向
int dy[4] = {-1, 1, 0, 0};
 
void init() {
	cin >> m >> n >> t;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> maze[i][j];
			if (maze[i][j] == '!') {//僵尸出发点
				st.x = i, st.y = j;
			}
			if (maze[i][j] == '+') {//目标位置
				ed.x = i, ed.y = j;
			}
		}
	}
	st.t = t;
	st.step = 0;
}
 
rec moveto(rec now, int i) {
	rec next;
	next.x = now.x + dx[i];
	next.y = now.y + dy[i];
	if (next.x < 0 || next.x >= m || next.y < 0 || next.y >= n) {
		next.useful = false;
		return next;
	}
	if (maze[next.x][next.y] == 'w') {//如果遇到地刺
		next.t = now.t - 1;
	} else if (maze[next.x][next.y] != 'w') {//如果遇到非地刺
		next.t = now.t;
	}
	if (next.t <= 0) {//僵尸体力值为0， 僵尸死亡
		next.useful = false;
		return next;
	}
	next.useful = true;
	return next;
 
}
 
int bfs() {
	q.push(st);
	while (q.size()) {
		rec now = q.front();
		if (now.x == ed.x && now.y == ed.y) {//到达目标
			return now.step;//返回最小步数
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			rec next = moveto(now, i);
			if (next.useful == true && !visited[next.x][next.y][next.t]) {
				visited[next.x][next.y][next.t] = 1;
				next.step = now.step + 1;
				q.push(next);
			}
		}
	}
	return -1;//不能到达
}
 
int main() {
	init();
	int ans = bfs();
	cout << ans << endl;
	return 0;
}
