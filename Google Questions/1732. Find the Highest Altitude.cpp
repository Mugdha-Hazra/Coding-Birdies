class Solution {
public:
    int largestAltitude(vector<int>& gain)
     { int n=gain.size(),m=0,s=0;
        for(int i=0;i<n;i++)
        {
           s+=gain[i];
           m=max(s,m);

        }
        return m;
    }
};
