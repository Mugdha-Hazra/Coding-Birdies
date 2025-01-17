class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        vector<vector<int>>ans;
        sort(a.begin(),a.end());
        int f=a[0][0], b=a[0][1];
        for(int i=1;i<a.size();i++)
        {
            if(a[i][0]<=b)
                b=max(a[i][1],b);
            else{
                ans.push_back({f,b});
                f=a[i][0];
                b=a[i][1];
            }
        }
        ans.push_back({f,b});
        return ans;
    }
};
