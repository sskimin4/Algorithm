#include<iostream>
#include<cstdio>
#include<algorithm>
#include<functional>
#include<queue>
using namespace std;
int a, b;
int cat[10000];
int ans=-1;

int main() {
	int t;
	int tmp[4];
	int cnt;
	cin >> t;
	for (int i = 2; i < 10000; i++) {
		if (cat[i] == 0) {
			cnt = 2;
			while (1) {
				if (i*cnt <= 9999) {
					cat[i*cnt] = 1;
				}
				else
					break;
				cnt++;
			}
		}
	}
	int num;
	int na;
	cnt = -1;
	int s[4] = { 1000,100,10,1 };
	while (t > 0) {
		t--;
		cin >> a >> b;
		int visited[10000] = {};
		queue < pair <int, int> > q;
		visited[a] = 1;
		q.push({ a,0 });
		while (!q.empty()) {
			num = q.front().first;
			na = num;
			cnt = q.front().second;
			if (na == b) {
				ans = cnt;
				break;
			}
			for (int i = 0; i < 4; i++) {
				tmp[i] = num / s[i];
				num %= s[i];
			}
			q.pop();
			int c;
			for (int i = 0; i < 4; i++) {
				num = na - s[i] * tmp[i];
				for (int j = 0; j < 10; j++) {
					if (i == 0 && j == 0)
						continue;
					c = num + s[i] * j;
						if (!cat[c]&&!visited[c]) {
							visited[c] = 1;
							q.push({ c, cnt + 1 });
						}
				}
			}
		}
		if (ans == -1)
			cout << "Impossible" << "\n";
		else
			cout <<  ans << "\n";
	}
}