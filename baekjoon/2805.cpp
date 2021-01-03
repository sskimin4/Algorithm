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
long long a[1000000];
long long m;
int main() {
	int n;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int lw = 0, hg = 1000000000;
	while (lw + 1 < hg) {
		int mid = (lw + hg) / 2;
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] - mid>0) {
				sum = sum + (a[i] - mid);
			}
		}
		if (sum >= m) {
			lw = mid;
		}
		else {
			hg = mid;
		}
	}
	cout << lw << '\n';
}