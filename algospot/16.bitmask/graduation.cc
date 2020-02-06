#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
int t,n,m,k,l,o;
int ans;
const int INF = 123456789;
int classes[11], pre[11];
int dp[11][1<<11];
int rec(int ind, int now){
	if(__builtin_popcount(now)>=k)return 0;
	if(ind ==m )return INF;
	int& ret = dp[ind][now];
	if(ret != -1)return ret;
	ret = INF;
	int cantake = (classes[ind] & ~now);
	for(int i =0; i < n; i++){
		if((cantake&(1<<i)) && (now&pre[i]) != pre[i]) cantake &= ~(1<<i);
	}
	for(int i = cantake; i; i = (i - 1)&cantake){
		if(__builtin_popcount(i) > l)continue;
		ret = min(ret, rec(ind+1, i|now) + 1);
	}
	ret = min(ret, rec(ind+1,now));
	return ret;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while(t--){
		cin >> n >>  k >> m >> l;
		memset(dp,0,sizeof(dp));
		for(int i =0; i < n; i++){
			int num;
			cin >> num;
			for(int j =0; j < num; j++){
				cin >> o;
				pre[i] |= (1<<o);
			}
		}
		for(int i =0; i < m; i++){
			int num;
			cin >> num;
			for(int j= 0; j < num; j++){
				cin >> o;
				classes[j] |= (1<<o);
			}
		}
		if(rec(0,0) == INF)cout << "IMPOSSIBLE" <<"\n";
		else cout << rec(0,0) << "\n";
	}
}