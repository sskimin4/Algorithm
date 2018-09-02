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
int dist[125][125];
bool vi[125][125];
typedef pair <int, pair<int, int> > P;
int main() 
{
	int t = 1;
	while (1) {
		int n;
		int cave[125][125];
		cin >> n;
		if (n == 0)
			break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> cave[i][j];
				dist[i][j] = MAX_I;
				vi[i][j] = 0;
			}
		}
		dist[0][0] = cave[0][0];
		priority_queue<P, vector<P>, greater<P> > pq;
		pq.push({ dist[0][0],{0,0} });
		while (!pq.empty()) {
			pair <int, int> n_p;
			int n_w;
			do {
				n_p = pq.top().second;
				n_w = pq.top().first;
				pq.pop();
			} while (vi[n_p.first][n_p.second]&&!pq.empty());
			if (vi[n_p.first][n_p.second])
				break;
			vi[n_p.first][n_p.second] = 1;
				if (n_p.first + 1 < n) {
					if (dist[n_p.first + 1][n_p.second] > n_w + cave[n_p.first + 1][n_p.second]) {
						dist[n_p.first + 1][n_p.second] = n_w + cave[n_p.first + 1][n_p.second];
						pq.push({dist[n_p.first + 1][n_p.second],{ n_p.first + 1 ,n_p.second } });
					}
				}
				if (n_p.first - 1 >=0) {
					if (dist[n_p.first - 1][n_p.second] > n_w + cave[n_p.first - 1][n_p.second]) {
						dist[n_p.first - 1][n_p.second] = n_w + cave[n_p.first - 1][n_p.second];
						pq.push({ dist[n_p.first - 1][n_p.second],{ n_p.first - 1 ,n_p.second } });
					}
				}
				if (n_p.second + 1 < n) {
					if (dist[n_p.first][n_p.second+1] > n_w + cave[n_p.first][n_p.second+1]) {
						dist[n_p.first][n_p.second+1] = n_w + cave[n_p.first][n_p.second+1];
						pq.push({ dist[n_p.first][n_p.second+1],{ n_p.first,n_p.second+1 } });

					}
				}
				if (n_p.second - 1 >= 0) {
					if (dist[n_p.first][n_p.second-1] > n_w + cave[n_p.first][n_p.second-1]) {
						dist[n_p.first][n_p.second-1] = n_w + cave[n_p.first][n_p.second-1];
						pq.push({ dist[n_p.first][n_p.second-1],{ n_p.first ,n_p.second-1 } });
					}
				}
		}
		cout << "Problem " << t << ": " << dist[n - 1][n - 1] << '\n';
		t++;
	}
}