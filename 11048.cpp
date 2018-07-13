#include<iostream>
#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;
int maxi(int a, int b) {
	if (a < b)
		return b;
	return a;
}
int dp[1000][1000];
int miro[1000][1000];
int main() {
	int n, m;
	int i, j;
	cin >> n >> m;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			cin >> miro[i][j];
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (i == 0 && j == 0) {
				dp[i][j] = miro[i][j];
				dp[i][j + 1] = dp[i][j] + miro[i][j + 1];
				dp[i + 1][j] = dp[i][j] + miro[i + 1][j];
				dp[i + 1][j + 1] = dp[i][j] + miro[i + 1][j + 1];
			}
			else {
				if(i<n&&j+1<m)
					dp[i][j + 1] = maxi(dp[i][j + 1], dp[i][j] + miro[i][j + 1]);
				if (i+1<n&&j<m)
					dp[i + 1][j] = maxi(dp[i + 1][j], dp[i][j] + miro[i + 1][j]);
				if (i + 1<n&&j+1<m)
					dp[i + 1][j + 1] = maxi(dp[i + 1][j + 1], dp[i][j] + miro[i + 1][j + 1]);
			}
		}
	}
	std::cout << dp[n - 1][m - 1] << endl;
}