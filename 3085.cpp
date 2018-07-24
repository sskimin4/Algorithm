#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;
char board[50][50];
void swap(char *a, char *b) {
	char t;
	t=*a;
	*a=*b;
	*b=t;
}
void remi(char tmp[50][50], int n) {
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++)
			tmp[i][j]=board[i][j];
	}
}
int check(int i, int j,char tmp[50][50],int n) {
	int i1, j1;
	int ch1=1, ch2=1;
	for(i1=i-1; i1>=0; i1--) {
		if(tmp[i1][j]==tmp[i][j]) {
			ch1++;
		}
		else
			break;
	}
	for(i1=i+1; i1<n; i1++) {
		if(tmp[i1][j]==tmp[i][j]) {
			ch1++;
		}
		else
			break;
	}
	for(j1=j-1; j1>=0; j1--) {
		if(tmp[i][j1]==tmp[i][j]) {
			ch2++;
		}
		else
			break;
	}
	for(j1=j+1; j1<n; j1++) {
		if(tmp[i][j1]==tmp[i][j]) {
			ch2++;
		}
		else
			break;
	}
	if(ch1<ch2)
		return ch2;
	return ch1;
}
int main() {
	int n;
	int max=0;
	int ca;
	char tmp[50][50];
	cin>>n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin>>board[i][j];
	remi(tmp, n);
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(j+1<n) {
				swap(&tmp[i][j], &tmp[i][j+1]);
				ca=check(i, j, tmp, n);
				remi(tmp, n);
				if(ca>max) {
					max=ca;
				}
			}
			if(j-1>=0) {
				swap(&tmp[i][j], &tmp[i][j-1]);
				ca=check(i, j, tmp, n);
				remi(tmp, n);
				if(ca>max) {
					max=ca;
				}
			}
			if(i+1<n) {
				swap(&tmp[i][j], &tmp[i+1][j]);
				ca=check(i, j, tmp, n);
				remi(tmp, n);
				if(ca>max) {
					max=ca;
				}
			}
			if(i-1>=0) {
				swap(&tmp[i][j], &tmp[i-1][j]);
				ca=check(i, j, tmp, n);
				remi(tmp, n);
				if(ca>max) {
					max=ca;
				}
			}
		}
	}
	cout<<max<<"\n";
}