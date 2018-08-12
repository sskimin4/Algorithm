#include <algorithm>
#include <functional>
#include <iostream>
#include <cstdio>
#include <vector>
#include<queue>
#include<string>
#include<stack>
using namespace std;
int main() {
	long long n;
	long long w[100001];
	long long maxi=0;
	long long tmp;
	stack < pair<long long,int > > s;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		if (s.empty())
			s.push({ w[i], i });
		else {
			if(s.top().first<w[i]){
				s.push({w[i], i});
			}
			else {
				long long cnt = s.top().second;
				long long a, b;
				while (!s.empty()) {
					if (s.top().first < w[i])
						break;
					a = s.top().first;
					b = s.top().second;
					s.pop();
					if (s.size() == 0)
						tmp = a * cnt;
					else
						tmp = a * (cnt - s.top().second);
					if (maxi < tmp)
						maxi = tmp;
				}
				s.push({ w[i],i });
			}
		}
	}
	if (!s.empty()) {
		long long a, b;
		long long cnt = s.top().second;
		while (!s.empty()) {
			a = s.top().first;
			b = s.top().second;
			s.pop();
			if (s.size() == 0)
				tmp = a * cnt;
			else
				tmp = a * (cnt - s.top().second);
			if (maxi < tmp)
				maxi = tmp;
		}
	}
	cout << maxi << '\n';
}