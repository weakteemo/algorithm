#include <bits/stdc++.h>
#include <iostream>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
int t, n;
int a[2001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >>t;
	while(t--){
		cin >> n;
		int ocnt= 0;
		for(int i=0; i < n; i++){
			cin >> a[i];
			if(a[i]&1)ocnt++;
		}
		if(ocnt >= 1 && ocnt < n)cout <<"YES"<<"\n";
		else if(ocnt ==n && n%2==1)cout << "YES" << "\n";
		else cout << "NO" <<"\n";
	}
}