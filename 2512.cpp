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

int main() {
	int n;
	long long m;
	cin >> n;
	int a[10000];
	long long s = 0;
	int ma = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
		if (ma < a[i])
			ma = a[i];
	}
	cin >> m;
	int low = 0, high = ma * 2;
	while (low + 1 < high) {
		int mid = (low + high) / 2;
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] >= mid)
				sum += mid;
			else
				sum += a[i];
		}
		if (sum > m) {
			high = mid;
		}
		else {
			low = mid;
		}
	}
	if (ma>low)
		cout << low << '\n';
	else
		cout << ma << '\n';
}