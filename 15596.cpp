#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char ans[2201][2201];
void line_1(int x,int y) {
	ans[x][y]=ans[x][y+1]=ans[x][y+2]='*';
}
void line_2(int x,int y) {
	ans[x][y] = ans[x][y + 2] = '*';
	ans[x][y + 1] = ' ';
}
void print_star(int x,int y,int n) {
	if (n / 3==1) {
		line_1(x, y);
		line_2(x+1, y);
		line_1(x+2, y);
		return;
	}
	print_star(x, y, n/3);
	print_star(x, y + n/3,n/3);
	print_star(x, y+2*n/3, n / 3);
	
	print_star(x+n/3, y, n / 3);
	print_star(x+n/3, y + 2 * n / 3, n / 3);

	print_star(x+2*n/3, y, n / 3);
	print_star(x+2*n/3, y + n / 3, n / 3);
	print_star(x + 2 * n / 3, y + 2 * n / 3, n / 3);

}
int main() {
	int n;
	scanf("%d", &n);
	memset(ans, ' ', sizeof(ans));
	print_star(0,0,n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%c", ans[i][j]);
		printf("\n");
	}
}
