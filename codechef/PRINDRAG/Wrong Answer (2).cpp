/****************************************************************************************
*  @author: kzvd4729                                         created: 03-08-2018 18:42:01                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 19.5M                                
*  problem: https://www.codechef.com/AUG18A/problems/PRINDRAG
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int t,n,p,arr[1000006],mx;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>t;
  while(t--)
  {
    cin>>n>>p;
    for(int i=1;i<=n;i++)
      cin>>arr[i];
    sort(arr+1,arr+n+1);
    mx=arr[n];
     if(mx>=p)
    {
      for(int i=1;i<=n;i++)
        cout<<n<<" ";
      cout<<endl;
      continue;
    }
    int cnt1=0,cnt2=0,sum1=mx,sum2=mx;
     for(int i=n-1;i>=1;i--)
    {
      if(sum1<p)
      {
        sum1+=arr[i];
        cnt1++;
      }
      else if(sum2<p)
      {
        sum2+=arr[i];
        cnt2++;
      }
    }
    for(int i=1;i<=n;i++)
    {
      int rgt=n-i;
      int lft=i-1;
      int ans=0;
      if(lft>rgt)swap(lft,rgt);
       if(sum1>=p)ans+=(rgt-cnt1+1);
      if(sum2>=p)ans+=(lft-cnt2+1);
      cout<<ans<<" ";
    }
    cout<<endl;
  }
  return 0;
}