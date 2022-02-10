/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-05-15 19:31:12                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1035
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define long long long int
long t,tc,n,i,j,x,fac[103][103],fc[103];
vector<long>v;
void prime_factorization(void)
{
    for(i=2;i<=100;i++)
    {
        x=i;
        while(x!=1)
        {
            for(j=2;j<=i;j++)
            {
                if(x%j==0)
                {
                    fac[i][j]++;
                    x=x/j;
                    break;
                }
            }
        }
    }
}
int main()
{
    prime_factorization();
    ///ios_base::sync_with_stdio(false);
    ///cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=2;i<=n;i++)
        {
            for(j=2;j<=i;j++)
            {
                fc[j]=fc[j]+fac[i][j];
            }
        }
        /*for(i=1;i<=10;i++)
        {
            cout<<fc[i]<<" ";
        }
        cout<<endl;*/
        for(i=2;i<=n;i++)
        {
            if(fc[i]>0)v.push_back(i);
        }
        cout<<"Case "<<++tc<<": "<<n<<" = ";
        for(i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ("<<fc[v[i]]<<")";
            if(i!=v.size()-1)cout<<" * ";
            else cout<<endl;
        }
        v.clear();
    }
    return 0;
}