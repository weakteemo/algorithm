#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<pi>v(n);
	int ans[1001];
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v[i] = {a,i};
	}
	sort(all(v));
	reverse(all(v));
	for(int i = 0; i < n; i++){
		sum += i*v[i].first;
		ans[v[i].second+1] = i + 1;
	}
	sum += n;
	cout << sum << "\n";
	for (int i = 1; i <= n; i++)cout << ans[i] << " ";
}