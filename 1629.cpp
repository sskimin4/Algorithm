#include<iostream>
#include<cstdio>
//#include<cmath>
#include<algorithm>
#include<string>
#include<functional>
#include<queue>
#include<vector>
#include<set>
//#include<stack>
using namespace std;
long long two(int n) {
	long long tmp = 1;
	for (int i = 0; i < n; i++) {
		tmp *= 2;
	}
	return tmp;
}int main() {
	long long t[30];
	long long a, b, c;
	cin >> a >> b >> c;
	long long t1, t2;
	t1 = t2 = a;
	t[0] = a%c;
	for (long long i = 1; i < 30; i++) {
		t[i] = t[i - 1] * t[i - 1] % c;
	}
	int k = 29;
	int ans = 1;
	while (1) {
		if (b == 0)
			break;
		if (b - two(k) >= 0) {
			b -= two(k);
			ans = (ans*t[k]) % c;
		}
		else
			k--;
	}
	cout << ans << '\n';
}