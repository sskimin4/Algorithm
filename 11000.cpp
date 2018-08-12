#include <algorithm>
#include <functional>
#include <iostream>
#include <cstdio>
#include <vector>
#include<queue>
#include<string>
#include<stack>
using namespace std;
pair <int, int > c[200000];
int a[200000];
bool comp(pair<int, int>a, pair<int, int> b) {
	if (a.first > b.first)
		return 0;
	else if (a.first == b.first) {
		if (a.second < b.second)
			return 1;
		else
			return 0;
	}
	else
		return 1;
}
int main() {
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int> > q;
	for (int i = 0; i < n; i++)
		cin >> c[i].first >> c[i].second;
	sort(c, c + n, comp);
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			q.push(c[i].second);
		}
		else {
			if (q.top()>c[i].first) {
				q.push(c[i].second);
			}
			else {
				q.pop();
				q.push(c[i].second);
			}
		}
	}
	cout << q.size() << '\n';
	return 0;
}