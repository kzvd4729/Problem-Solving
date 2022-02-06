/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/24/2017 00:45                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 60 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/40/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
double x,y;
long d,f;
map<long,long>mp;
void fx(void)
{
    for(long i=1;i<=1000;i++)
    {
        mp[i*i]=1;
    }
}
double dis(double x,double y,double x1,double y1)
{
    if(mp[(x-x1)*(x-x1)+(y-y1)*(y-y1)]==1)
    {
        f=1;
    }
    return sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     fx();
    cin>>x>>y;
    f=0;
    d=dis(x,y,0,0);
    if(x==0||y==0)
    {
        cout<<"black"<<endl;
    }
    else if(f==1)
    {
        f=0;
        dis(x,y,x,0);
        if(f==1)cout<<"black"<<endl;
        else cout<<"white"<<endl;
    }
    else if((x>0&&y>0)||(x<0&&y<0))
    {
        if(d%2==0)
        {
            cout<<"black"<<endl;
        }
        else cout<<"white"<<endl;
    }
    else
    {
        if(d%2==0)
        {
            cout<<"white"<<endl;
        }
        else cout<<"black"<<endl;
    }
    return 0;
}