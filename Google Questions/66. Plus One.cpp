/*
### Intuition
The problem requires us to increment a number represented by a vector of digits. The key difficulty is handling carries, especially when the number contains a `9`, which rolls over to `0`. The challenge also involves properly adjusting the length of the vector when a carry extends beyond the most significant digit.

### Approach
1. **Simple Case**: If the last digit is less than `9`, we can simply increment it and return the vector as the result. This case doesn't require handling carries, as no digit overflows.
2. **Carry Handling**: When the last digit is `9`, it rolls over to `0` and a carry is propagated to the next significant digit. This process continues, and the algorithm needs to handle it until there is no further carry or we run out of digits.
3. **Final Adjustment**: If the carry propagates past the most significant digit (e.g., `999` becomes `1000`), we need to add a new digit at the beginning of the vector. 
4. **Reverse**: The vector is reversed twice—once to handle the carry from the least significant digit, and once more to restore the order after the calculation.

### Complexity
- **Time complexity**: 
  - The time complexity is \(O(n)\), where \(n\) is the size of the input vector. We iterate over the vector twice (once to process carries and once to reverse the vector).
  
- **Space complexity**: 
  - The space complexity is \(O(1)\) because the algorithm modifies the input vector in place, and we only use a constant amount of extra space.

### Code
```cpp
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& a) {
      int n = a.size();

      // Case where the last digit is less than 9, we simply increment and return
      if (a[n-1] <= 8) {
        a[n-1] += 1;
        return a;
      }

      // Reverse the vector to make carry handling easier
      reverse(a.begin(), a.end());

      int i = 0;
      // Propagate carry over
      while (i < n && a[i] == 9) {
        a[i] = 0;  // Set 9 to 0 and continue to the next digit
        i++;
      }

      // If there is still a digit to increment, do so
      if (i < n) {
        a[i] += 1;
      } else {
        // If all digits were 9, add a new digit at the end
        a.push_back(1);
      }

      // Reverse the vector back to original order
      reverse(a.begin(), a.end());
      return a;
    }
};
/*
```

### Explanation of Code:
1. **Initial check**: If the last digit is less than 9, we simply add 1 and return the result.
2. **Reversing**: The vector is reversed so that we can start processing the least significant digit (the end of the number).
3. **Carry propagation**: We process each digit in the reversed vector. If it’s `9`, we turn it to `0` and move the carry to the next digit. If a non-`9` digit is found, we increment it and stop.
4. **Adding a digit**: If we reach the end of the vector and all digits were `9` (like `999`), we add a `1` at the beginning (after reversing the list back to original order, it becomes `1000`).
5. **Reversing back**: The vector is reversed back to restore the original order, and we return the final result.

This solution efficiently handles edge cases (like all digits being `9`), and the time complexity is linear, \(O(n)\), which is optimal for this problem.

*/
