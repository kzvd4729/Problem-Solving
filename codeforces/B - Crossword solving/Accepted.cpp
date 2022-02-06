/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/06/2017 19:43                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/822/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n,m,mx,l;
char s[1003],t[1003];
int match(int id)
{
    int i,j,cnt=0;
    j=1;
    for(i=id;i<=id+n-1;i++)
    {
        if(s[j]==t[i])cnt++;
        j++;
    }
    return cnt;
}
int main()
{
    cin>>n>>m;
    int i,x,j;
    for(i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    for(i=1;i<=m;i++)
    {
        cin>>t[i];
    }
    l=1;
    for(i=1;i<=m;i++)
    {
        if(i-1+n<=m)
        {
            x=match(i);
            if(x>mx)
            {
                mx=x;
                l=i;
            }
        }
    }
    cout<<n-mx<<endl;
    j=1;
    for(i=l;i<=l+n-1;i++)
    {
        if(s[j]!=t[i])cout<<j<<" ";
        j++;
    }
    cout<<endl;
    return 0;
}