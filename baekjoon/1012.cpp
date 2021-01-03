#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

int bach[50][50];
bool vi[50][50];
int n, m;
void dfs(int i, int j) {
	if (vi[i][j])
		return;
	vi[i][j] = 1;
	if (i + 1 < n) {
		if (bach[i + 1][j] == 1)
			dfs(i + 1, j);
	}
	if (i - 1 >= 0) {
		if (bach[i - 1][j] == 1)
			dfs(i - 1, j);
	}
	if (j + 1 < m) {
		if (bach[i][j + 1] == 1)
			dfs(i, j + 1);
	}
	if (j - 1 >= 0) {
		if (bach[i][j - 1] == 1)
			dfs(i, j - 1);
	}
}
int main() {
	int t;
	cin >> t;
	int k;
	while (t > 0) {
		int i, j;
		int cnt = 0;
		cin >> m >> n >> k;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				bach[i][j] = 0;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				vi[i][j] = 0;
			}
		}
		for (int x = 0; x < k; x++) {
			cin >> i >> j;
			bach[j][i] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!bach[i][j])
					vi[i][j] = 1;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!vi[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
		t--;
	}
}