#include <iostream>
using namespace std;

struct TNode
{
	int inf;
	TNode* a;
};
struct stack {
	TNode* top = nullptr;
	int size = 0;
	bool empty() {
		if (top) return false;
		else return true;
	}

	void push(int inf) {
		TNode* spt = new TNode;
		spt->inf = inf;
		spt->a = top;
		top = spt;
	}
	void pop() {
		TNode* spt = top;
		top = top -> a;
		delete spt;
		size--;
	}
	void print() {
		TNode* spt = top;
		while (spt != nullptr) {
			cout << spt->inf << " ";
			spt = spt->a;
		}
	}
	TNode* search(int x) {
		if (!top)return nullptr;
		TNode* spt = top;
		while (spt->inf != x && spt->a != nullptr)spt = spt->a;
		if (spt->inf == x)return spt;
		else return nullptr;
	}
	TNode* searchp(int x) {
		if (!top || !top->a) return nullptr;
		TNode* spt = top;
		while (spt->a->inf != x && spt->a->a != nullptr)spt = spt->a;
		if (spt->a->inf == x)return spt;
		return nullptr;
	}
	void del(int x) {
		if (!top) return;
		if (top->inf == x) { pop(); return; }
		TNode* spt, * spp;
		spp = searchp(x);
		spt = spp->a;
		spp->a = spp->a->a;
		delete spt;
	}


};
int main() {
	TNode* spt;
	stack s;
	double sum = 0;
	int mas[] = { 1, 7, 3, 4, 5, 6,2 };
	for (int i = 0; i < 7; i++) {
		s.push(mas[i]);
	}
	spt = s.top;
	for (int i = 0; i < 7; i++) {
		sum += spt->inf;
		spt = spt->a;
	}
	sum /= 7;
	cout << sum << endl;
	spt = s.top;

	while (spt) {
		if (spt->inf < sum) {
			TNode* sp = spt->a;
			s.del(spt->inf);
			spt = sp;
		}
		else spt = spt->a;
	}
	spt = s.top;
	s.print();
	while (!s.empty()) s.pop();
	return 0;
}