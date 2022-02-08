/****************************************************************************************
*  @author: kzvd4729                                         created: 29-07-2017 20:50:46                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 23.3M                                
*  problem: https://www.codechef.com/LTIME50/problems/MAXOR
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int t,i,n,cnt[50],cnt2,zero,sum,id,x;
struct data
{
    int v;
    int cn;
}arr[1000004];
int main()
{
    cin>>t;
    while(t--)
    {
        memset(cnt,0,sizeof(cnt));
        cin>>n;
        zero=0;
        id=-1;
        for(i=1;i<=n;i++)
        {
            cin>>x;
            if(x==0)
            {
                zero++;
                continue;
            }
            ++id;
            arr[id].v=x;
            cnt2=-1;
            while(x)
            {
                cnt2++;
                if(x%2==1)
                {
                    cnt[cnt2]++;
                }
                x=x/2;
            }
            arr[id].cn=cnt2;
        }
        sum=0;
        for(i=0;i<=id;i++)
        {
            x=arr[i].v;
            cnt2=-1;
            while(x)
            {
                cnt2++;
                if(x%2==1)
                {
                    cnt[cnt2]--;
                }
                x=x/2;
            }
            sum+=cnt[arr[i].cn];
        }
        sum+=(n-1)*zero;
        cout<<sum<<endl;
    }
    return 0;
}