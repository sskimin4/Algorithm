#include<iostream>
#include<cstdio>
//#include<cmath>
#include<algorithm>
//#include<string>
//#include<functional>
//#include<queue>
#include<vector>
using namespace std;

vector <int> st[100001];
vector <int> q;
int vi[100001];
int f[100001];
int cnt = 0;
void dfs(int v) {
	if (vi[v] == 1 && f[v] != 1) {
		int i = q.size() - 1;
		while (1) {
			if (q.at(i) == v)
				break;
			q.pop_back();
			i--;
			cnt++;
		}
		cnt++;
	}
	if (vi[v]) {
		return;
	}
	vi[v] = 1;
	q.push_back(v);
	for(int i=0;i<st[v].size();i++)
		dfs(st[v].at(i));
	f[v] = 1;
}
int main() {
	int t;
	cin >> t;
	int ans;
	int n;
	while (t > 0) {
		ans = 0;
		cin >> n;
		int p;
		for (int i = 1; i <= n; i++) {
			cin >> p;
			st[i].push_back(p);
		}
		for (int i = 1; i <= n; i++) {
			cnt = 0;
			if (!vi[i])
				dfs(i);
			while (!q.empty())
				q.pop_back();
			ans += cnt;
		}
		for (int i = 1; i <= n; i++) {
			vi[i] = 0;
			f[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			st[i].pop_back();
		}
		cout << n - ans << '\n';
		t--;
	}
}