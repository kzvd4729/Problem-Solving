/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/26/2017 17:55                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 30 ms                                           memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/779/problem/A
****************************************************************************************/
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int n,i,s1[103],s2[103],c1[10],c2[10],flag,dif[10],sum;
    while(cin>>n)
    {
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        for(i=0;i<n;i++)
        {
            cin>>s1[i];
            c1[s1[i]]++;
         }
        for(i=0;i<n;i++)
        {
            cin>>s2[i];
            c2[s2[i]]++;
         }
         flag=0;
        for(i=1;i<=5;i++)
        {
            if((c1[i]+c2[i])%2==1)
            {
                cout<<-1<<endl;
                flag=1;
                break;
            }
        }
        sum=0;
        if(flag==0)
        {
            for(i=1;i<=5;i++)
            {
                dif[i]=(c1[i]-c2[i]);
                if(dif[i]<=0)dif[i]=0;
                sum=sum+dif[i];
            }
            cout<<sum/2<<endl;
        }
      }
      return 0;
}