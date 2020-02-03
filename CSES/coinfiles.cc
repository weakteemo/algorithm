#include <iostream>
using namespace std;
int t,a,b;
int main(){
	cin >> t;
	while(t--){
		cin >> a >> b;
		bool isok=0;
		int diff =abs(a-b);
		a %= 3; b %= 3;
		if(diff==0 && (a==0&&b==0))isok=1;
		if(diff==1&&((a==1&&b==2)||(a==2&&b==1)))isok=1;
		cout << (isok ? "YES" : "NO") << "\n";
	}
}