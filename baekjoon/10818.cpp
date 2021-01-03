#include<iostream>
#include<cstdio>
using namespace std;
int main() {
	int min, max;
	int n,value;
	scanf("%d", &n);
	scanf("%d", &value);
	min = max = value;
	for (int i = 1; i < n; i++) {
		scanf("%d", &value);
		if (value > max)
			max = value;
		if (min > value)
			min = value;
	}
	printf("%d %d\n", min, max);
}