#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
int n;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<int> v(n);
	for(int i=0; i < n; i++){
		cin >> v[i];
	}
	sort(all(v));
	set<int >st;
	vector<int> rv;
	for(int i : v){
		if(st.find(i)==st.end())st.insert(i);
		else rv.push_back(i);
	}
	bool isok = 1;
	sort(all(rv));
	if(rv.size() >=2){
		for(int i =0; i < rv.size() - 1; i++){
			if(rv[i] == rv[i + 1] )isok=0;
		}
	}
	if(!isok)cout << "NO";
	else{
		cout << "YES" << "\n";
		cout << st.size() << "\n";
		for(int i : st ) cout << i << " ";
		cout << "\n";
		reverse(rv.begin(),rv.end());
		cout << rv.size() << "\n";
		for(int i : rv)cout << i << " ";
	}
}