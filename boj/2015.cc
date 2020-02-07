#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
int n , k;
map<ll,ll>mp;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	ll ans = 0;
	ll psum=0;
	mp[0]=1;
	for(int i =0; i < n; i++){
		ll iti;
		cin >> iti;
		psum += iti;
		ll tf = psum-k;
		if(mp.count(tf)) ans +=mp[tf];
		if(mp.count(psum))mp[psum]++;
		else mp[psum] = 1;
	}
	cout << ans;
}