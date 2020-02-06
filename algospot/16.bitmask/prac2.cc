#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
int taken =21;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for(int i = taken; i; i = (i - 1)&(taken)){
		cout << i << " ";
	}
}