#include<iostream>
#include<cstdio>
//#include<cmath>
#include<algorithm>
#include<string>
#include<functional>
#include<queue>
#include<vector>
#include<set>
//#include<stack>
using namespace std;
bool vi[1000001];
void chan1(string *a, int n) {
	int x, y;
	while (n>0) {
		x = n % 10;
		(*a).push_back(x+'0');
		n = n / 10;
	}
}
int ten(int x) {
	int k = 1;
	for (int i = 0; i < x; i++)
		k *= 10;
	return k;
}
int chan2(string a, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += (a[i] - '0')*ten(i);
	return sum;
}
void swap(char *a, char *b) {
	char k;
	k = *a;
	*a = *b;
	*b = k;
}
int main() {
	int n, k;
	cin >> n >> k;

	queue <pair <int, int> > q;
	queue <int> ans;
	q.push({ n,0 });
	pair <int, int> tmp;

	while (!q.empty()) {
		string a;
		tmp = q.front();
		q.pop();
		int ch;
		chan1(&a, tmp.first);
		if (tmp.second >= k + 1)
			break;
		if (tmp.second == k){
			ans.push(tmp.first);
		}
		for (int i = 0; i < a.size()-1; i++) {
			for (int j = i + 1; j < a.size(); j++) { 
				if (a[i] == '0'&&j == a.size() - 1)
					continue;
				swap(&a[i], &a[j]);
				ch = chan2(a, a.size());
				if (!vi[ch]) {
					vi[ch] = 1;
					q.push({ ch,tmp.second + 1 });
				}
				swap(&a[i], &a[j]);
			}
		}
		if (!q.empty()) {
			if (tmp.second != q.front().second) {
				for (int i = 0; i < ten(a.size()); i++) {
					if (i == 1000001)
						break;
					vi[i] = 0;
				}
			}
		}
	}
	int max = 0;
	int tm = 0;
	if (ans.empty())
		cout << -1 << '\n';
	else {
		while (!ans.empty()) {
			tm = ans.front();
			ans.pop();
			if (max < tm)
				max = tm;
		}
		cout << max << '\n';
	}
}