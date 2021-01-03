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
const int MAX_I = 1000000000;
int dist[1001];
bool vi[1001];
typedef pair <int, int> P;
int main() 
{
	int n, m;
	int x;
	cin >> n >> m >> x;
	vector<P> srt[1001];
	for (int i = 0; i < m; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		srt[s].push_back({ e,w });
	}
	int max = 0;
	int tmp = 0;
	for (int z = 1; z <= n; z++) {
		for (int i = 1; i <= n; i++) {
			dist[i] = MAX_I;
			vi[i] = 0;
		}
		dist[z] = 0;
		priority_queue<P, vector<P>, greater<P> > pq;
		pq.push({ dist[z],z });
		while (!pq.empty()) {
			int n_p, n_w;
			do {
				n_p = pq.top().second;
				n_w = pq.top().first;
				pq.pop();
			} while (vi[n_p] &&!pq.empty());
			if (vi[n_p])
				break;
			vi[n_p] = 1;
			for (int i = 0; i < srt[n_p].size(); i++) {
				if (n_w + srt[n_p][i].second < dist[srt[n_p][i].first]) {
					dist[srt[n_p][i].first] = n_w + srt[n_p][i].second;
					pq.push({ dist[srt[n_p][i].first],srt[n_p][i].first });
				}
			}
		}
		tmp = dist[x];
		for (int i = 1; i <= n; i++) {
			dist[i] = MAX_I;
			vi[i] = 0;
		}
		dist[x] = 0;
		priority_queue<P, vector<P>, greater<P> > pq2;
		pq2.push({ dist[x],x });
		while (!pq2.empty()) {
			int n_p, n_w;
			do {
				n_p = pq2.top().second;
				n_w = pq2.top().first;
				pq2.pop();
			} while (vi[n_p] && !pq2.empty());
			if (vi[n_p])
				break;
			vi[n_p] = 1;
			for (int i = 0; i < srt[n_p].size(); i++) {
				if (n_w + srt[n_p][i].second < dist[srt[n_p][i].first]) {
					dist[srt[n_p][i].first] = n_w + srt[n_p][i].second;
					pq2.push({ dist[srt[n_p][i].first],srt[n_p][i].first });
				}
			}
		}
		tmp += dist[z];
		if (max < tmp)
			max = tmp;
	}
	cout << max << '\n';
}