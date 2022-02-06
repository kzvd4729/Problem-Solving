/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/18/2018 02:11                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1294 ms                                         memory_used: 8000 KB                              
*  problem: https://codeforces.com/contest/939/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long q,x,ty,mx,lo,hi,mid;
vector<long>v;
double cal(long id)
{
    ///cout<<v[id]<<" "<<mx<<" "<<id<<endl;
    double x=((double)v[id]+(double)mx)/(double)(id+2);
    return x;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>q;
    while(q--)
    {
        cin>>ty;
        if(ty==1)
        {
            cin>>x;
            mx=x;
            if(!v.size())v.push_back(mx);
            else v.push_back(v.back()+mx);
        }
        else
        {
            if(v.size()==1)cout<<0<<endl;
            else
            {
                lo=0;
                hi=v.size()-2;
                while((hi-lo)>3)
                {
                    mid=(lo+hi)/2;
                    if(cal(mid)<cal(mid+1))hi=mid;
                    else lo=mid;
                }
                double mn=99999999999;
                for(long i=lo; i<=hi; i++)
                {
                    mn=min(mn,cal(i));
                    ///cout<<cal(i)<<endl;
                }
                ///cout<<mn<<endl;
                cout<<setprecision(10)<<fixed<<mx-mn<<endl;
            }
        }
    }
    return 0;
}