#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
int t,n,m,k,l;
vector<vector<int>> pre;
vector<vector<int>> semester;
int ans;
bool valcheck(int x){
	
}
void dfs(int ind, int now){
	for(int i =0; i < (1<<semester[ind].size()); i++){
		int next =0;
		for(int j =0; j < semester[ind].size(); j++){
			if(i&(1<<j)){
				int nval = semester[ind][j];
				
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while(t--){
		cin >> n >>  k >> m >> l;
		ans =9999;
		pre.clear(); semester.clear(); pre.resize(n); semester.resize(m);
		for(int i=0; i <n ; i++){
			int val;
			cin >> val;
			for(int j =0 ; j < val; j++){
				int pval;
				cin >> pval;
				pre[i].push_back(pval);	
			}
		}
		for (int i =0; i < m; i++){
			int val;
			cin >> val;
			for(int j =0; j < val; j++){
				int pval;
				cin >> pval;
				semester[i].push_back(pval);
			}
		}		
	}
}