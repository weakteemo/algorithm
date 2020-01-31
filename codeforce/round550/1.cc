#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
int a[27];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		bool isok = 1;
		bool iss = 1;
		memset(a,0,sizeof(a));
		vector<int> v;
		for(int i =0 ; i < s.length(); i++){
			a[s[i]-'a']++;
		}
		for(int i =0; i < 26; i++){
			if(a[i] >=2)isok=0;
		}
		for (int i =0 ; i < 26; i++){
			if(a[i])v.push_back(i);
		}
		sort(all(v));
		for(int i= 0; i < v.size() - 1; i++){
			if(v[i + 1] - v[i] != 1) iss=0;
		}
		if(v.size() == 1) iss= 1;
		if(isok&&iss)cout << "YES" << "\n";
		else cout << "NO" <<"\n";
	}
}