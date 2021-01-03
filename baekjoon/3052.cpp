#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int main() {
	map <int, int> m;
	int value;
	for (int i = 0; i < 10; i++) {
		scanf("%d", &value);
		m[value % 42] = 1;
	}
	printf("%d\n", m.size());
}