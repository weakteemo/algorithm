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
	vector<int> odd;
	vector<int> even;
	for (int i = 0; i < n; i++) {
		int iti;
		cin >> iti;
		if (iti % 2) odd.push_back(iti);
		else even.push_back(iti);
	}
	int mcnt = min(even.size(), odd.size()) + 1;
	sort(all(odd));
	sort(all(even));
	int ans = 0;
	for (int i = 0; i < max(0,(int)odd.size() - mcnt); i++) ans += odd[i];
	for (int i = 0; i < max(0,(int)even.size() - mcnt); i++) ans += even[i];
	cout << ans;
}