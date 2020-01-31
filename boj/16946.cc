#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
int n ,m;
int a[1001][1001];
int check[1001][1001];
int num;
int dlx[4] = {-1,0,1,0};
int dly[4] = {0,1,0,-1};
int tcnt[1000*1000];
int bfs(int x,int y){
	int cnt=0;
	check[x][y] = num;
	queue<pi>q;
	q.push({x,y});
	while(!q.empty()){
		int hx= q.front().first, hy = q.front().second;
		cnt++;
		q.pop();
		for(int i =0 ; i < 4; i++){
			int dx = hx + dlx[i], dy = hy + dly[i];
			if(dx < 0 || dx >= n || dy < 0 || dy>= m) continue;
			if(a[dx][dy] == 0 && check[dx][dy] == 0){
				check[dx][dy] = num;
				q.push({dx,dy});
			}
		}
	}
	return cnt;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i= 0;  i< n ; i++){
		string s;
		cin >> s;
		for(int j =0; j < m; j++){
			a[i][j]= s[j]-'0';
		}
	}
	for (int i =0; i<n ; i++){
		for(int j =0; j < m; j++){
			if(check[i][j]==0 && a[i][j]==0){
				num++;
				tcnt[num]=bfs(i,j);
			}
		}
	}
	for (int i =0; i < n; i++){
		for(int j =0; j < m; j++){
			if(a[i][j]== 1){
				set<int> st;
				int ans =1;
				for(int k=0; k < 4; k++){
					int dx = i + dlx[k], dy = j + dly[k];
					if(dx < 0 || dx >= n || dy < 0 || dy>= m) continue;
					st.insert(check[dx][dy]);
				}
				for(int l :st){
					ans += tcnt[l];
				}
				cout << (ans==0? 0 : ans%10);
			}
			else cout <<0;
		}
		cout << "\n";
	}
}