#include<iostream>
#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;
int v[50];
int a[50];
int n;
void df(int st,int cnt) {
	if (cnt == 6) {
		for (int i = 0; i < n; i++) {
			if (v[i]) {
				printf("%d ", a[i]);
			}
		}
		printf("\n");
		return;
	}
	if (n - st < 6 - cnt)
		return;
	v[st]++;
	df(st + 1, cnt + 1);
	v[st]--;
	df(st + 1, cnt);
}
int main() {
	while (1) {
		cin >> n;
		if (n == 0)
			break;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		df(0,0);
		printf("\n");
	}
}