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
int r, c;
int num;
int pr;
bool flag;
void ans(int st_i, int st_j, int len) {
	if (len != 2) {
		ans(st_i, st_j, len / 2);
		ans(st_i, st_j + len / 2, len / 2);
		ans(st_i + len / 2, st_j, len / 2);
		ans(st_i + len / 2, st_j + len / 2, len / 2);
		return;
	}
	if (flag == 1)
		return;
	if ((r >= st_i&&r < st_i + len) && (c >= st_j&&c < st_j + len)) {
		flag = 1;
		for (int i = st_i; i < st_i + len; i++) {
			for (int j = st_j; j < st_j + len; j++) {
				if (r == i&&c == j) {
					pr = num;
					return;
				}
				num++;
			}
		}
	}
	else
		num += 4;
}
int two(int n) {
	int tmp = 1;
	for (int i = 0; i < n; i++)
		tmp *= 2;
	return tmp;
}
int main() {
	int n;
	cin >> n >> r >> c;
	ans(0, 0, two(n));
	cout << pr << '\n';
}