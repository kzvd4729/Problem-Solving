/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/24/2017 21:51                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 264 ms                                          memory_used: 2200 KB                              
*  problem: https://codeforces.com/contest/832/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int i,l1,l2,q,star,f;
char g[30],str[100005],qq[100005];
map<char,int>gd;
int main()
{
    cin>>g;
    for(i=0; i<strlen(g); i++)
    {
        gd[g[i]]=1;
    }
    cin>>str;
    l1=strlen(str);
    star=-1;
    for(i=0; i<l1; i++)
    {
        if(str[i]=='*')
        {
            star=i;
            break;
        }
    }
     cin>>q;
    while(q--)
    {
        cin>>qq;
        l2=strlen(qq);
        f=0;
        if(star==-1)
        {
            if(l1!=l2)
            {
                cout<<"NO"<<endl;
                continue;
            }
            for(i=0; i<l1; i++)
            {
                if(str[i]!=qq[i])
                {
                    if(str[i]!='?')
                    {
                        f=1;
                        break;
                    }
                    if(gd[qq[i]]!=1)
                    {
                        f=1;
                        break;
                    }
                }
            }
            if(f==1)
            {
                cout<<"NO"<<endl;
                continue;
            }
         }
        if(l2<l1-1)
        {
            cout<<"NO"<<endl;
            continue;
        }
        for(i=0; i<star; i++)
        {
            if(str[i]!=qq[i])
            {
                if(str[i]!='?')
                {
                    f=1;
                    break;
                }
                if(gd[qq[i]]!=1)
                {
                    f=1;
                    break;
                }
            }
        }
        if(f==0)
        {
            ///l1baki=l1-star-1;
            int id=l2;
            for(i=l1-1; i>star; i--)
            {
                id--;
                if(str[i]!=qq[id])
                {
                    if(str[i]!='?')
                    {
                        f=1;
                        break;
                    }
                    if(gd[qq[id]]!=1)
                    {
                        f=1;
                        break;
                    }
                }
             }
            if(f==0)
            {
                for(i=star; i<id; i++)
                {
                    if(gd[qq[i]]==1)
                    {
                        f=1;
                        break;
                    }
                }
            }
          }
        if(f==1)
        {
            cout<<"NO"<<endl;
        }
        else cout<<"YES"<<endl;
     }
     return 0;
}