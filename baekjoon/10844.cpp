#include <algorithm>
#include <functional>
#include <iostream>
#include <cstdio>
#include <vector>
#include<queue>
using namespace std;
#define maxi 1000000000
int dp[101][10];
int main() {
	int n;
	int ans = 0;
	cin >> n;
	for (int i = 0; i <= 9; i++)
		dp[1][i] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if(j + 1 <= 9)
				dp[i][j] = (dp[i][j] + dp[i - 1][j + 1])%maxi;
			if(j - 1 >= 0)
				dp[i][j] = (dp[i][j] + dp[i - 1][j - 1])%maxi;
		}
	}

	for (int i = 1; i <= 9; i++) {
		ans = (ans + dp[n][i])%maxi;
	}
	cout << ans << "\n";
}