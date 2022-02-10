/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-02-08 22:56:02                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 70                                         memory_used (MB): 16.4                            
*  problem: https://vjudge.net/problem/SPOJ-CRAN04
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,n,k;
string s;
void case1(void)
{
    long ans=0,cnt=0;
    for(int i=0;i<=n;i++)
    {
        if(s[i]=='0')cnt++;
        else
        {
            ans=ans+(cnt*(cnt+1))/2;
            cnt=0;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--)
    {
        s.clear();
        cin>>n>>k;
        cin>>s;
        s.push_back('1');
        long l=0,ans=0,cnt=0;
        if(k==0)
            case1();
        else
        {
            for(int i=0; i<=n; i++)
            {
                if(s[i]=='1')
                    cnt++;
                if(cnt>k)
                {
                    long tmp=i,c1=1,c2=1;
                    while(s[l++]=='0')
                        c1++;
                    while(s[--tmp]=='0')
                        c2++;
                    ans=ans+(c1*c2);
                    cnt--;
                    ///l=tmp+1;
                    ///cout<<ans<<" "<<l<<endl;
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}