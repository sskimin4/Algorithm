#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
map <int,int> m;
vector < pair<int,int> > thing;
int dp[100][100001];
int max(int a,int b){
  if(a<b)
    return b;
  return a;
}
int main()
{
  int n,k;
  scanf("%d%d",&n,&k);
  for(int i=0;i<n;i++){
    int w,v;
    scanf("%d%d",&w,&v);
    thing.push_back(make_pair(w,v)); 
  }
  sort(thing.begin(),thing.end());
  int answer=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<=k;j++){
      if(i==0){
        if(thing[i].first>j)
          continue;
        dp[i][j]=thing[i].second;
      }
      else{
        if(j-thing[i].first>=0)
          dp[i][j]=max(dp[i-1][j],dp[i-1][j-thing[i].first]+thing[i].second);
        else{
          dp[i][j]=dp[i-1][j];
        }
      }
    }
  }
  /*
  for(int i=0;i<n;i++){
    for(int j=0;j<=k;j++){
      printf("%d ",dp[i][j]);
    }
    printf("\n");
  }
  */
  printf("%d\n",dp[n-1][k]);
  return 0;
  //value를 최대로 무게를 최저로? a[무게] = a[x] + a[y] X
  //a[i,무게] = max(a[i-1,무게],a[i-1,무게-a[i]무게]+a[i] 가치
}
