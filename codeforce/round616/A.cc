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
		string s;
		cin >> s;
		int ocnt=0;
		vector<int> ans;
		for(int i=0; i < s.length(); i++){
			if((s[i]-'0')&1) {
				ocnt++;
				ans.push_back(s[i]-'0');
			}
			if(ocnt==2)break;
		}
		if(ocnt != 2) cout <<-1 << "\n";
		else {
			for(int i : ans ) cout << i;
			cout << "\n";
		}
	}
}