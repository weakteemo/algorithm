#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
char arr[9][9];
bool check[9][9][10];
int dlx[9] = { -1,-1,-1,0,0,0,1,1,1 };
int dly[9] = { -1,0,1,-1,0,1,-1,0,1 };
int bfs() {
	queue<pair<pair<int, int>, int>>q;
	check[7][0][0] = 1;
	q.push({ {7,0},0 });
	while (!q.empty()) {
		int hx = q.front().first.first, hy = q.front().first.second, hs = q.front().second;
		q.pop();
		if (hx - hs >= 0) {
			if (arr[hx - hs][hy] == '#')continue;
		}
		if ((hx == 0 && hy == 7) || hs >= 9)return 1;
		for (int i = 0; i < 9; i++) {
			int dx = hx + dlx[i];
			int dy = hy + dly[i];
			if (dx < 0 || dx > 7 || dy < 0 || dy > 7)continue;
			if (dx - hs >= 0) {
				if (arr[dx - hs][dy] == '#')continue;
			}
			check[dx][dy][hs + 1] = 1;
			q.push({ {dx,dy},hs + 1 });
		}
	}
	return 0;
}
int main() {
	for (int i = 0; i < 8; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < 8; j++) {
			arr[i][j] = s[j];
		}
	}
	cout << bfs();
}