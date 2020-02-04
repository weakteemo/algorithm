/*먹는 시간이 가장 긴 것을 가장 먼저 먹기 시작해야(데워야) 
*/
#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
int a[10001], b[10001];
int t, n;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<pi>v(n);
		for(auto&i : v)cin >> i.second;
		for(auto&i : v)cin >> i.first;
		sort(all(v));
		reverse(all(v));
		int ret= 0,suma=0;
		for(auto i : v){
			suma += i.second;
			ret =max(ret,suma+i.first);
		}
		cout << ret << "\n";
	}
}
