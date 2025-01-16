/*

### Problem Explanation:

The problem asks you to find the minimum number of days you need to wait in order to create a certain number of bouquets, given a list of bloom days for flowers in a garden. Each bouquet requires `k` **adjacent** flowers, and you can only use flowers that have already bloomed.

### Input:

- `bloomDay`: An array where each element represents the day a particular flower will bloom.
- `m`: The number of bouquets you need to create.
- `k`: The number of flowers required in each bouquet.

### Output:

- Return the minimum number of days you need to wait to make `m` bouquets. If it's impossible, return `-1`.

### Key Observations:
1. **Basic Feasibility**:
   - If `m * k` (the total number of flowers needed) is greater than the number of flowers in the garden (`len(bloomDay)`), it's impossible to make the bouquets. In this case, return `-1`.

2. **Binary Search Approach**:
   - Since we are looking for the minimum number of days, a binary search is an efficient approach. The range of possible answers spans from day `1` to the maximum bloom day in `bloomDay`. We want to determine the smallest day such that we can form `m` bouquets.

3. **Flower Counting**:
   - For a given day, we need to check how many adjacent flowers have bloomed. If the count of adjacent bloomed flowers reaches `k`, we can form a bouquet. Count the number of bouquets that can be made for that day, and see if it meets or exceeds `m`.

### Solution Explanation:

We apply a binary search on the possible "days" between `1` and `max(bloomDay)`. For each middle day, we check if it's possible to form `m` bouquets by using a helper function. If it's possible to form enough bouquets, we adjust the binary search range to look for smaller possible days. If not, we increase the number of days.

### Code Breakdown:

```cpp

*/


static int __star = []{
    ios_base::sync_with_stdio(0);  // Optimize input/output
    cin.tie(NULL), cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    int minDays(vector<int>& v, int m, int k) {
        if (m > v.size() / k) return -1;  // Not enough flowers to make m bouquets
        
        int l = 1, h = 1e9;  // Binary search range for the days (1 to max possible bloom day)
        
        while (l < h) {
            int mid = (l + h) / 2;  // Try to form bouquets on day 'mid'
            int n = 0, c = 0;  // n = number of bouquets formed, c = count of consecutive bloomed flowers

            // Loop through each flower's bloom day
            for (auto &i : v) {
                if (i <= mid) {  // If the flower blooms by day 'mid'
                    c++;  // Increment the count of consecutive bloomed flowers
                } else {
                    c = 0;  // Reset the count if the flower doesn't bloom by day 'mid'
                }
                
                if (c == k) {  // If we have enough adjacent flowers for a bouquet
                    n++;  // Form a bouquet
                    c = 0;  // Reset the count of consecutive flowers
                }
            }

            // If we can form at least 'm' bouquets, try to reduce the number of days
            if (n >= m) {
                h = mid;  // Search for smaller days
            } else {
                l = mid + 1;  // Increase the number of days
            }
        }

        return l;  // Return the smallest day where it's possible to form m bouquets
    }
};

/*
```

### Key Steps in the Code:

1. **Binary Search Setup**:
   - We initialize the binary search range with `l = 1` (the earliest possible bloom day) and `h = 1e9` (the maximum possible bloom day).

2. **Feasibility Check**:
   - For each `mid` day (middle of the binary search range), check how many bouquets can be formed if we only consider flowers that have bloomed by day `mid`.
   - For each flower, keep a count (`c`) of consecutive flowers that have bloomed. If this count reaches `k`, form a bouquet and reset the count.

3. **Adjust Binary Search**:
   - If we can form at least `m` bouquets by day `mid`, try to find an earlier possible day by moving the high boundary (`h = mid`).
   - If not, it means we need more days, so move the low boundary (`l = mid + 1`).

4. **Final Answer**:
   - The result will be the smallest day (`l`) where it's possible to form `m` bouquets.

### Example Walkthrough:

#### Example 1:
**Input**: `bloomDay = [1,10,3,10,2], m = 3, k = 1`

- Day 1: [x, _, _, _, _] — 1 bouquet
- Day 2: [x, _, _, _, x] — 2 bouquets
- Day 3: [x, _, x, _, x] — 3 bouquets (Answer = 3)

#### Example 2:
**Input**: `bloomDay = [1,10,3,10,2], m = 3, k = 2`

- We need 6 flowers, but only have 5 in total. Therefore, it's impossible to form 3 bouquets. Answer = -1.

#### Example 3:
**Input**: `bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3`

- After day 7, we can form one bouquet from the first 3 flowers, and another bouquet from the last 3 flowers. Answer = 12.

### Time Complexity:

- The binary search runs in `O(log(max bloom day))`, where `max bloom day` is at most `1e9`.
- For each binary search iteration, we check the feasibility by iterating over the flowers, which takes `O(n)` time, where `n` is the number of flowers.
- Overall time complexity: `O(n * log(max bloom day))`.

This solution is efficient enough given the constraints (`n` up to `10^5` and `max bloom day` up to `10^9`).

*/
