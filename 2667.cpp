#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;
int cnt = 0;
char tmp[26][26];
int a[25][25];
int vi[25][25];
int ct[25];
int n;
void dfs(int i, int j) {
	if (vi[i][j])
		return;
	vi[i][j] = 1;
	cnt++;
	if (i + 1 < n) {
		if (a[i + 1][j] == 1)
			dfs(i + 1, j);
	}
	if (i - 1 >= 0) {
		if (a[i - 1][j] == 1)
			dfs(i - 1, j);
	}
	if (j + 1 < n) {
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
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%s", tmp[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = tmp[i][j] - '0';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 0)
				vi[i][j] = 1;
		}
	}
	int size = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!vi[i][j]) {
				cnt = 0;
				dfs(i, j);
				ct[size++] = cnt;
			}
		}
	}
	sort(ct, ct + size);
	cout << size << '\n';
	for (int i = 0; i < size; i++)
		cout << ct[i] << "\n";
}
