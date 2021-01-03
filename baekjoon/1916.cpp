#include <algorithm>
#include <functional>
#include <iostream>
#include <cstdio>
#include <vector>
#include<utility>
#include<queue>
#include<string>
#include<stack>
using namespace std;
const int MAX_I = 1000000000;
int dist[1001];
bool vi[1001];
typedef pair <int, int> P;
int main() 
{
	vector<P> city[1001];
	int n,m;
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		city[u].push_back({ v,w });
	}
	for (int i = 1; i <= n; i++)
		dist[i] = MAX_I;
	int st, ed;
	cin >> st >> ed;
	dist[st] = 0;
	priority_queue<P, vector<P>, greater<P> > pq;
	pq.push({ 0,st });
	while (!pq.empty()) {
		int n_p;
		int n_w;
		do {
			n_p = pq.top().second;
			n_w = pq.top().first;
			pq.pop();
		} while (!pq.empty() && vi[n_p]);
		if (vi[n_p])
			break;
		vi[n_p] = 1;
		for (int i = 0; i < city[n_p].size(); i++) {
			if (city[n_p][i].second + n_w < dist[city[n_p][i].first]) {
				dist[city[n_p][i].first] = city[n_p][i].second + n_w;
				pq.push({ dist[city[n_p][i].first] ,city[n_p][i].first });
			}
		}
	}
	cout << dist[ed] << '\n';
}