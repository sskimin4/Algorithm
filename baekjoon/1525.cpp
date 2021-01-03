#include<iostream>
#include<cstdio>
//#include<cmath>
#include<algorithm>
//#include<string>
#include<functional>
#include<queue>
#include<vector>
#include<set>
//#include<stack>
using namespace std;
int a[3][3];
int vi[3][3];
struct puz {
	int a[3][3];
	int cnt;
};

void swap(int *x, int *y) {
	int k;
	k = *x;
	*x = *y;
	*y = k;
}
int check(int a[3][3]) {
	int cnt = 1;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 2 && i == 2)
				break;
			if (a[i][j] != cnt)
				return 0;
			cnt++;
		}
	}
	return 1;
}
long long ten(int i) {
	long long tm=1;
	for (int x = 0; x < i; x++)
		tm *= 10;
	return tm;
}
int main() {
	puz tmp;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j];
			tmp.a[i][j] = a[i][j];
		}
	tmp.cnt = 0;
	queue <puz> me;
	set <long long> fi;
	me.push(tmp);
	bool flag = 0;
	long long k;
	while (!me.empty()) {
		tmp = me.front();
		k = 0;
		int c = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				k += ten(c)*tmp.a[i][j];
				c++;
			}
		}
		me.pop();
		if (fi.find(k) != fi.end())
			continue;
		fi.insert(k);
		if (check(tmp.a)) {
			flag = 1;
			break;
		}

		tmp.cnt++;
		char s[9];
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (j + 1 < 3) {
					if (!tmp.a[i][j + 1]) {
						swap(&tmp.a[i][j+1], &tmp.a[i][j]);
						me.push(tmp);
						swap(&tmp.a[i][j+1], &tmp.a[i][j]);
					}
				}
				if (j - 1 >=0 ) {
					if (!tmp.a[i][j - 1]) {
						swap(&tmp.a[i][j - 1], &tmp.a[i][j]);
						me.push(tmp);
						swap(&tmp.a[i][j-1], &tmp.a[i][j]);
					}
				}
				if (i + 1 < 3) {
					if (!tmp.a[i + 1][j]) {
						swap(&tmp.a[i+1][j], &tmp.a[i][j]);
						me.push(tmp);
						swap(&tmp.a[i+1][j], &tmp.a[i][j]);
					}
				}
				if (i- 1 >= 0) {
					if (!tmp.a[i - 1][j]) {
						swap(&tmp.a[i-1][j], &tmp.a[i][j]);
						me.push(tmp);
						swap(&tmp.a[i-1][j], &tmp.a[i][j]);
					}
				}

			}
		}
	}
	if (flag)
		cout << tmp.cnt << '\n';
	else
		cout << -1 << '\n';
}