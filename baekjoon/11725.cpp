#include <algorithm>
#include <functional>
#include <iostream>
#include <cstdio>
#include <vector>
#include<queue>
using namespace std;
int vk[100001];
vector <int> co[100001];
int main() {
	int n;
	int a, b;
	cin >> n;
	queue< pair < int, int > > v;
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;
		co[a].push_back(b);
		co[b].push_back(a);
	}
	for (int i = 0; i < co[1].size(); i++) {
		v.push({1,co[1][i]});
	}
	while (!v.empty()) {
		a = v.front().first;
		b = v.front().second;
		v.pop();
		vk[b] = a;
		for (int i = 0; i < co[b].size(); i++) {
			if(co[b][i]!=a)
				v.push({ b,co[b][i] });
		}
	}
	for (int i = 2; i <=n; i++) {
		cout << vk[i] << "\n";
	}
}