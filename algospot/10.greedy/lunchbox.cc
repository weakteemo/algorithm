#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
int t, n;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		vector<int>a(n);vector<int>b(n);
		int suma=0, sumb=0;
		int minb=1e9+3;
		for(int &i : a){
			cin>>i;
			suma +=i;
		}
		for(int &i : b){
			cin>>i;
			sumb += i;
			minb=min(i,minb);
		}
		cout <<minb+suma<< "\n";
	}
}
