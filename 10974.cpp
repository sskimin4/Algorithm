#include<iostream>
#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;
int main() {
	int a[10];
	int n;
	int i;
	cin >> n;
	for (i = 0; i < n; i++)
		a[i] = i + 1;
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	while (next_permutation(a, a + n)) {
		for (i = 0; i < n; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
	}
	i = 1;
}