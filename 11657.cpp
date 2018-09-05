#include <algorithm>
#include <functional>
#include <iostream>
#include <cstdio>
#include <vector>
#include<utility>
#include<queue>
#include<cstring>
#include<stack>
using namespace std;
const int MAX_I = 10000000000;
int dist[501];
bool vi[501];
typedef pair <int , int> P;
int main()
{
	int n, m;
	cin >> n >> m;
	vector <P> road[501];
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		road[a].push_back({ b,c });
	}
	for (int i = 1; i <= n; i++) {
			dist[i] = MAX_I;
			vi[i] = 0;
	}
	dist[1] = 0;
	bool flag = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int p = 0; p < road[j].size(); p++) {
				if (dist[j] != MAX_I && dist[road[j][p].first] > dist[j] + road[j][p].second) {
					dist[road[j][p].first]=dist[j] + road[j][p].second;
					if (i == n - 1)
						flag = 1;
				}
			}
		}
	}
	if (flag)
		cout << -1<<'\n';
	else {
		for (int i = 2; i <= n; i++) {
			if (dist[i] == MAX_I) {
				cout << -1;
			}
			else
				cout << dist[i];
			cout << '\n';
		}
	}
}