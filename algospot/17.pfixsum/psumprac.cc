// 정수의 범위를 가지는 n개의 원소를 가진 배열이 주어질때,
// 0에가장 가까운 범위를 가지는 구간을 구하시오
#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<pi> psum(n);
	for (int i = 0; i < n; i++) {
		int iti;
		cin >> iti;
		if (i == 0)psum[i] = { iti,i };
		else psum[i] = { psum[i - 1].first + iti, i };
	}
	// 부분의 구간을 정렬 
	sort(all(psum));
	int minval = 123456789;
	int an1, an2;
	// psum[i] - psum[i-1]만확인하면 된다 왜??
	// 차이가 가장 작은구간을 찾아야하기 때문, 정렬된 상태의psum[i] - psum[i - 1]보다 더 작은 차이를 가지는 구간이. 존재하지않는다.(그리디적인 풀이, 귀류법으로 증명가능)
	for (int i = 1; i < psum.size(); i++) {
		if (psum[i].first - psum[i - 1].first < minval) {
			minval = psum[i].first - psum[i - 1].first;
			an1 = psum[i].second, an2 = psum[i - 1].second;
		}
	}
	cout << an1 << " " << an2;
}