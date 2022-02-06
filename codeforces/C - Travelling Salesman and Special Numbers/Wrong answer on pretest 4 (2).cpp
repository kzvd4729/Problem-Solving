/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/21/2018 00:06                        
*  solution_verdict: Wrong answer on pretest 4               language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/914/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long cons=1000000007;
string s;
long l,cnt,sum,k,fac[1002];
vector<long>v;
long power(long x, long y, long p)
{
    long res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
long modInverse(long n, long p)
{
    return power(n, p-2, p);
}
long nCrModPFermat(long n, long r, long p)
{
    if (r==0)
        return 1;
    return (fac[n]* modInverse(fac[r], p) % p *
            modInverse(fac[n-r], p) % p) % p;
}
void factorial(void)
{
    fac[0]=1;
    for(long i=1; i<=1000; i++)
    {
        fac[i]=(fac[i-1]*i)%cons;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     factorial();
    cin>>s;
    cin>>k;
    l=s.size();
     for(long i=1; i<=1000; i++)
    {
        long x=i,cnt=0;
        while(true)
        {
            if(x==1)
                break;
            x= __builtin_popcount(x);
            cnt++;
        }
        if(cnt==k-1)
            v.push_back(i);
    }
    long sum=0;
     for(long i=0; i<v.size(); i++)
    {
        long xx=v[i];
        if(xx>=l)
            continue;
        ///cout<<xx<<endl;
        for(long j=0; j<l; j++)
        {
            if(s[j]=='0')
                continue;
            if(xx==0)
                break;
            sum=(sum+nCrModPFermat(l-j-1,xx,cons))%cons;
            xx--;
        }
        sum=(sum+1)%cons;
    }
//    long f=0;
//    for(long i=0;i<l;i++)
//    {
//        if(s[i]=='0')f=1;
//    }
//    if(f==0)sum++;
    cout<<sum%cons<<endl;
    return 0;
}
 