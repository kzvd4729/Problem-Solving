/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/21/2017 00:42                        
*  solution_verdict: Runtime error on pretest 5              language: GNU C++11                               
*  run_time: 15 ms                                           memory_used: 11800 KB                             
*  problem: https://codeforces.com/contest/768/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
char str[10000000];
int main()
{
    long long int n,l,r,p,i,z,k,j,m;
    while(cin>>n>>l>>r)
    {
        for(i=1; i<=51; i++)
        {
            if(pow(2,i)>n)
            {
                p=pow(2,i);
                break;
            }
        }
        z=p;
         while(n!=1)
        {
            if(n%2==1)str[p/2]='1';
            else str[p/2]='0';
            n=n/2;
            p=p/2;
         }
        str[1]='1';
        j=2;
        int f=1;
        int cnt=0;
        for(i=2;i<=z;i=pow(2,j))
        {
            m=pow(2,f);
            for(k=m-1;k>=1;k--)
            {
                str[++m]=str[k];
            }
            f++;
            j++;
         }
        for(k=l;k<=r;k++)
        {
            if(str[k]=='1')cnt++;
        }
        cout<<cnt<<endl;
    }
     return 0;
}