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
bool a[64][64];
void ans(int st_i, int st_j, int len, int flag) {
	for (int i = st_i; i < st_i + len; i++) {
		for (int j = st_j; j < st_j + len; j++) {
			if (a[st_i][st_j] != a[i][j]) {
				cout << '(';
				ans(st_i, st_j, len / 2, 1);
				ans(st_i, st_j + len / 2, len / 2, 2);
				ans(st_i + len / 2, st_j, len / 2, 3);
				ans(st_i + len / 2, st_j + len / 2, len / 2, 4);
				cout << ')';
				return;
			}
		}
	}
	cout << a[st_i][st_j];
}
int main() {
	int n;
	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++)
			a[i][j] = s[j] - '0';
	}
	ans(0, 0, n, 0);
	cout << '\n';
}