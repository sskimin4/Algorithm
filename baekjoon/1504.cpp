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
int dist[801];
bool vi[801];
typedef pair <int, int> P;
int main() 
{
	vector<P> city[801];
	int n,m;
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		city[u].push_back({ v,w });
		city[v].push_back({ u,w });
	}
	int c1,c2;
	cin >> c1 >> c2;
	int ans[3];
	int p = 0;
	bool flag = 0;
	while (p < 3) {
		priority_queue<P, vector<P>, greater<P> > pq;
		if(p==0)
			pq.push({ 0,1 });
		else if (p == 1) 
			pq.push({ 0,c1 });
		else if(p==2)
			pq.push({ 0,c2 });
		for (int i = 1; i <= n; i++) {
			dist[i] = MAX_I;
			vi[i] = 0;
		}
		dist[pq.top().second] = 0;
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
		if(p==0)
			ans[p] = dist[c1];
		else if(p==1)
			ans[p] = dist[c2];
		else
			ans[p] = dist[n];
		if (ans[p] == MAX_I) {
			flag = 1;
			break;
		}
		p++;
	}
	int ca[2];
	if (!flag)
		ca[0] = ans[0] + ans[1] + ans[2];
	else
		ca[0] = MAX_I;
	p = 0;
	flag = 0;
	while (p < 3) {
		priority_queue<P, vector<P>, greater<P> > pq;
		if (p == 0)
			pq.push({ 0,1 });
		else if (p == 1)
			pq.push({ 0,c2 });
		else if (p == 2)
			pq.push({ 0,c1 });
		for (int i = 1; i <= n; i++) {
			dist[i] = MAX_I;
			vi[i] = 0;
		}
		dist[pq.top().second] = 0;
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
		if (p == 0)
			ans[p] = dist[c2];
		else if (p == 1)
			ans[p] = dist[c1];
		else
			ans[p] = dist[n];
		if (ans[p] == MAX_I) {
			flag = 1;
			break;
		}
		p++;
	}
	if (!flag)
		ca[1] = ans[0] + ans[1] + ans[2];
	else
		ca[1] = MAX_I;
	if (ca[0] <= ca[1]) {
		if (ca[0] == MAX_I)
			cout << -1 << '\n';
		else
			cout << ca[0] << '\n';
	}
	else {
		cout << ca[1] << '\n';
	}
}