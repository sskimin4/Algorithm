#include<stack>
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char a[101];
stack <char> s;
int level(char k) {
	if (k == '(')
		return 0;
	if (k == '+' || k == '-')
		return 1;
	else
		return 2;
}
int main() {
	char ans[101];
	int size = 0;
	scanf("%s", a);
	for (int i = 0; i < strlen(a); i++) {
		if (a[i] <= 'Z'&&a[i] >= 'A') {
			ans[size++] = a[i];
		}
		else if (a[i] == '(') {
			s.push(a[i]);
		}
		else if (a[i] == ')') {
			while (1) {
				if (s.top() == '(') {
					s.pop();
					break;
				}
				else {
					ans[size++] = s.top();
					s.pop();
				}
			}
		}
		else {
			if (s.empty())
				s.push(a[i]);
			else{
				while (!s.empty()) {
					if (level(s.top()) >= level(a[i]))
						ans[size++] = s.top();
					else
						break;
					s.pop();
				}
				s.push(a[i]);
			}
		}
	}
	while (!s.empty()) {
		ans[size++] = s.top();
		s.pop();
	}
	for (int i = 0; i < size; i++)
		cout << ans[i];
	printf("\n");
}
