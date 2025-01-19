class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        bool fc=false,fr=false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][0]==0)
                fr=true;
                if(a[0][j]==0)
                fc=true;
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(a[i][j]==0)
                {
                    a[0][j]=0;
                    a[i][0]=0;
                }
            }
        }
        for(int i=1;i<n;i++)
        {
            for (int j=1;j<m;j++)
            {
                if(a[i][0]==0||a[0][j]==0) 
                    a[i][j]=0;
            }
        }
        if(fc==true)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    a[0][j]=0;
                }
            }
        }
         if(fr==true)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    a[i][0]=0;
                }
            }
        }
    }
};
