/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-10-28 21:16:43                      
*  solution_verdict: WA                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 3 ms                                            memory_used: 1280 KB                              
*  problem: https://atcoder.jp/contests/abc142/tasks/abc142_f
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int N;
bool adj[1002][1002];
vector <int> mode;
bool fin() {
    int i,j,cnt,siz=mode.size();
    for(i=0; i<siz; i++) {
        cnt=0;
        for(j=0; j<siz; j++) {
            if(adj[mode[i]][mode[j]])
                cnt++;
        }
        if(cnt!=1)
            return false;
    }
    return true;
}
 bool check(int j,int val) {
    if(adj[j][val])
    {
        mode.push_back(j);
        mode.push_back(val);
        if(fin())
        return true;
        else
        {
            mode.pop_back();mode.pop_back();
            return false;
        }
    }
     for(int k=j+1; k<=N; k++) {
        if(adj[j][k]){
                mode.push_back(j);
            if(check(k,val)) {
                return true;
            }
            else mode.erase(mode.end()-1);
        }
    }
    return false;
}
 int main() {
    int i,j,a,M,b;
    bool ch=false;
    scanf("%d %d",&N,&M);
    for(i=0; i<M; i++) {
        scanf("%d %d",&a,&b);
        adj[a][b]=true;
    }
    for(i=1; i<N; i++) {
        for(j=i+1; j<=N; j++) {
            if(adj[i][j]) {
                if(check(j,i)) {
                        ch=true;
                        break;
                 }
            }
        }
        if(ch)
            break;
    }
    if(!ch)
        printf("-1\n");
    else {
         int siz=mode.size();
        printf("%d\n",siz);
        for(i=siz-1; i>=0; i--)
            printf("%d\n",mode[i]);
    }
    return 0;
}