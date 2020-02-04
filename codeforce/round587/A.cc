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
	string s;
	cin >> s;
	int ans= 0;
	for(int i =0; i < s.length(); i+=2){
		if(s[i] == 'a' && s[i+1] == 'b')continue;
		if(s[i] == 'b' && s[i+1] == 'a')continue;
		ans++;
		s[i] = 'a';s[i + 1] = 'b';
	}
	cout << ans << "\n";
	cout << s;
}