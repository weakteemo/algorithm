#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
int dlx[5] = { 0,-1,1,0,0 };
int dly[5] = { 0,0, 0, 1, -1 };
int r, c, m;
int ans;
struct info {
	int speed, dir, siz, tag;
	info(int c, int d, int e, int f) {
		speed = c; dir = d; siz = e; tag = f;
	};
	bool operator<(const info& w) const {
		return siz < w.siz;
	};
};
vector<info> v[101][101];
bool isalive[10001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> r >> c >> m;
	for (int i = 0; i < 10001; i++)isalive[i] = 1;
	for (int i = 0; i < m; i++) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		v[a][b].push_back(info(c, d, e, i));
	}
	for (int i = 1; i <= c; i++) {
		vector<info> rv[101][101];
		// 상어잡기
		bool isb = 0;
		for (int j = 1; j <= r; j++) {
			if (!v[j][i].empty()) {
				for (auto wt : v[j][i]) {
					if (isalive[wt.tag]) {
						ans += wt.siz;
						isalive[wt.tag] = 0;
						isb = 1;
						break;
					}
				}
				if (isb)break;
			}
		}
		// move of shark to v - > rv (ignore erased shark at this stage)
		for (int j = 1; j <= r; j++) {
			for (int k = 1; k <= c; k++) {
				for (auto l : v[j][k]) {
					if (isalive[l.tag]) {
						int nx = j, ny = k;
						if (l.dir >= 3) {
							if (l.dir == 3)ny += l.speed;
							else ny -= l.speed;
							while (ny > c || ny < 1) {
								if (ny > c) ny = 2 * c - ny, l.dir = 4;
								if (ny < 1) ny = 2 - ny, l.dir = 3;
							}
						}
						else {
							if (l.dir == 1) nx -= l.speed;
							else nx += l.speed;
							while (nx > r || nx < 1) {
								if (nx > r) nx = 2 * r - nx, l.dir = 1;
								if (nx < 1) nx = 2 - nx, l.dir = 0;
							}
						}
						rv[nx][ny].push_back(l);
					}
				}
			}
		}
		// watch rv and erase shark at same space
		for (int j = 1; j <= r; j++) {
			for (int k = 1; k <= c; k++) {
				int msiz = -1;
				for (int l = 0; l < rv[j][k].size(); l++) {
					if (rv[j][k][l].siz > msiz) msiz = rv[j][k][l].siz;
				}
				for (int l = 0; l < rv[j][k].size(); l++) {
					if (rv[j][k][l].siz != msiz) isalive[rv[j][k][l].tag] = 0;
				}
			}
		}
		//rv -> v 
		swap(rv, v);
	}
	cout << ans;
}