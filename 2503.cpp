#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;
int p[1000];
int res[2];
void check(int k, int ans) {
	int a[3];
	int b[3];
	int tmp;
	tmp=k;
	int z[3]={ 100,10,1 };
	for(int i=0; i<3; i++) {
		a[i]=tmp/z[i];
		tmp%=z[i];
	}
	tmp=ans;
	for(int i=0; i<3; i++) {
		b[i]=tmp/z[i];
		tmp%=z[i];
	}
	if(b[0]==0) {
		res[0]=-1;
		res[1]=-1;
		return;
	}
	if(b[1]==0) {
		res[0]=-1;
		res[1]=-1;
		return;
	}
	if(b[2]==0) {
		res[0]=-1;
		res[1]=-1;
		return;
	}
	if(b[0]==b[1]) {
		res[0]=-1;
		res[1]=-1;
		return;
	}
	if(b[1]==b[2]) {
		res[0]=-1;
		res[1]=-1;
		return;
	}
	if(b[0]==b[2]) {
		res[0]=-1;
		res[1]=-1;
		return;
	}
	int cnt1=0, cnt2=0;
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			if(a[i]==b[j]) {
				if(i==j)
					cnt1++;
				if(i!=j)
					cnt2++;
				break;
			}
		}
	}
	res[0]=cnt1;
	res[1]=cnt2;
}
int main() {
	int a[3];
	int n;
	int k;
	int tmp;
	int z[2];
	int s, b;
	int ans=0;
	cin>>n;
	while(n>0) {
		cin>>k>>s>>b;
		for(int i=100; i<999; i++) {
			if(p[i]!=-1) {
				check(k, i);
				if(res[0]==s&&res[1]==b) {
					p[i]=1;
				}
				else {
					p[i]=-1;
				}
			}
		}
		n--;
	}
	for(int i=100; i<999; i++) {
		if(p[i]==1)
			ans++;
	}
	cout<<ans<<"\n";
}