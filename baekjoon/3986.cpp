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
	int n;
	string s;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> s;
		int flag = 1;
		stack <char> word;
		for (int j = 0; j < s.size(); j++) {
			if (word.empty())
				word.push(s[j]);
			else if (word.top() == s[j]) {
				word.pop();
			}
			else {
				word.push(s[j]);
			}
		}
		if (!word.empty())
			flag = 0;
		if (flag)
			cnt++;
	}
	cout << cnt << '\n';
}