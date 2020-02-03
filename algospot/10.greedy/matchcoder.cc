#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
int t,n, ans;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		vector<int> a(n), b(n);
		for(int &i : a ) cin >> i;
		for(int &i : b ) cin >> i;
		sort(all(a));
		sort(all(b));
		ans=  0;
		int ap=0, bp=0;
		while(bp < n){
			if(a[ap]<= b[bp]){
				ans++;
				ap++; bp++;
			}
			else{
				bp++;
			}
		}
		cout << ans << "\n";
	}
}