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
int a[2200][2200];
int ans[3];

void cas(int x, int y, int s) {
	if (s == 1) {
		ans[a[x][y] + 1]++;
		return;
	}
	for (int i = x; i < x + s; i++) {
		for (int j = y; j < y + s; j++) {
			if (a[i][j] != a[x][y]) {
				for (int z = 0; z < 3; z++)
					for (int r = 0; r < 3; r++)
						cas(x + (s / 3)*z, y + (s / 3)*r, s / 3);
				return;
			}
		}
	}
	ans[a[x][y] + 1]++;
	return;
}
int main() {
	int n;

	cin >> n;
	int cnt = 0;
	int tmp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) 
			cin >> a[i][j];
	}
	cas(0, 0, n);
	for (int i = 0; i < 3; i++)
		cout << ans[i] << '\n';
	return 0;
}