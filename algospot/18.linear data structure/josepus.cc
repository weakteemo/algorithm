#include <iostream>
#include <algorithm>
using namespace std;
int t, n, x;
struct Node{
	int elem;
	Node* next; Node* prev;
	Node(int x){this->elem = x;};
};
Node* delNode(Node* now){
	now->prev->next = now->next;
	now->next->prev = now->prev;
	return now->next;
};
Node* trev(Node* node){
	cout << node->elem << "\n";
	return node->next;
}
int main(){
	cin >> t;
	while(t--){
		cin >> n >> x;
		Node* now = new Node(1);
		Node* fir = now;
		for(int i = 1; i < n; i++){
			Node* node = new Node(i+1);
			now->next = node;
			node->prev = now;
			now = node;
			if(i == n - 1){
				now->next = fir;
				fir->prev = now;
				now = now->next;
			}
		}
		/*for(int i =0; i < n; i++){
			now = trev(now);
		}*/
		for (int  i=0; i < n - 2; i++){
			now =delNode(now);
			for(int j = 0; j < x - 1; j++)now = now->next;
		}
		cout << min(now->elem,now->next->elem) << " " <<max(now->elem,now->next->elem) << "\n";
	}	
}