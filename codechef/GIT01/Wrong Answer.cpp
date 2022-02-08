/****************************************************************************************
*  @author: kzvd4729                                         created: 01-12-2017 16:46:25                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/DEC17/problems/GIT01
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
string s;
long t,n,m,now,s1,s2,f;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        now=0;
        s1=0,s2=0;
        for(long k=0; k<n; k++)
        {
            cin>>s;
            if(k%2==0)
            {
                for(long i=0; i<m; i++)
                {
                    if(s[i]=='R')f=0;
                    else f=1;
                    if(now==0&&f==1)s1+=5;
                    else if(now==1&&f==0)s1+=3;
                    if(now==0&&f==0)s2+=3;
                    else if(now==1&&f==1)s2+=5;
                    now^=1;
                }
            }
            else
            {
                for(long i=m-1; i>=0; i--)
                {
                    if(s[i]=='R')f=0;
                    else f=1;
                    if(now==0&&f==1)s1+=5;
                    else if(now==1&&f==0)s1+=3;
                    if(now==0&&f==0)s2+=3;
                    else if(now==1&&f==1)s2+=5;
                    now^=1;
                }
            }
        }
        cout<<min(s1,s2)<<endl;
    }
    return 0;
}