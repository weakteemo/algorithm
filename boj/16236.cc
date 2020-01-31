#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
int check[21][21][7][7];
int a[21][21];
int dlx[4] = {-1,0,0,1};
int dly[4] = {0,-1,1,0};
int ans = 0;
struct info{
	int x,y,siz,scnt;
	info(int a,int b,int c,int d){x=a; y=b;siz=c;scnt=d;}
};
int n;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	queue<info> q;
	for(int i =0 ; i < n; i++){
		for(int j =0; j < n; j++){
			cin >> a[i][j];
			if(a[i][j] == 9) {
				q.push(info(i,j,2,0));
				check[i][j][2][0] = 1;
			}
		}
	}
	while(!q.empty()){
		auto now = q.front();
		int hdist = check[now.x][now.y][now.siz][now.scnt];
		cout << now.x << " "<<now.y << " " << now.siz << " "<< now.scnt <<"\n";
		q.pop();
		for(int i =0; i< 4; i++){
			int dx = now.x+dlx[i];
			int dy = now.y+dly[i];
			int dsiz = now.siz;
			int dcnt = now.scnt;
			if(dx < 0 || dx >= n || dy < 0 || dy >= n)continue;
			if(check[dx][dy][dsiz][dcnt]==0 || chej[]){
				if(a[dx][dy] == 0 || a[dx][dy] ==dsiz){
					check[dx][dy][dsiz][dcnt] = hdist + 1;
					q.push(info(dx,dy,dsiz,dcnt));
				}
				else if(a[dx][dy] < dsiz){
					a[dx][dy] = 0;
					ans = max(ans,hdist);
					dcnt++;
					if(dcnt == dsiz){
						dsiz++;
						dcnt=0;
					}
					check[dx][dy][dsiz][dcnt] = hdist+1;
					q.push(info(dx,dy,dsiz,dcnt));
				}
			}
		}
	}
	cout << ans;
}