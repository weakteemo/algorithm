#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
int n;
ll ans =2e10;
ll an1,an2;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<ll>v(n);
	for(ll &i : v)cin >> i;
	int lo=0, hi = n - 1;
	while(lo != hi){
		if(abs(v[lo]+v[hi]) <ans){
			ans = abs(v[lo]+v[hi]);
			an1 =v[lo]; an2 = v[hi];
		}
		if(v[lo]+v[hi] < 0)lo++;
		else hi++;
	}
	cout << an1 << " " << an2;
}