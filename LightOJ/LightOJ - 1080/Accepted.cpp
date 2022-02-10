/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-07-28 01:29:31                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 240                                        memory_used (MB): 2.2                             
*  problem: https://vjudge.net/problem/LightOJ-1080
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int t,tc,q,bit[100005],l,r,n,x1,x;
char s[100005];
char c;
void upd(int id)
{
    for( ; id<=n;id+=id&-id)
    {
        bit[id]++;
    }
}
int get(int id)
{
    int sum=0;
    for( ; id>0;id-=id&-id)
    {
        sum+=bit[id];
    }
    return sum;

}
int main()
{
    scanf("%d",&t);
    tc=0;
    while(t--)
    {
        memset(bit,0,sizeof(bit));
        scanf("%s",&s);
        n=strlen(s);
        printf("Case %d:\n",++tc);
        scanf("%d",&q);
        while(q--)
        {
            getchar();
            scanf("%c",&c);
            if(c=='I')
            {
                scanf("%d%d",&l,&r);
                upd(l);
                upd(r+1);
            }
            else
            {
                scanf("%d",&x1);
                x=get(x1);
                if(x%2==1)
                {
                    if(s[x1-1]=='0')printf("1\n");
                    else printf("0\n");
                }
                else printf("%c\n",s[x1-1]);
            }

        }

    }
    return 0;
}