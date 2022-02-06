/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/05/2017 19:14                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 4200 KB                              
*  problem: https://codeforces.com/gym/101375/problem/J
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n,m,x,i,h[300004],s[300004],flag;
char y;
int main()
{
    cin>>n>>m;
    for(i=1; i<=m; i++)
    {
        cin>>x>>y;
        if(y=='H')h[x]=1;
        if(y=='S')s[x]=1;
        if(y=='M')
        {
            flag=1;
        }
    }
    if(flag==1)
    {
        cout<<"No"<<endl;
        return 0;
    }
    for(i=1; i<=n; i++)
    {
        if(h[i]==1)
        {
            if(i-3>=1)
            {
                if(s[i-3]==1)
                {
                    cout<<"No"<<endl;
                    return 0;
                }
            }
            if(i-2>=1)
            {
                if(s[i-2]==1)
                {
                    cout<<"No"<<endl;
                    return 0;
                }
            }
            if(i-1>=1)
            {
                if(s[i-1]==1)
                {
                    cout<<"No"<<endl;
                    return 0;
                }
            }
            if(i>=1)
            {
                if(s[i]==1)
                {
                    cout<<"No"<<endl;
                    return 0;
                }
            }
            if(i+1<=n)
            {
                if(s[i+1]==1)
                {
                    cout<<"No"<<endl;
                    return 0;
                }
            }
            if(i+2<=n)
            {
                if(s[i+2]==1)
                {
                    cout<<"No"<<endl;
                    return 0;
                }
            }
            if(i+3<=n)
            {
                if(s[i+3]==1)
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