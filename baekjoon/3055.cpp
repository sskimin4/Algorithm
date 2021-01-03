#include <algorithm>
#include <functional>
#include <iostream>
#include <cstdio>
#include <vector>
#include<queue>
#include<string>
#include<stack>
using namespace std;
char sup[50][50];
bool visit[50][50];
struct loc {
	int i;
	int j;
};
int main() {
	int r, c;
	queue < pair<loc, int > > water;
	queue < pair<loc, int > > g;

	string s;
	loc ans;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> s;
		for (int j = 0; j < c; j++) {
			sup[i][j] = s[j];
			if (sup[i][j] == '*') {
				water.push({ {i,j},0 });
			}
			if (sup[i][j] == 'S') {
				g.push({ { i,j },0 });
				sup[i][j] = '.';
			}
		}
	}
	loc tmp;
	int cnt = 0;
	int flag = 0;
	while (!g.empty()) {
		tmp = g.front().first;
		cnt = g.front().second;
		g.pop();
		if (visit[tmp.i][tmp.j])
			continue;
		visit[tmp.i][tmp.j] = 1;
		if (sup[tmp.i][tmp.j] == '*')
			continue;
		if (tmp.i + 1 < r) {
			if (sup[tmp.i + 1][tmp.j] == '.') {
				g.push({ {tmp.i + 1, tmp.j}, cnt + 1 });
			}
			if (sup[tmp.i+1][tmp.j]=='D') {
				flag = 1;
				break;
			}
		}
		if (tmp.i - 1 >= 0) {
			if (sup[tmp.i - 1][tmp.j] == '.') {
				g.push({ { tmp.i - 1, tmp.j }, cnt + 1 });
			}
			if (sup[tmp.i - 1][tmp.j] == 'D') {
				flag = 1;
				break;
			}

		}
		if (tmp.j + 1 < c) {
			if (sup[tmp.i][tmp.j+1] == '.') {
				g.push({ { tmp.i, tmp.j+1 }, cnt + 1 });
			}
			if (sup[tmp.i][tmp.j+1] == 'D') {
				flag = 1;
				break;
			}

		}
		if (tmp.j - 1 >= 0) {
			if (sup[tmp.i][tmp.j-1] == '.') {
				g.push({ { tmp.i, tmp.j-1 }, cnt + 1 });
			}
			if (sup[tmp.i][tmp.j-1] == 'D') {
				flag = 1;
				break;
			}

		}
		if (!g.empty()&&!water.empty()) {
			if(g.front().second!=water.front().second){
				int wsize = water.size();
				while (wsize > 0) {
					tmp = water.front().first;
					cnt = water.front().second;
					water.pop();
					if (tmp.i + 1 < r) {
						if (sup[tmp.i + 1][tmp.j] == '.') {
							sup[tmp.i + 1][tmp.j] = '*';
							water.push({ { tmp.i + 1, tmp.j }, cnt + 1 });
						}
					}
					if (tmp.i - 1 >= 0) {
						if (sup[tmp.i - 1][tmp.j] == '.') {
							sup[tmp.i - 1][tmp.j] = '*';
							water.push({ { tmp.i - 1, tmp.j }, cnt + 1 });
						}
					}
					if (tmp.j + 1 < c) {
						if (sup[tmp.i][tmp.j + 1] == '.') {
							sup[tmp.i][tmp.j+1] = '*';
							water.push({ { tmp.i, tmp.j + 1 }, cnt + 1 });
						}
					}
					if (tmp.j - 1 >= 0) {
						if (sup[tmp.i][tmp.j - 1] == '.') {
							sup[tmp.i][tmp.j-1] = '*';
							water.push({ { tmp.i, tmp.j - 1 }, cnt + 1 });
						}
					}
					wsize--;
				}
			}
		}
	}
	if (flag)
		cout << cnt+1 << '\n';
	else
		cout << "KAKTUS" << '\n';
}