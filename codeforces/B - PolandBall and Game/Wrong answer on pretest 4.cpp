/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/15/2017 23:36                        
*  solution_verdict: Wrong answer on pretest 4               language: GNU C++11                               
*  run_time: 15 ms                                           memory_used: 3000 KB                              
*  problem: https://codeforces.com/contest/755/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    char pola[1000][500],enmy[1000][500],temp,cnt,nn,mm;
    int n,m,i,j;
    while(scanf("%d%d",&n,&m)==2)
    {
        for(i=0;i<n;i++)scanf("%s",&pola[i]);
        for(i=0;i<m;i++)scanf("%s",&enmy[i]);
        cnt=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(pola[i]==enmy[j])cnt++;
            }
        }
        nn=n-cnt;
        mm=m-cnt;
        if(nn>mm)printf("YES\n");
        else if(mm>nn)printf("NO\n");
        else if(nn==mm)
        {
            if(n>=m)printf("YES\n");
            else printf("NO\n");
        }
       }
       return 0;
}