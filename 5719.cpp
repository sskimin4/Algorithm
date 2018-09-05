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
long long dist[500];
bool vi[500];
typedef pair <long long , long long> P;
int main()
{
	while (1) {
		int n, m;
		bool flag = 0;
		vector<P> street[500];
		vector<P> hint[500];
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		int st, ed;
		cin >> st >> ed;
		for (int i = 0; i < m; i++) {
			int a, b, w;
			cin >> a >> b >> w;
			hint[b].push_back({ a,w });
			street[a].push_back({ b,w });
		}


		while (1) {
			vector <P> key[500];
			for (int i = 0; i < 500; i++) {
				dist[i] = MAX_I;
				vi[i] = 0;
			}
			priority_queue<P, vector<P>, greater<P> > pq;
			dist[st] = 0;
			pq.push({ 0,st });
			while (!pq.empty()) {
				long long n_p, n_w;
				do {
					n_p = pq.top().second;
					n_w = pq.top().first;
					pq.pop();
				} while (!pq.empty() && vi[n_p]);
				if (vi[n_p])
					break;
				vi[n_p] = 1;
				for (int i = 0; i < street[n_p].size(); i++) {
					if (dist[street[n_p][i].first] > n_w + street[n_p][i].second) {
						dist[street[n_p][i].first] = n_w + street[n_p][i].second;
						key[street[n_p][i].first].push_back({ n_p,street[n_p][i].first });
						pq.push({ dist[street[n_p][i].first] ,street[n_p][i].first });
					}
				}
			}
			if (!flag) {
				if (dist[ed] == MAX_I)
					break;
				flag = 1;
			}
			else if (flag == 1) {
				break;
			}
			P x;
			for (int z = 0; z < hint[ed].size(); z++) {
				if (hint[ed][z].second + dist[hint[ed][z].first] == dist[ed]&&dist[hint[ed][z].first]!=MAX_I) {
					for (int i = 0; i < street[hint[ed][z].first].size(); i++) {
						if (street[hint[ed][z].first][i].first == ed) {
							street[hint[ed][z].first][i].second = MAX_I;
						}
					}
					int tmp = hint[ed][z].first;
					while (1) {
						if (key[tmp].size()) {
							x.first = key[tmp][key[tmp].size() - 1].first;
							x.second = key[tmp][key[tmp].size() - 1].second;
						}
						else
							break;
						for (int q = 0; q < hint[tmp].size(); q++) {
							if (hint[tmp][q].second + dist[hint[tmp][q].first] == dist[tmp] && dist[hint[tmp][q].first] != MAX_I) {
								for (int i = 0; i < street[hint[tmp][q].first].size(); i++) {
									if (street[hint[tmp][q].first][i].first == tmp) {
										street[hint[tmp][q].first][i].second = MAX_I;
									}
								}
							}
						}
						tmp = x.first;
					}
				}
			}
		}
		if (dist[ed] == MAX_I)
			cout << -1;
		else
			cout << dist[ed];
		cout << '\n';
	}
}