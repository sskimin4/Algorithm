#include <algorithm>
#include <functional>
#include <iostream>
#include <cstdio>
#include <vector>
#include<queue>
using namespace std;
#define MAX_SIZE 10002
vector< pair <int, int> > v[MAX_SIZE];
int max_length;
int real_p;
int visited[MAX_SIZE];
int visited2[MAX_SIZE];
void dfs(int p, int l) {
	if (visited[p] == 1)
		return;
	if (max_length < l) {
		max_length = l;
		real_p = p;
	}
	visited[p] = 1;
	for (int i = 0; i < v[p].size(); i++) {
		dfs(v[p][i].first, l + v[p][i].second);
	}
}
void dfs2(int p, int l) {
	if (visited2[p] == 1)
		return;
	if (max_length < l) {
		max_length = l;
		real_p = p;
	}
	visited2[p] = 1;
	for (int i = 0; i < v[p].size(); i++) {
		dfs2(v[p][i].first, l + v[p][i].second);
	}
}
int main() {
	int n;
	cin >> n;
	int a, b, c;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	dfs(1, 0);
	max_length = 0;
	dfs2(real_p, 0);
	cout << max_length << "\n";
}