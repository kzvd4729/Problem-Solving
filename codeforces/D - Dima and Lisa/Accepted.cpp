/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/06/2018 19:44                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 218 ms                                          memory_used: 92500 KB                             
*  problem: https://codeforces.com/contest/584/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long vis[10000007],n;
vector<long>prime;
void seive(void)
{
    vis[0]=1;
    vis[1]=1;
    prime.push_back(2);
    for(long i=4;i<=10000000;i+=2)vis[i]=1;
    for(long i=3;i<=10000000;i+=2)
    {
        if(vis[i])continue;
        prime.push_back(i);
        for(long j=i*i;j<=10000000;j+=2*i)vis[j]=1;
    }
}
bool isprime(long x)
{
    if(x<0)return false;
    if(x<=10000000)
    {
        if(vis[x]==0)return true;
        else return false;
    }
    long lim=sqrt(x);
    if(x%2==0)return false;
    for(long i=3;i<=lim;i+=2)if(x%i==0)return false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    seive();
    cin>>n;
    if(isprime(n))
    {
        cout<<1<<endl<<n<<endl;
        return 0;
    }
    for(auto x:prime)
    {
        if(isprime(n-x))
        {
            cout<<2<<endl<<x<<" "<<n-x<<endl;
            return 0;
        }
    }
    for(int i=0;i<1000;i++)
    {
        for(int j=i;j<1000;j++)
        {
            long x=prime[i]+prime[j];
            if(isprime(n-x))
            {
                cout<<3<<endl<<prime[i]<<" "<<prime[j]<<" "<<n-x<<endl;
                return 0;
            }
        }
    }
    return 0;
}