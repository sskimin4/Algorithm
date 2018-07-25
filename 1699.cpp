#include<iostream>
#include<cstdio>
#include<algorithm>
#include<functional>
#include<queue>
using namespace std;
int dp[200001];
int min(int a, int b) {
	if (a < b)
		return a;
	return b;
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= 100001; i++)
		dp[i] = 100000;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 1; i <= 400; i++) {
		dp[i*i] = 1;
	}
	for (int i = 3; i <= n; i++) {
		for (int j = 1; j*j <=i; j++) {
			dp[i] = min(dp[i], dp[i - j*j] + 1);
		}
	}
	cout << dp[n] << "\n";
}