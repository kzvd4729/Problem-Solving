/****************************************************************************************
*  @author: kzvd4729                                         created: 03-02-2018 18:30:35                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.17 sec                                        memory_used: 15.7M                                
*  problem: https://www.codechef.com/FEB18/problems/CHEFPTNT
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int t,n,m,x,k,e,o;
string s;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>x>>k;
        cin>>s;
        e=0;o=0;
        for(int i=0;i<k;i++)
        {
            if(s[i]=='E')e++;
            else o++;
        }
        for(int i=1;i<=m;i++)
        {
            if(i%2==1)
            {
                if(o>x)
                {
                    n-=x;
                    o-=x;
                }
                else
                {
                    n-=o;
                    o=0;
                }
            }
            else
            {
                if(e>x)
                {
                    n-=x;
                    e-=x;
                }
                else
                {
                    n-=e;
                    e=0;
                }
            }
        }
        if(n<=0)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}