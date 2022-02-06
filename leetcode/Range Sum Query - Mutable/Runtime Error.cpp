/****************************************************************************************
*  @author: kzvd4729                                         created: 07/18/2021 00:13                         
*  solution_verdict: Runtime Error                           language: cpp                                     
*  run_time: N/A                                             memory_used: N/A                                  
*  problem: https://leetcode.com/problems/range-sum-query-mutable
****************************************************************************************/
class NumArray 
{
public:
        vector<int>sg;int n;
        void build(int nd,int lo,int hi,vector<int>& nums)
    {
        if(lo==hi)
        {
            sg[nd]=nums[lo];
            return ;
        }
                int md=(lo+hi)/2;
        build(nd*2,lo,md,nums);build(nd*2+1,md+1,hi,nums);
                sg[nd]=sg[nd*2]+sg[nd*2+1];
    }
        void upd(int nd,int lo,int hi,int id,int nm)
    {
        if(lo==hi)
        {
            sg[nd]=nm;
            return ;
        }
                int md=(lo+hi)/2;
                if(id<=md)upd(nd*2,lo,md,id,nm);
        else upd(nd*2+1,md+1,hi,id,nm);
                sg[nd]=sg[nd*2]+sg[nd*2+1];
    }
    int get(int nd,int lo,int hi,int lt,int rt)
    {
        if(lo>rt || hi<lt)return 0;
        if(lo>=lt && hi<=rt)return sg[nd];
                        int md=(lo+hi)/2;
                return get(nd*2,lo,md,lt,rt)+get(nd*2+1,md+1,hi,lt,rt);
    }
            NumArray(vector<int>& nums) 
    {
        n=nums.size();
        sg.resize(n+8);
                build(1,0,n-1,nums);
            }
        void update(int index, int val) 
    {
        upd(1,0,n-1,index,val);
    }
        int sumRange(int left, int right) 
    {
        return get(1,0,n-1,left,right);
    }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */