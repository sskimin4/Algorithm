#include<iostream>
#include<cstdio>
using namespace std;
int a, b;
int main() {
	int t;
	scanf("%d", &t);
	while (t != 0) {
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
		t--;
	}
}