/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/24/2017 17:59                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 15 ms                                           memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/777/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string S,M;
    int s,m,i,j,dif,d,cnt,x,y,c,flag=0;
    while(cin>>n)
    {
        cin>>S>>M;
         sort(S.begin(),S.end());
        sort(M.begin(),M.end());
         //cout<<S<<endl;
        //cout<<M<<endl;
        cnt=0;
        j=-1;
        for(i=0;i<n;i++)
        {
            x=S[i]-'0';
            for(j=j+1;j<n;j++)
            {
                y=M[j]-'0';
                 if(y>x)
                {
                    cnt++;
                    break;
                }
              }
          }
        //cout<<cnt<<endl;
        j=-1;
        c=0;
        for(i=0;i<n;i++)
        {
            x=S[i]-'0';
            flag=0;
            for(j=j+1;j<n;j++)
            {
                y=M[j]-'0';
                 if(y>=x)
                {
                    flag=1;
                     break;
                }
              }
            if(flag==0)c++;
          }
        cout<<c<<endl<<cnt<<endl;
       }
      return 0;
}