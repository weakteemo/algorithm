#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
int t, n, x;
const ll MOD = 20091101;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> x;
		vector< vector< int > > v;
		vector<pi> q2;
		v.resize(x);
		v[0].push_back(0);
		ll psum = 0;
		ll an1 = 0, an2 = 0;
		for (int i = 0; i < n; i++) {
			int iti;
			cin >> iti;
			psum += iti;
			v[psum%x].push_back(i + 1);
		}
		for (int i = 0; i < x; i++) {
			ll vs = v[i].size();
			if (vs >= 2)an1 = (an1 + (vs*(vs - 1) / 2)) % MOD;
			for (int j = 0; j < v[i].size(); j++) {
				if (j < vs -1) {
					q2.push_back({ v[i][j + 1],v[i][j] });
				}
			}
		}
		sort(all(q2));
		int hi = -1;
		for (int i = 0; i < q2.size(); i++) {
			if (q2[i].second >= hi) {
				hi = q2[i].first;
				an2++;
			}
		}
		cout << an1 << " " << an2 << "\n";
	}
}