#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
int t,n;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		vector<int> v(n);
		priority_queue<int> pq;
		for(int &i: v){
			cin>>i;
			pq.push(-i);
		}
		int ans = 0;
		while(pq.size()!=1){
			int a= -pq.top(); pq.pop(); int b = -pq.top(); pq.pop();
			ans += (a+b);
			pq.push(-a-b);
		}
		cout << ans<<"\n";
	}
}