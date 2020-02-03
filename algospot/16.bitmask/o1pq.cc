/* 1~140의 우선순위를 가지는 element들을 n개 입력
priority_queue로 관리
push나 pop연산을 수행할수 있다.
ll(64bit) 3개로 수행, 메모리를 bool[140](140 byte) -> 3*ll(24byte)로 절약하는 것이 목표
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef unsigned long long ll;
int n;
ll pq[3];
const ll MAX = 64;
int main() {
	cin >> n;
	// input query q (1 push(x== element) 2 top 3 pop 4 empty 5 size
	for (int i = 0; i < n; i++) {
		int q, x;
		cin >> q;
		if (q == 1) {
			cin >> x;
			pq[x / MAX] |= ((ll)1 << (x%MAX));
			cout << ((ll)1 << (x%MAX));
			cout << __builtin_clzl(((ll)1 << (x%MAX)));
			cout << x/MAX << " " << x%MAX << "\n";
		}
		if (q == 2) {
			for (int i = 2; i >= 0; i--) {
				if (!pq[i])continue;
				else {
					cout << i;
					cout << i * MAX + __builtin_clzl(pq[i]) << "\n";
					break;
				}
			}
		}
		if (q == 3) {
			for (int i = 2; i >= 0; i--) {
				if (!pq[i])continue;
				else {
					pq[i] &= ~((ll)1 << __builtin_clzl(pq[i]));
				}
			}
		}
		if (q == 4) {
			for (int i = 0; i < 3; i++) {
				if (pq[i]) {
					cout << 0 << "\n";
					break;
				}
				if (i == 2)cout << 1 << "\n";
			}
		}
		if (q == 5) {
			int tmp = 0;
			for (int i = 0; i < 2; i++) {
				tmp += __builtin_popcountl(pq[i]);
			}
			cout << tmp << "\n";
		}
	}
}