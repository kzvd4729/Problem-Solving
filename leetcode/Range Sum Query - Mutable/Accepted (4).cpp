/****************************************************************************************
*  @author: kzvd4729                                         created: 06/18/2021 16:51                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 392 ms                                          memory_used: 150.6 MB                             
*  problem: https://leetcode.com/problems/range-sum-query-mutable
****************************************************************************************/
class NumArray {
public:
    vector<int>bit,a;
        void upd(int id,int vl)
    {
        for( ;id<(int)bit.size();id+=id&-id)bit[id]+=vl;
    }
    int get(int id)
    {
        int ret=0;
        for( ;id>0;id-=id&-id)ret+=bit[id];
                return ret;
    }
        NumArray(vector<int>& _a) 
    {
        a=_a;
        int n=a.size();
                bit.resize(n+1,0);
        for(int i=0;i<n;i++)upd(i+1,a[i]);
    }
        void update(int i, int vl) 
    {
        upd(i+1,vl-a[i]);
        a[i]=vl;
    }
        int sumRange(int l, int r) 
    {
        return get(r+1)-get(l);
    }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */