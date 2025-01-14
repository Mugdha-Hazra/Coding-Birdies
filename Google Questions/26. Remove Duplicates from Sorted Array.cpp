/*### Intuition
The problem asks us to remove duplicates from a sorted array. Since the array is already sorted, we can leverage the fact that duplicates will be adjacent to each other. By scanning through the array, we can use two pointers (`i` and `j`) to track the position of the last unique element and the current element, respectively. If we find a new unique element (i.e., `a[i] != a[j]`), we update the position of the unique element and move the pointer `i`.

### Approach
1. **Edge Case Handling**: If the size of the array is less than or equal to 1, we can immediately return the size since there are no duplicates to remove.
2. **Two Pointers**:
   - Pointer `i` will point to the last unique element.
   - Pointer `j` will iterate through the array starting from the second element.
   - If `a[i] != a[j]`, it means we've found a new unique element, so we move `i` forward and set `a[i] = a[j]`.
   - Finally, the length of the unique elements will be `i + 1`.
3. **Return**: The function should return the number of unique elements.

### Complexity
- **Time complexity**: $$O(n)$$, where \(n\) is the length of the array. We traverse the array once with the `j` pointer.
- **Space complexity**: $$O(1)$$, since we modify the array in place without using any extra space.

### Code

```cpp
*/
class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int i = 0, j = 1, n = a.size();
        if (n <= 1)
            return n;  // If the array has one or fewer elements, it's already unique
        
        while (j < n) {  // Ensure j is within bounds
            if (a[i] != a[j]) {  // Found a unique element
                i++;  // Move i to the next position
                a[i] = a[j];  // Copy the unique element
            }
            j++;  // Move j to continue scanning
        }
        
        return i + 1;  // The length of the array without duplicates
    }
};

/*
```

### Explanation:
- **Pointers**: We use two pointers, `i` and `j`, to scan the array. `i` tracks the last unique element's index, and `j` scans each element.
- **Unique Element Check**: When `a[i] != a[j]`, we have encountered a new unique element. We increment `i` and move that unique element to `a[i]`.
- **Final Length**: The number of unique elements is `i + 1` because `i` tracks the index of the last unique element.

### Example:
For the input array `[1, 1, 2, 2, 3]`:
1. Initially: `i = 0`, `j = 1`
2. At `j = 2`, `a[i] != a[j]`, so increment `i`, set `a[i] = a[j]` → array becomes `[1, 2, 2, 2, 3]`.
3. At `j = 3`, `a[i] == a[j]`, so continue.
4. At `j = 4`, `a[i] != a[j]`, so increment `i`, set `a[i] = a[j]` → array becomes `[1, 2, 3, 2, 3]`.
5. The final array with unique elements is `[1, 2, 3]`, and the function returns 3.

*/
