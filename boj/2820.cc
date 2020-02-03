#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const int MAX = 2000001;
int n, m;
ll seg[MAX], sn[500001], en[500001], prop[MAX], Q[500001];
int tsiz;
int n_num = 0;
vector<vector<int>> vt;
void prop_update(ll s, ll e, ll ind) {
	if (prop[ind]) {
		seg[ind] += (e - s + 1) * prop[ind];
		if (s != e) {
			prop[ind * 2] += prop[ind];
			prop[ind * 2 + 1] += prop[ind];
		}
		prop[ind] = 0;
	}
}
void update(ll s, ll e, ll ind, ll pval, ll L, ll R) {
	prop_update(L, R, ind);
	if (L >= s && R <= e) {
		seg[ind] += (R - L + 1)*pval;
		if (L != R) {
			prop[ind * 2] += pval;
			prop[ind * 2 + 1] += pval;
		}
		return;
	}
	else if (s > R || e < L) return;
	update(s, e, ind * 2, pval, L, (L + R) / 2);
	update(s, e, ind * 2 + 1, pval, (L + R) / 2 + 1, R);
	seg[ind] = seg[ind * 2] + seg[ind * 2 + 1];
}
void dfs(int i) {
	sn[i] = ++n_num;
	for (int V : vt[i]) {
		if (!sn[V])dfs(V);
	}
	en[i] = n_num;
}
ll Qu(ll s, ll e, ll ind, ll L, ll R) {
	prop_update(L, R, ind);
	if (L >= s && R <= e)return seg[ind];
	else if (R < s || L > e)return 0;
	return Qu(s, e, ind * 2, L, (L + R) / 2) + Qu(s, e, ind * 2 + 1, (L + R) / 2 + 1, R);
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	vt.resize(n + 1);
	tsiz = ceil(log2(n));
	tsiz = 1 << tsiz;
	for (int i = 0; i < n; i++) {
		int  b;
		if (i == 0) {
			cin >> Q[i];
		}
		else {
			cin >> Q[i] >> b;
			vt[b].push_back(i + 1);
		}
	}
	dfs(1);
	for (int i = 1; i <= n; i++)update(sn[i], sn[i], 1, Q[i - 1], 1, n);
	for (int i = 0; i < m; i++) {
		char c;
		cin >> c;
		ll a, b;
		if (c == 'p') {
			cin >> a >> b;
			update(sn[a]+1, en[a], 1, b, 1, n);
		}
		else {
			cin >> a;
			cout << Qu(sn[a], sn[a], 1, 1, n) << "\n";
		}
	}
}