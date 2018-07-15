#include<iostream>
#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;
int sum[10000];
int main() {
	int n;
	int a[10000];

	long long m;
	int cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			sum[j] += a[i];
		}
		for (int j = 0; j <= i; j++) {
			if (sum[j] == m)
				cnt++;
		}
	}
	cout << cnt << endl;
}