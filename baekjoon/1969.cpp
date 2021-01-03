#include <algorithm>
#include <functional>
#include <iostream>
#include <cstdio>
#include <vector>
#include<queue>
#include<string>
#include<stack>
using namespace std;

char max_a(int a, int t, int g, int c) {
	if (a >= t && a >= g && a >= c) {
		return 'A';
	}
	if (c > a && c >= g && c >= t) {
		return 'C';
	}
	if (g >= t && g > a && g > c) {
		return 'G';
	}
	if (t > g && t > a && t > c) {
		return 'T';
	}

}
int main() {
	int n, m;
	string s[1000];
	string ans;
	int A[50];
	int T[50];
	int G[50];
	int C[50];

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			if (s[i][j] == 'A') {
				A[j]++;
			}
			else if (s[i][j] == 'T') {
				T[j]++;
			}
			else if (s[i][j] == 'G') {
				G[j]++;
			}
			else if (s[i][j] == 'C') {
				C[j]++;
			}
		}
	}
	for (int i = 0; i < m; i++)
		ans.push_back(max_a(A[i], T[i], G[i], C[i]));
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] != ans[j])
				cnt++;
		}
	}
	cout << ans << '\n';
	cout << cnt << '\n';
}