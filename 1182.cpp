#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;
int ans=0;
int n, s;
int w[20];
void check(int c,int i) {
	if(i==n-1)
		return;
	for(int j=i+1; j<n; j++) {
		if(c+w[j]==s)
			ans++;
		check(c+w[j], j);
	}
}
int main() {
	cin>>n>>s;
	for(int i=0; i<n; i++) {
		cin>>w[i];
	}
	check(0, -1);
	cout<<ans<<"\n";
}