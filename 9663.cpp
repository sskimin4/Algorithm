#include<iostream>
#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;

int q[16];
int cnt=0;
int n;
int ah(int k) {
	if (k < 0)
		return k*-1;
	return k;
}
bool check(int r) {
	for (int i = 1; i < r; i++) {
		if (q[r] == q[i] || r - i== ah(q[r] - q[i]))
			return 0;
	}
	return 1;
}
void df(int r) {
	if (r == n+1) {
		cnt++;
		return;
	}
	for (int i = 1; i <= n; i++) {
		q[r] = i;
		if (check(r)) {
			df(r + 1);
		}
	}
}
int main() {
	cin >> n;
	df(1);
	cout << cnt << endl;
}