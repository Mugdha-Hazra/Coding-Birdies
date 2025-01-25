class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& a, int c) 
    {
        int s=0, n=a.size();
        for(int i=0;i<n;i++)
        {
            s=max(s,a[i]);
        }
        vector<bool>v;
        for(int i=0;i<n;i++)
        {
            if(a[i]+c>=s)
            v.push_back(true);
            else
            v.push_back(false);
        }
        return v;
        
    }
};
