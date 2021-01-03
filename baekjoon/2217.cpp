#include <algorithm>
#include <functional>
#include <iostream>
#include <cstdio>
#include <vector>
#include<queue>
#include<string>
#include<stack>
using namespace std;

int lope[100000];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> lope[i];
	sort(lope, lope + n);
	long long max = 0;
	long long tmp = 0;
	for (int i = 0; i < n; i++) {
		tmp = lope[i] * (n - i);
		if (max < tmp)
			max = tmp;
	}
	cout << max << '\n';
}