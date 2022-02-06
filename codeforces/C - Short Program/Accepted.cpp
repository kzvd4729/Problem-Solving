/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/10/2017 12:42                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 187 ms                                          memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/879/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,x,arr[15],bin[15],id,sum;
char c;
void binary(long z)
{
    id=0;
    while(z)
    {
        bin[++id]=z%2;
        z/=2;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1;i<=10;i++)arr[i]=2;
    while(n--)
    {
        cin>>c>>x;
        binary(x);
        if(c=='|')
        {
            for(long i=1;i<=id;i++)
            {
                if(bin[i]==1)arr[i]=1;
            }
        }
        else if(c=='^')
        {
            for(long i=1;i<=id;i++)
            {
                if(bin[i]==1)
                {
                    if(arr[i]==0)arr[i]=1;
                    else if(arr[i]==1)arr[i]=0;
                    else if(arr[i]==2)arr[i]=3;
                    else if(arr[i]==3)arr[i]=2;
                }
            }
        }
        else
        {
            for(long i=1;i<=id;i++)
            {
                if(bin[i]==1)continue;
                arr[i]=0;
            }
            for(long i=id+1;i<=10;i++)arr[i]=0;
        }
    }
    cout<<4<<endl;
    sum=0;
    for(long i=1;i<=10;i++)
    {
        if(arr[i]==0)
        {
            sum+=pow(2,i-1);
        }
    }
    cout<<"| "<<sum<<endl;
    cout<<"^ "<<sum<<endl;
    sum=0;
    for(long i=1;i<=10;i++)
    {
        if(arr[i]==1)
        {
            sum+=pow(2,i-1);
        }
    }
    cout<<"| "<<sum<<endl;
    sum=0;
    for(long i=1;i<=10;i++)
    {
        if(arr[i]==3)
        {
            sum+=pow(2,i-1);
        }
    }
    cout<<"^ "<<sum<<endl;
     return 0;
}
 