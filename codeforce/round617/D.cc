#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
int n, a, b, x;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> a >> b >> x;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int iti;
		cin >> iti;
		iti = (iti % (a + b));
		if (iti == 0) iti = (a + b);
		v.push_back(iti);
	}
	for (int i : v)cout << v[i] << " ";
	cout << "\n";
	for (int i : v) v[i] = (v[i] - 0.1 / a);
	for (int i : v) cout << v[i] << " ";
}