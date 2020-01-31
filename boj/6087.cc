#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
char a[103][103];
int check[103][103];
int dlx[4] = { -1,0,1,0 };
int dly[4] = { 0, 1,0, -1 };
queue<pair<int, int>> q;
int n, m;
int bfs() {
	while (!q.empty()) {
		int hx = q.front().first, hy = q.front().second;
		if (a[hx][hy] == 'C') return check[hx][hy]-2;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int dx = hx, dy = hy;
			while (1) {
				dx += dlx[i], dy += dly[i];
				if (dx < 0 || dx >= n || dy < 0 || dy >= m)break;
				else if(a[dx][dy] == '*')break;
				else if(check[dx][dy] == 0){
					check[dx][dy]= check[hx][hy] + 1;
					q.push({dx,dy});
				}
			}
		}
	}
}
int main() {
	cin >> m >> n;
	int isin = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			a[i][j] = s[j];
			if (a[i][j] == 'C' && isin == 0) {
				q.push({ i,j });
				a[i][j] = '.';
				check[i][j] = 1;
				isin++;
			}
		}
	}
	cout << bfs();
}