#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<functional>
#include<queue>
using namespace std;

int zi[100][100];
int ca[100][100];
int vi[100][100];
int n;
void dfs(int i, int j) {
	if (vi[i][j])
		return;
	vi[i][j] = 1;
	if (i + 1 < n) {
		if (ca[i + 1][j] == 0)
			dfs(i + 1, j);
	}
	if (i - 1 >= 0) {
		if (ca[i - 1][j] == 0)
			dfs(i - 1, j);
	}
	if (j + 1 < n) {
		if (ca[i][j + 1] == 0)
			dfs(i, j + 1);
	}
	if (j - 1 >= 0) {
		if (ca[i][j - 1] == 0)
			dfs(i, j - 1);
	}

}
int main() {
	cin >> n;
	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> zi[i][j];
			if (max < zi[i][j]) {
				max = zi[i][j];
			}
		}
	}
	int cnt = 0;
	int ans_max = 0;
	for (int h = 0; h <= max; h++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				vi[i][j] = 0;
				ca[i][j] = 0;
			}
		}
		cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (zi[i][j] <= h) {
					ca[i][j] = 1;
					vi[i][j] = 1;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!vi[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		if (ans_max < cnt)
			ans_max = cnt;
	}
	cout << ans_max << '\n';
}