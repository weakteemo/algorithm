#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s;
	while(1){
		cin >> s;
		if(s == "end")break;
		stack<char >st;
		int ans = 0;
		bool isok = 1;
		for(int i = 0; i < s.length(); i++){
			if(s[i] == '(' || s[i] == '[') st.push(s[i]);
			else{
				if(st.empty()){
					isok =0 ;
					break;
				}
				if(st.top() != s[i]){
					isok = 0;
					break;
				}
				st.pop();
				ans+=2;
			}
		}
		if(!isok)cout <<0 << "\n";
		
	}
}