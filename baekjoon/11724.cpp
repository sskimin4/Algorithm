#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

vector <int> q[1001];
bool vi[1001];

void dfs(int v) {
	if (vi[v])
		return;
	vi[v] = 1;
	for (int i = 0; i < q[v].size(); i++) {
		dfs(q[v].at(i));
	}
}
int main() {
	int n, m;
	int cnt = 0;
	cin >> n >> m;
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		q[u].push_back(v);
		q[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if (!vi[i]) {
			dfs(i);
			cnt++;
		}
	}
	cout << cnt << "\n";
}