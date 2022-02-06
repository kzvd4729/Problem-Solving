/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/03/2018 23:08                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 62 ms                                           memory_used: 3300 KB                              
*  problem: https://codeforces.com/contest/959/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,cnt,nn;
int main()
{
  scanf("%d",&n);
   if(n==6)
  {
    printf("1 2\n");
    printf("2 3\n");
    printf("3 4\n");
    printf("3 5\n");
    printf("2 6\n");
     n--;
    cnt=1;
    while(n--)
    {
      printf("%d %d\n",cnt,cnt+1);
      cnt++;
    }
    return 0;
   }
  if(n==7)
  {
    printf("1 2\n");
    printf("2 3\n");
    printf("3 4\n");
    printf("3 5\n");
    printf("2 6\n");
    printf("2 7\n");
     n--;
    cnt=1;
    while(n--)
    {
      printf("%d %d\n",cnt,cnt+1);
      cnt++;
    }
    return 0;
  }
   if(n<8)
  {
    n--;
    printf("-1\n");
    cnt=1;
    while(n--)
    {
      printf("%d %d\n",cnt,cnt+1);
      cnt++;
    }
  }
  else
  {
    nn=n;
    nn--;
    printf("1 2\n");
    printf("1 3\n");
    printf("2 4\n");
    printf("2 5\n");
    printf("3 6\n");
    printf("4 7\n");
    printf("4 8\n");
    nn-=7;
    cnt=8;
    while(nn--)
    {
      printf("%d %d\n",4,++cnt);
    }
    n--;
    cnt=1;
    while(n--)
    {
      printf("%d %d\n",cnt,cnt+1);
      cnt++;
    }
  }
  return 0;
}