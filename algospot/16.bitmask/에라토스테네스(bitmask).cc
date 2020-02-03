//https://m.blog.naver.com/PostView.nhn?blogId=occidere&logNo=220973318428&proxyReferer=https%3A%2F%2Fwww.google.com%2F
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_N = (1<<16);
int n;
unsigned char sieve[(MAX_N + 7)/ 8];
// k가 소수인지 확인
// /8, %8
inline bool isPrime(int k){
	return sieve[k>>3]&(1<<(k&7));
}
// k가 소수가 아니라고 표시
inline void setComposite(int k){ 
	sieve[k>>3] &= ~(1 << (k&7));
}
// 비트마스크를 사용하는 에라토스테네스 체의 구현
// 이 함수 실행 뒤, isPrime()을 이용해 각 수가 없습니다.
void eratosthenes(){
	setComposite(0);
	setComposite(1);
	//for(int i = 2; i* i <= n; i++){
		
	//}
}
