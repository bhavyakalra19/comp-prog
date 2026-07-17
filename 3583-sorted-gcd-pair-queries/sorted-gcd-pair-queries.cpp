#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = 0;
        for (int x : nums) {
            mx = max(mx, x);
        }

        // Step 1: Count frequency of each number in the array
        vector<int> freq(mx + 1, 0);
        for (int x : nums) {
            freq[x]++;
        }

        // Step 2: Calculate how many pairs have a GCD that is a MULTIPLE of i.
        // We use long long to prevent integer overflow.
        vector<long long> countGcd(mx + 1, 0);
        for (int i = 1; i <= mx; i++) {
            long long multiples = 0;
            // Jump by i to find all multiples (i, 2i, 3i...)
            for (int j = i; j <= mx; j += i) {
                multiples += freq[j];
            }
            // nC2 formula: pairs from the available multiples
            countGcd[i] = multiples * (multiples - 1) / 2;
        }

        // Step 3: Iterate backwards to filter down to EXACT GCD matches.
        // We subtract the pairs that resulted in a larger multiple.
        for (int i = mx; i >= 1; i--) {
            for (int j = 2 * i; j <= mx; j += i) {
                countGcd[i] -= countGcd[j];
            }
        }

        // Step 4: Build a prefix sum array of the exact counts
        vector<long long> prefix(mx + 1, 0);
        for (int i = 1; i <= mx; i++) {
            prefix[i] = prefix[i - 1] + countGcd[i];
        }

        // Step 5: Answer queries using std::upper_bound
        vector<int> result;
        result.reserve(queries.size());
        
        for (long long q : queries) {
            // upper_bound finds the first element strictly greater than q
            // Because our query is 0-indexed, if q=0 and prefix[1]=5, 
            // it immediately correctly lands on index 1.
            auto it = upper_bound(prefix.begin(), prefix.end(), q);
            result.push_back(distance(prefix.begin(), it));
        }

        return result;
    }
};