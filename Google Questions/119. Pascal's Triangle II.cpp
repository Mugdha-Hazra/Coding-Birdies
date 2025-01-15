class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vi(rowIndex + 1);   // Create a vector of size rowIndex + 1
        vi[0] = 1;                       // The first element in any row is always 1
        
        // This loop fills the row
        for (int i = 0; i <= rowIndex; ++i) {
            for (int j = i; j > 0; --j) {
                vi[j] += vi[j - 1];   // Add the value of the previous element in the row
            }
        }
        
        return vi;
    }
};

