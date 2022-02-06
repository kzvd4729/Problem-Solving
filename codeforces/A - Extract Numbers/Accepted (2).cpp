/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/25/2017 01:51                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 9400 KB                              
*  problem: https://codeforces.com/contest/600/problem/A
****************************************************************************************/
#include<iostream>
#include<string>
using namespace std;
string s,x[100008];
string a[100008],b[100008];
int main()
{
    int i,j,k,f,m,l,len,u,v;
    while(getline(cin,s))
    {
        l=s.size();
        k=0;
        f=0;
        for(i=0;i<=l;i++)
        {
            if(f==0)m=i;
            if(s[i]==','||s[i]==';'||i==l)
            {
                x[++k]=s.substr(m,i-m);
                f=0;
            }
            else f=1;
        }
         /*for(i=1;i<=k;i++)
        {
            cout<<x[i]<<endl;
        }*/
         f=0;
        u=0;
        v=0;
        for(i=1;i<=k;i++)
        {
            len=x[i].size();
            if(len==0)
            {
                f=1;
            }
            else
            {
                for(j=0;j<len;j++)
                {
                    if(x[i][j]>='0'&&x[i][j]<='9')
                    {
                        f=0;
                    }
                    else
                    {
                        f=1;
                        break;
                    }
                }
             }
            if(f==0&&len>=2)
            {
                if(x[i][0]=='0')
                {
                    f=1;
                }
            }
            if(f==0)
            {
                a[++u]=x[i];
            }
            else if(f==1)
            {
                b[++v]=x[i];
            }
         }
         if(u==0)cout<<"-";
        else
        {
            for(i=1;i<=u;i++)
            {
                if(i==1)cout<<"\"";
                cout<<a[i];
                if(i==u)cout<<"\"";
                else cout<<",";
            }
         }
        cout<<endl;
         if(v==0)cout<<"-";
        else
        {
            for(i=1;i<=v;i++)
            {
                if(i==1)cout<<"\"";
                cout<<b[i];
                if(i==v)cout<<"\"";
                else cout<<",";
            }
         }
        cout<<endl;
     }
    return 0;
}