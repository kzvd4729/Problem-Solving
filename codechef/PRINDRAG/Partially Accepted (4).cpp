/****************************************************************************************
*  @author: kzvd4729                                         created: 08-08-2018 18:57:06                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.10 sec                                        memory_used: 15.8M                                
*  problem: https://www.codechef.com/AUG18A/problems/PRINDRAG
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int t,n,s,arr[N+2];
int vis[N+2];
vector<int>qu;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    cin>>n>>s;
    for(int i=1;i<=n;i++)
      cin>>arr[i];
    sort(arr+1,arr+n+1);
    s-=arr[n];
    if(s<=0)
    {
      for(int i=1;i<=n;i++)
        cout<<n<<" ";
      cout<<endl;
      continue;
    }
    int cnt1=0,cnt2=0;
    qu.clear();int sum1=0,id=0;
    memset(vis,0,sizeof(vis));
    for(int i=n-1;i>=1;i--)
    {
      if(sum1>=s)
      {
        while(id<qu.size())
        {
          if(sum1-arr[qu[id]]+arr[i]>=s)
          {
            sum1=sum1-arr[qu[id]]+arr[i];
            vis[qu[id]]=0;qu.push_back(i);
            vis[i]=1;id++;break;
          }
          else id++;
        }
      }
      else
      {
        sum1+=arr[i];
        vis[i]=1;cnt1++;
        qu.push_back(i);
      }
    }
    int sum2=0;
    for(int i=n-1;i>=1;i--)
    {
      if(vis[i])continue;
      sum2+=arr[i];cnt2++;
      if(sum2>=s)break;
    }
    for(int i=1;i<=n;i++)
    {
      int mx=n-i,mn=i-1,ans1=0,ans2=0;
      if(mx<mn)swap(mx,mn);
      if(sum1>=s&&cnt1<=mx)
        ans1+=(mx-cnt1+1);
      if(sum2>=s&&cnt2<=mn)
        ans1+=(mn-cnt2+1);
      swap(sum1,sum2);
      swap(cnt1,cnt2);
      if(sum1>=s&&cnt1<=mx)
        ans2+=(mx-cnt1+1);
      if(sum2>=s&&cnt2<=mn)
        ans2+=(mn-cnt2+1);
      cout<<max(ans1,ans2)<<" ";
    }
    cout<<endl;
  }
  return 0;
}