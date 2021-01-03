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
int min(int a, int b) {
	if (a < b)
		return a;
	return b;
}
int main() {
	int n, m;
	cin >> n >> m;
	int a[100000];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long high = 100000000000;
	long long low = 0;
	long long ans = 100000000000;
	while (low + 1 < high) {
		bool flag = 0;
		long long mid = (low + high) / 2;
		long long m_s = 1;
		long long tmp = mid;
		for (int i = 0; i < n; i++) {
			if (mid < a[i]) {
				flag = 1;
				break;
			}
			if (tmp - a[i] >= 0) {
				tmp -= a[i];
			}
			else {
				m_s++;
				tmp = mid;
				tmp -= a[i];
			}
		}
		if (m_s > m || flag) {
			low = mid;
		}
		else {
			ans = min(ans, mid);
			high = mid;
		}
	}
	cout << ans << '\n';
}