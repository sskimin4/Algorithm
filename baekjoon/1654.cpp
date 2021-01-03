#include<iostream>
#include<cstdio>
//#include<cmath>
#include<algorithm>
#include<string>
#include<functional>
#include<queue>
#include<vector>
#include<set>
#include<stack>
using namespace std;
int maxi(int a, int b) {
	if (a > b)
		return a;
	return b;
}
int main() {
	int k, n;
	cin >> k >> n;
	long long a[10000];
	long long max = 0;
	int ans = 0;
	for (int i = 0; i < k; i++) {
		cin >> a[i];
		if (max < a[i])
			max = a[i];
	}
	long long low = 0;
	long long high = max + 1000000;
	while (low + 1 < high) {
		long long mid = (low + high) / 2;
		int cnt = 0;
		for (int i = 0; i < k; i++) {
			cnt += (a[i] / mid);
		}
		if (cnt >= n) {
			ans = maxi(mid, ans);
			low = mid;
		}
		else {
			high = mid;
		}
	}
	cout << ans << '\n';
}