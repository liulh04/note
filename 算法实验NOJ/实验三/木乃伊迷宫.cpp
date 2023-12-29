#include <iostream>
#include <queue>
using namespace std;
 
struct rec {
	int mx, my;
	int px, py;
	bool useful;
};
queue <rec> q;
int visited[7][7][7][7];
int maze[8][8][2];
int n;//墙的数量
int mstart_x, mstart_y, pstart_x, pstart_y, target_x, target_y;
 
int dx[4] = {0, 1, 0, -1};
 
int dy[4] = {-1, 0, 1, 0};
 
void init() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		maze[x][y][w] = 1;
 
	}
	cin >> mstart_x >> mstart_y;
	cin >> pstart_x >> pstart_y;
	cin >> target_x >> target_y;
}
 
bool iswall(int x, int y, int i) {
	switch (i) {
		case 0://向左走
			return maze[x][y - 1][1];
 
		case 1://向下走
			return maze[x][y][0];
 
		case 2://向右走
			return maze[x][y][1];
 
		case 3://向上走
			return maze[x - 1][y][0];
	}
	return false;
}
 
rec move(rec now, int i) {
	rec next;
	next.px = now.px + dx[i];
	next.py = now.py + dy[i];
	if (next.py < 0 || next.py > 5 || next.px < 0 || next.px > 5 || iswall(now.px, now.py, i)) {
		next.useful = false;
		return next;
	}
	int step = 2;
//	cout << endl;
//	cout << "木乃伊的位置：";
//	cout << now.mx << now.my << endl;
//	cout << "人的位置：";
//	cout << next.px << next.py << endl;
	next.mx = now.mx, next.my = now.my;
	while (step--) {
		if (next.py > next.my && !iswall(next.mx, next.my, 2)) {
			next.my++;
		} else if (next.py < next.my && !iswall(next.mx, next.my, 0)) {
			next.my--;
		} else if (next.py == next.my) {
			if (next.px > next.mx && !iswall(next.mx, next.my, 1)) {
				next.mx++;
			} else if (next.px < next.mx && !iswall(next.mx, next.my, 3)) {
				next.mx--;
			} else if (next.px == next.mx) {
//				cout << next.px << ' ' << next.py << "catch" << endl;
				next.useful = false;
				return next;
			}
		}
	}
	if (visited[next.px][next.py][next.mx][next.my]) {
		next.useful = false;
	} else {
		next.useful = true;
		visited[next.px][next.py][next.mx][next.my] = 1;
	}
	return next;
}
 
bool bfs() {
	rec temp;
	temp.mx = mstart_x, temp.my = mstart_y;
	temp.px = pstart_x, temp.py = pstart_y;
	visited[temp.px][temp.py][temp.mx][temp.my] = 1;
	q.push(temp);
	while (q.size()) {
		rec now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			rec next = move(now, i);
			if (next.useful == true) {
				if (next.px == target_x && next.py == target_y) {
					return true;
				}
				q.push(next);
			}
		}
	}
 
	return false;
}
 
int main() {
	init();
	if (bfs()) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}
