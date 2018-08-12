#include <algorithm>
#include <functional>
#include <iostream>
#include <cstdio>
#include <vector>
#include<queue>
//#include<string>
#include<stack>
#include<cstring>
using namespace std;
int ca(char s[],int size) {

	if (!strncmp(s,"body",size))
		return 0;
	if (!strncmp(s, "strong",size))
		return 1;
	if (!strncmp(s, "br /",size))
		return 2;
	if (!strncmp(s, "p",size))
		return 3;
	if (s[0] == 'a')
		return 4;
	if (!strncmp(s, "/body",size))
		return 5;
	if (!strncmp(s, "/strong",size))
		return 6;
	if (!strncmp(s, "/p",size))
		return 8;
	if (!strncmp(s, "/a",size))
		return 9;
}
int main() {


	while (1) {
		char code[256];
		char k;
		int size = 0;
		while (1) {
			scanf("%c",&k);
			if (k == '\n')
				break;
			code[size++] = k;
		}
		if (code[0] == '#')
			break;
		int flag = 0;
		int tmp;
		stack <int> s;
		char ck[255];
		int size2 = 0;
		int j;
		for (int i = 0; i < size; i++) {
			if (code[i] == '<') {
				size2 = 0;
				for (j = i + 1; i < size; j++) {
					if (code[j] == '>')
						break;
					ck[size2++] = code[j];
				}
				tmp = ca(ck,size2);
				if (s.empty()) {
					if (tmp == 5 || tmp == 6 || tmp == 8 || tmp == 9){
						flag = 1;
						break;
					}
					if(tmp!=2)
						s.push(tmp);
				}
				else {
					if (s.top() + 5 == tmp) {
						s.pop();
					}
					else if (tmp == 5 || tmp == 6 || tmp == 8 || tmp == 9) {
						flag = 1;
						break;
					}
					else if(tmp!=2)
						s.push(tmp);
				}

				i = j;
			}
		}
		if (!s.empty())
			flag = 1;
		if (flag == 1)
			cout << "illegal" << '\n';
		else
			cout << "legal" << '\n';
	}
}