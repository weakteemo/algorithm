#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
int n , m;
char a[51][51];
int wdist[51][51];
int gdist[51][51];
int stx, sty, dtx, dty;
int dlx[4] = {-1,0,1,0};
int dly[4] = {0, 1, 0, -1};
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	memset(wdist, -1,sizeof(wdist));
	memset(gdist, -1,sizeof(gdist));
	queue<pi> q;
	for(int i=0; i <n ;i++){
		string s;
		cin >> s;
		for(int j =0; j <m ; j++){
			a[i][j] = s[j];
			if(a[i][j] == 'S')stx = i, sty =j;
			if(a[i][j] == 'D')dtx = i, dty= j;
			if(a[i][j] == '*'){
				q.push({i,j});
				wdist[i][j]=0;
			}
		}
	}
	while(!q.empty()){
		int hx = q.front().first, hy = q.front().second;
		q.pop();
		for(int i =0;  i< 4; i++){
			int dx = hx + dlx[i];
			int dy = hy + dly[i];
			if(dx < 0 || dx >= n || dy < 0 || dy >= m)continue;
			if((a[dx][dy] == '.'||a[dx][dy] == 'S') && wdist[dx][dy] ==-1){
				wdist[dx][dy] = wdist[hx][hy] + 1;
				q.push({dx,dy});
			}
		}
	}
	gdist[stx][sty] = 0;
	q.push({stx,sty});
	while(!q.empty()){
		int hx = q.front().first, hy = q.front().second;
		q.pop();
		for(int i =0;  i< 4; i++){
			int dx = hx + dlx[i];
			int dy = hy + dly[i];
			if(dx < 0 || dx >= n || dy < 0 || dy >= m)continue;
			if((a[dx][dy] == '.'||a[dx][dy] == 'D') && gdist[dx][dy] ==-1 &&(wdist[dx][dy] == -1 || gdist[hx][hy] + 1 < wdist[dx][dy])){
				gdist[dx][dy] = gdist[hx][hy] + 1;
				q.push({dx,dy});
			}
		}
	}
	/*for(int i =0; i < n; i++){
		for(int j= 0; j < m; j++){
			cout << gdist[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
	/*for(int i =0; i < n; i++){
		for(int j= 0; j < m; j++){
			cout << wdist[i][j];
		}
		cout << "\n";
	}*/
	if(gdist[dtx][dty] == -1) cout << "KAKTUS"<< "\n";
	else cout << gdist[dtx][dty]; 
}