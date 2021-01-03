#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
vector <pair <int, int> > ans;
void hanoi(int start,int other,int goal,int n) {
	if (n == 1) {
		ans.push_back({ start ,goal });
		return;
	}
	hanoi(start, goal,other,n-1);
	hanoi(start, other,goal, 1);
	hanoi(other, start,goal,n-1);
}

int main() {
	int n;
	scanf("%d", &n);
	hanoi(1,2,3,n);
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
}