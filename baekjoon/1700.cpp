#include <algorithm>
#include <functional>
#include <iostream>
#include <cstdio>
#include <vector>
#include<queue>
#include<string>
#include<stack>
using namespace std;
int e[100];

queue <int> e_nu[101];
int main() {
	int n, k;
	cin >> n >> k;
	int x;
	for (int i = 0; i < k; i++) {
		cin >> x;
		e[i] = x;
		e_nu[x].push(i);
	}
	for (int i = 0; i <= k; i++) {
		e_nu[i].push(1000);
	}

	int cnt = 0;
	int ans = 0;
	vector <int > c;
	for (int i = 0; i < k; i++) {
		if (cnt < n) {
			bool flag = 0;
			for (int j = 0; j < c.size(); j++) {
				if (c[j] == e[i]) {
					flag = 1;
					break;
				}
			}
			if (!flag) {
				cnt++;
				c.push_back(e[i]);
			}
		}
		else {
			bool flag=0;
			int max=0;
			int max_x = 0;
			for (int j = 0; j < c.size(); j++) {
				if (c[j] == e[i]) {
					flag = 1;
					break;
				}
				if(e_nu[c[j]].front()>max){
					max = e_nu[c[j]].front();
					max_x = j;
				}
			}
			if (!flag) {
				ans++;
				c[max_x] = e[i];
			}
		}
		if(e_nu[e[i]].front()!=1000)
			e_nu[e[i]].pop();
	}
	cout << ans << '\n';
}