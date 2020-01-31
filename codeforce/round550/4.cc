#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
int n;
struct an {
	int x, y, z;
	an(int a, int b, int c) { x = a; y = b; z = c; }
};
vector<an> ansv;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<ll>v(n);
	map<ll, ll> mp;
	for (int i = 0; i < n; i++) {
		ll iti;
		cin >> iti;
		v[i] = iti;
		if (mp.find(iti) == mp.end())mp.insert({ iti,1 });
		else mp[iti]++;
	}
	ll maxt = 0;
	ll mval = 0;
	for (auto i : mp) {
		if (i.second > maxt) {
			maxt = i.second;
			mval = i.first;
		}
	}
	int ind = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] == mval) {
			ind = i;
			break;
		}
	}
	//
	for (int i = ind - 1; i >= 0; i--) {
		if (v[i] == mval)continue;
		else if (v[i] < mval) ansv.push_back(an(1, i + 1, i + 2));
		else ansv.push_back(an(2, i + 1, i + 2));
	}
	for (int i = ind + 1; i < n; i++) {
		if (v[i] == mval)continue;
		else if (v[i] < mval) ansv.push_back(an(1, i + 1, i));
		else ansv.push_back(an(2, i + 1, i));
	}
	cout << ansv.size() << "\n";
	for (auto i : ansv) {
		cout << i.x << " " << i.y << " " << i.z << "\n";
	}
}