#include<iostream>
#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;
int pl(int n);
int main() {
	int a[10];
	int n;
	int i, j;
	int t;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int max = 0;
	while (next_permutation(a, a + n)) {
		int sum = 0;
		for (i = 0; i < n - 1; i++) {
			sum += pl(a[i] - a[i + 1]);
		}
		if (max < sum)
			max = sum;

	}
	cout << max << endl;
}
int pl(int n) {
	if (n < 0)
		return n*-1;
	return n;
}