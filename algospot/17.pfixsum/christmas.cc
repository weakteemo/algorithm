#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
int t, n, x;
const int MOD = 20091001;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> x;
		vector<vector<int>> v(x);//나머지가같은것끼리
		vector<pi> q2;// 2번째쿼리 처리
		int psum = 0;
		for (int i = 0; i < n; i++) {
			int iti;
			cin >> iti;
			psum += iti;
			v[psum%x].push_back(i);
		}
		// query 1
		ll an1 = 0;
		int an2 = 0; // for query2
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < v[i].size(); j++) {
				if (j + 1 < v[i].size())q2.push_back({ v[i][j + 1],v[i][j] });
			}
			ll vs = v[i].size();
			an1 = (an1 + vs * (vs - 1) / 2) % MOD;
		}
		sort(all(q2));
		if (q2.size()) {
			int hi = -1;
			for (auto i : q2) {
				if (i.second > hi) {
					hi = i.first;
					an2++;
				}
			}
		}
		cout << an1 << " " << an2 << "\n";
	}
}
