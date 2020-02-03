#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
int t, n;
int ispos[300001];
int isppos[300001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		memset(ispos, 0, sizeof(ispos));
		memset(isppos, 0, sizeof(isppos));
		vector<int>v(n);
		for (int i = 0; i < n; i++)cin >> v[i];
		bool isok = 0;
		for (int i = 0; i < n; i++) {
			if (v[i] >= i)ispos[i] = 1;
			else {
				break;
			}
		}
		for (int i= n - 1; i>=0; i--){
			if(v[i] >= n - i - 1) isppos[i] = 1;
			else break;
		}
		for (int i =0; i < n; i++){
			if(max(i,n-i-1) <= v[i]){
				bool sw1= 1,sw2 =1;
				if(i>=1)if(!ispos[i-1])sw1=0;
				if(i<n-1)if(!ispos[i+1])sw2=0;
				if(sw1&&sw2)isok=1;
			}
		}
		if (isok)cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
}