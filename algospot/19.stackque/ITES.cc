#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
int t,n,k;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while(t--){
		cin >> k >> n;
		ll ans = 0;
		queue<int> q; int psum=0;
		for(int i =0; i < n; i++){
			unsigned a;
			if(i==0)a = 1983;
			else a=a *214013u+2531011u;
			int now = a%10000 + 1;
			q.push(now);
			psum += now;
			while(psum > k){
				psum -= q.front();
				q.pop();
			}
			if(psum == k)ans++;
		}
		cout << ans << "\n";
	}
}