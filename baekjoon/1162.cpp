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
const long long MAX_I = 1000000000000;
long long dist[10001][21];
bool vi[10001][21];
typedef pair <long long , pair<long long,long long> > P;
int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector <pair <long long,long long> > road[10001];
	for (int i = 0; i < m; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		road[a].push_back({ b,c });
		road[b].push_back({ a,c });
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 20; j++) {
			dist[i][j] = MAX_I;
			vi[i][j] = 0;
		}
	}
	priority_queue<P, vector<P>, greater<P> > pq;
	dist[1][k] = 0;
	pq.push({ 0,{1,k} });
	while (!pq.empty()) {
		long long n_p;
		long long n_k;
		long long n_w;
		do {
			n_k = pq.top().second.second;
			n_p = pq.top().second.first;
			n_w = pq.top().first;
			pq.pop();
		} while (!pq.empty() && vi[n_p][n_k]);
		if (vi[n_p][n_k])
			break;
		vi[n_p][n_k] = 1;
		for (int i = 0; i < road[n_p].size(); i++) {
			if (dist[road[n_p][i].first][n_k] > n_w + road[n_p][i].second) {
				dist[road[n_p][i].first][n_k] = n_w + road[n_p][i].second;
				pq.push({ dist[road[n_p][i].first][n_k],{road[n_p][i].first,n_k }});
			}
			if (n_k > 0) {
				if (dist[road[n_p][i].first][n_k - 1] > n_w) {
					dist[road[n_p][i].first][n_k-1] = n_w;
					pq.push({ dist[road[n_p][i].first][n_k-1],{ road[n_p][i].first,n_k-1 } });
				}
			}
		}
	}
	long long min = MAX_I;
	for (int i = 0; i <= k; i++) {
		if (min > dist[n][i]) {
			min = dist[n][i];
		}
	}
	cout << min << '\n';
}