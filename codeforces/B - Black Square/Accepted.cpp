/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/12/2017 00:06                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/828/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
char mat[110][110];
int n,m,i,j,f,up,down,lft,rght,sq,cnt,len,hig,dif;
int main()
{
    cin>>n>>m;
    f=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cin>>mat[i][j];
            if(mat[i][j]=='B')f=1;
        }
    }
    if(f==0)
    {
        cout<<1<<endl;
        return 0;
    }
    f=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(mat[i][j]=='B')
            {
                up=i;
                f=1;
                break;
            }
        }
        if(f==1)break;
    }
     ///cout<<up<<endl;
     f=0;
    for(i=n;i>=1;i--)
    {
        for(j=1;j<=m;j++)
        {
            if(mat[i][j]=='B')
            {
                down=i;
                f=1;
                break;
            }
        }
        if(f==1)break;
    }
     f=0;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(mat[j][i]=='B')
            {
                lft=i;
                f=1;
                break;
            }
        }
        if(f==1)break;
    }
     f=0;
     for(i=m;i>=1;i--)
    {
        for(j=1;j<=n;j++)
        {
            if(mat[j][i]=='B')
            {
                rght=i;
                f=1;
                break;
            }
        }
        if(f==1)break;
    }
    ///cout<<lft<<rght<<up<<down<<endl;
    len=abs(rght-lft)+1;
    hig=abs(down-up)+1;
    sq=max(len,hig);
    int g=min(n,m);
    if(sq>g)
    {
        cout<<-1<<endl;
        return 0;
    }
    cnt=0;
    for(i=up;i<=down;i++)
    {
        for(j=lft;j<=rght;j++)
        {
            if(mat[i][j]=='W')cnt++;
        }
    }
    if(len==hig)
    {
        cout<<cnt<<endl;
        return 0;
    }
    if(len<hig)
    {
        dif=hig-len;
        cnt=cnt+(hig*dif);
        cout<<cnt<<endl;
        return 0;
    }
    if(hig<len)
    {
        dif=len-hig;
        cnt=cnt+(len*dif);
        cout<<cnt<<endl;
        return 0;
    }
    return 0;
}