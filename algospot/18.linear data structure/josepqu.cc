#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
int t,n,x;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while(t--){
		cin >> n >> x;
		queue<int> q;
		for(int i = 1; i <= n;i++)q.push(i);
		for(int i=0; i < n -2; i++){
			q.pop();
			for(int j =0; j < x - 1; j++){
				q.push(q.front());
				q.pop();
			}
		}
		int n1 = q.front(); q.pop();
		int n2 = q.front();
		cout << min(n1,n2) << " "<<max(n1,n2) << "\n";
	}
}