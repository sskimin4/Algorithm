#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;
int cnt = 0;
int a[101][101];
int vi[101][101];
int n, m;
void dfs(int i, int j) {
	if (vi[i][j])
		return;
	vi[i][j] = 1;
	cnt++;
	if (i + 1 <= n) {
		if (a[i + 1][j] == 1)
			dfs(i + 1, j);
	}
	if (i - 1 >= 0) {
		if (a[i - 1][j] == 1)
			dfs(i - 1, j);
	}
	if (j + 1 <= m) {
		if (a[i][j + 1] == 1)
			dfs(i, j + 1);
	}
	if (j - 1 >= 0) {
		if (a[i][j - 1] == 1)
			dfs(i, j - 1);
	}
}
int main()
{
	int k;
	int x, y;

	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		a[x][y] = 1;
	}
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < m + 1; j++) {
			if (a[i][j] == 0)
				vi[i][j] = 1;
		}
	}
	int max = 0;
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < m + 1; j++) {
			if (!vi[i][j]) {
				cnt = 0;
				dfs(i, j);
				if (cnt > max)
					max = cnt;
			}
		}
	}
	cout << max << '\n';
}
