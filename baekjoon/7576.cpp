#include <algorithm>
#include <functional>
#include <iostream>
#include <cstdio>
#include <vector>
#include<queue>
#include<string>
#include<stack>
using namespace std;
bool visit[1000][1000];
int box[1000][1000];
struct loc {
	int i;
	int j;
};
int main() {
	int c, r;
	cin >> c >> r;
	int cnt_f = 0;
	int flag = 0;
	queue < pair<loc, int> > tom;
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1)
				tom.push({ {i,j},0 });
			if (box[i][j] == 0) {
				cnt_f++;
			}
		}
	}
	loc tmp;
	int cnt = 0;
	while (!tom.empty()) {
		if (cnt_f==0) {
			flag = 1;
			break;
		}
		int tm = tom.front().second;
		while (1) {
			if (tom.empty())
				break;
			if (tom.front().second != tm)
				break;
			tmp = tom.front().first;
			cnt = tom.front().second;
			tom.pop();
			if (visit[tmp.i][tmp.j])
				continue;
			visit[tmp.i][tmp.j] = 1;
			if (tmp.i + 1 < r) {
				if (box[tmp.i + 1][tmp.j] == 0) {
					tom.push({ {tmp.i + 1, tmp.j}, cnt + 1 });
					box[tmp.i + 1][tmp.j] = 1;
					cnt_f--;
				}
			}
			if (tmp.i - 1 >= 0) {
				if (box[tmp.i - 1][tmp.j] == 0) {
					tom.push({ { tmp.i - 1, tmp.j}, cnt + 1 });
					box[tmp.i - 1][tmp.j] = 1;
					cnt_f--;
				}
			}
			if (tmp.j + 1 < c) {
				if (box[tmp.i][tmp.j + 1] == 0) {
					tom.push({ { tmp.i, tmp.j + 1}, cnt + 1 });
					box[tmp.i][tmp.j+1] = 1;
					cnt_f--;
				}
			}
			if (tmp.j - 1 >= 0) {
				if (box[tmp.i][tmp.j - 1] == 0) {
					tom.push({ { tmp.i, tmp.j - 1}, cnt + 1 });
					box[tmp.i][tmp.j-1] = 1;
					cnt_f--;
				}
			}
		}
		if (cnt_f == 0) {
			flag = 2;
			break;
		}
	}
	if (flag==2)
		cout << cnt+1 << '\n';
	else if(flag==1)
		cout << cnt<< '\n';
	else
		cout << -1 << '\n';
}