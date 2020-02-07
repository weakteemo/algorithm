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
		int x = 0, y= 0;
		map<pi,int> mp;
		int mindist = 123456789;
		int l = -1, r=  -1;
		mp[{0,0}] = 0;
		for(int i =0; i < s.length(); i++){
			if(s[i] == 'L') y--;
			if(s[i] == 'R') y++;
			if(s[i] == 'U') x--;
			if(s[i] == 'D') x++;
			if(mp.count(make_pair(x,y))){
				if(mindist > i -mp[{x,y}]){
					l = mp[{x,y}], r = i;
					mindist = r-l;
				}
			}
			mp[{x,y}]=i+ 1;
		}
		if(l == -1)cout << -1 << "\n";
		else cout << l+1 << " " << r+1 << "\n";
	}
}