#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
int t,n,m,k;
int a[3501];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while(t--){
		cin >> n >> m >> k;
		m--;
		m -=k;
		int ans = -1;
		for(int i=0; i < n; i++)cin>>a[i];
		int len = n - k;
		int len2 = len - m;
		for(int i =0; i <= n-len; i++){
			int minval = 123456789;
			for(int j = 0; j <= len-len2; j++){
				minval = min(minval, max(a[i+j],a[i+j+len2-1]));
			}
			ans =max(ans,minval);
		}
		cout << ans << "\n";
	}
}