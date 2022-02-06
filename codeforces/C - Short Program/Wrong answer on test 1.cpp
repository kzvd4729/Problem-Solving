/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/08/2017 00:14                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/879/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,arr[15],x,bin[15],id;
char c;
void convert(long x)
{
    id=0;
    memset(bin,0,sizeof(bin));
    while(x)
    {
        bin[++id]=x%2;
        x=x/2;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     for(long i=1;i<=10;i++)arr[i]=2;
    cin>>n;
    while(n--)
    {
        cin>>c>>x;
        convert(x);
        if(c=='|')
        {
            for(long i=1;i<=id;i++)
            {
                if(bin[i])arr[i]=1;
            }
        }
        else if(c=='^')
        {
            for(long i=1;i<=id;i++)
            {
                if(bin[i])
                {
                    if(arr[i]==2)arr[i]=3;
                    else if(arr[i]==3)arr[i]=2;
                    else arr[i]=arr[i]^1;
                }
            }
        }
        else
        {
            for(long i=1;i<=id;i++)
            {
                if(!bin[i])
                {
                    arr[i]=0;
                }
            }
        }
    }
    /*for(long i=1;i<=10;i++)cout<<arr[i];
    cout<<endl;*/
     cout<<2<<endl;
    long sum=0;
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