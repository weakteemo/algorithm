#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),v.end()
using namespace std;
using ll = long long;
using pi = pair<double,double>;
# define PI          3.141592653589793238462643383279502884L
int t,n;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		bool ispos =1;
		vector<pi> v(n);// hi lo
		vector<int> check(n);
		for(int i =0; i < n; i++){
			double a,b,r, lo, hi;
			double tmp = 0;
			cin >> a >> b>> r;
			if(a<0)tmp= PI;
			lo = acos(b/8)-acos(4/r)+tmp;
			hi = acos(b/8)+acos(4/r)+tmp;
			lo *= ((double)180/PI);
			hi *= ((double)180/PI);
			if(r > 16) ispos=0;
			cout << lo << " " << hi << "\n";
			v[i] = {hi,lo};
		}
		if(!ispos)cout<<"IMPOSSIBLE"<<"\n";
		else{
			sort(all(v));
			reverse(all(v));
			for(auto i : v){
				cout << i.second << " " <<i.first << "\n";
			}
		}
	}
}