#include <algorithm>
#include <functional>
#include <iostream>
#include <cstdio>
#include <vector>
#include<queue>
#include<string>
#include<stack>
using namespace std;
int main() {
	int n;
	int p;
	stack <int > s[7];
	int cnt = 0;
	cin >> n >> p;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (s[x].empty()) {
			s[x].push(y);
			cnt++;
		}
		else {
			if (s[x].top() < y) {
				s[x].push(y);
				cnt++;
			}
			else {
				int flag = 0;
				while (!s[x].empty()) {
					if (s[x].top() == y) {
						flag = 1;
						break;
					}
					else if (s[x].top() < y) {
						break;
					}
					s[x].pop();
					cnt++;
				}
				if (flag == 0) {
					s[x].push(y);
					cnt++;
				}
			}
		}
	}
	cout << cnt << '\n';
}