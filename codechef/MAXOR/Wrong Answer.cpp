/****************************************************************************************
*  @author: kzvd4729                                         created: 29-07-2017 20:26:36                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 23.3M                                
*  problem: https://www.codechef.com/LTIME50/problems/MAXOR
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int t,n,i,x,cnt[30],cnt2,sum;
struct data
{
    int v;
    int cn;
}arr[1000005];
int main()
{
    cin>>t;
    while(t--)
    {
        memset(cnt,0,sizeof(cnt));
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>x;
            arr[i].v=x;
            cnt2=-1;
            while(x)
            {
                cnt2++;
                if(x%2==0)
                {
                    cnt[cnt2]++;
                }
                x=x/2;
            }
            arr[i].cn=cnt2;
        }
        sum=0;
        for(i=1;i<=n;i++)
        {
            sum+=cnt[arr[i].cn];
        }
        int ans=(n*(n-1))/2-sum;
        cout<<ans<<endl;
    }
    return 0;
}