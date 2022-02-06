/****************************************************************************************
*  @author: kzvd4729#                                        created: Mar/24/2017 17:15                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/787/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,b,c,d,k,v,i,j,cnt,f;
    while(cin>>a>>b>>c>>d)
    {
         k=0;
        v=0;
        i=b;
        j=d;
        cnt=0;
        f=0;
        //cout<<i<<endl<<j<<endl;
        while(1)
        {
            for(i=i;  ;i=b+(a*k))
            {
                k++;
                cnt++;
                //cout<<i<<endl;
                if(i>=j)break;
              }
            k--;
            if(i>100000000000000)break;
            if(i==j)
            {
                f=1;
                break;
            }
            for(j=j;  ;j=d+(c*v))
            {
                v++;
                cnt++;
                //cout<<j<<endl;
                if(j>=i)break;
              }
            v--;
            if(j>100000000000000)break;
            if(i==j)
            {
                f=1;
                break;
            }
             if(cnt>1000000)break;
         }
         if(f==1)cout<<i<<endl;
        else cout<<-1<<endl;
      }
    return 0;
}