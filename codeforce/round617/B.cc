#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int ans= 0;
		int now = n;
		while(now<10){
			now = (int)((double)now/10+0.5);
			ans += now;
		}
		cout << ans << "\n";
	}
}