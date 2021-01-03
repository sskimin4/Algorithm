#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;
int T[46];
int check(int x) {
	int sum[3];
	for(int i=1; i<=45; i++) {
		sum[0]=T[i];
		if(sum[0]>=x)
			break;
		for(int j=1; j<=45; j++) {
			sum[1]= sum[0]+T[j];
			if(sum[1]>=x)
				break;
			for(int k=1; k<=45; k++) {
				sum[2] = sum[1]+T[k];
				if(sum[2]==x)
					return 1;
				else if(sum[2]>=x)
					break;
			}
		}
	}
	return 0;
}
int main() {
	int t;
	int k;
	for(int i=1; i<=45; i++) {
		T[i]=i*(i+1)/2;
	}
	cin>>t;
	while(t>0) {
		cin>>k;
		cout<<check(k)<<"\n";
		t--;
	}
}