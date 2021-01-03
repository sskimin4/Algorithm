#include <algorithm>
#include <functional>
#include <iostream>
#include <cstdio>
#include <vector>
#include<queue>
using namespace std;
char a[50][50];
#define maxi 2147483647
int check(int q, int w) {
	int cnt = 0;
	char t[8][8];
	int x = 0, y = 0;
	for (int i = q; i < q + 8; i++) {
		y = 0;
		for (int j = w; j < w + 8; j++) {
			t[x][y] = a[i][j];
			y++;
		}
		x++;
	}
	char k[2];
	k[0] = t[0][0];
	if (k[0] == 'W')
		k[1] = 'B';
	else
		k[1] = 'W';
	for (int i = 0; i < 8; i++) {
			if (k[i % 2] != t[i][0]) {
				t[i][0] = k[i % 2];
				cnt++;
			}
	}	
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 7; j++) {
			if (t[i][j] == t[i][j + 1]) {
				if (t[i][j] == 'W')
					t[i][j + 1] = 'B';
				else
					t[i][j + 1] = 'W';
				cnt++;
			}
		}
	}
	return cnt;
}
int check2(int q, int w) {
	int cnt = 0;
	char t[8][8];
	int x = 0, y = 0;
	for (int i = q; i < q + 8; i++) {
		y = 0;
		for (int j = w; j < w + 8; j++) {
			t[x][y] = a[i][j];
			y++;
		}
		x++;
	}
	char k[2];
	k[1] = t[0][0];
	if (k[1] == 'W')
		k[0] = 'B';
	else
		k[0] = 'W';
	for (int i = 0; i < 8; i++) {
		if (k[i % 2] != t[i][0]) {
			t[i][0] = k[i % 2];
			cnt++;
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 7; j++) {
			if (t[i][j] == t[i][j + 1]) {
				if (t[i][j] == 'W')
					t[i][j + 1] = 'B';
				else
					t[i][j + 1] = 'W';
				cnt++;
			}
		}
	}
	return cnt;
}
int main() {
	int n, m;
	int min = maxi;
	int tmp;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			tmp = check(i, j);
			if (tmp < min)
				min = tmp;
			tmp = check2(i, j);
			if(tmp<min)
				min=tmp;
		}
	}
	cout << min << "\n";
}