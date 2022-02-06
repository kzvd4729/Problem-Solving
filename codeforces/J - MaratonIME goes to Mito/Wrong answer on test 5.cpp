/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/05/2017 18:38                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 3300 KB                              
*  problem: https://codeforces.com/gym/101375/problem/J
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n,m,a[300004],x,i;
char c[300004],y;
int main()
{
    cin>>n>>m;
    for(i=1; i<=m; i++)
    {
        cin>>x>>y;
        c[x]=y;
    }
    for(i=1; i<=n; i++)
    {
        if(c[i]=='M')
        {
            cout<<"No"<<endl;
            return 0;
        }
    }
    for(i=1; i<=n; i++)
    {
        if(c[i]=='H')
        {
            if(i-3>=0)
            {
                if(c[i]=='S')
                {
                    cout<<"No"<<endl;
                    return 0;
                }
            }
            if(i-2>=0)
            {
                if(c[i]=='S')
                {
                    cout<<"No"<<endl;
                    return 0;
                }
            }
            if(i-1>=0)
            {
                if(c[i]=='S')
                {
                    cout<<"No"<<endl;
                    return 0;
                }
            }
            if(i>=0)
            {
                if(c[i]=='S')
                {
                    cout<<"No"<<endl;
                    return 0;
                }
            }
            if(i+1<=n)
            {
                if(c[i]=='S')
                {
                    cout<<"No"<<endl;
                    return 0;
                }
            }
            if(i+2<=n)
            {
                if(c[i]=='S')
                {
                    cout<<"No"<<endl;
                    return 0;
                }
            }
            if(i+3<=n)
            {
                if(c[i]=='S')
                {
                    cout<<"No"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"Yes"<<endl;
     return 0;
}