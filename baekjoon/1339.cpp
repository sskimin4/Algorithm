#include<iostream>
#include<cstdio>
using namespace std;
void compare(int a, int b) {
	if (a < b)
		printf("<");
	else if (a == b)
		printf("==");
	else
		printf(">");
}
int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	compare(a, b);
}