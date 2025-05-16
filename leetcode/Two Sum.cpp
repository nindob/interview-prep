#include <vector>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;

// solution 1: brute force with nested for loop O(n^2)
// this is intuitively what i thought of when i first read the problem


// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         for (int i = 0; i < nums.size(); i++) {
//             for (int j = i + 1; j < nums.size(); j++) {
//                 if (nums[i] + nums[j] == target) {
//                     return {i, j};
//                 }
//             }
//         }
//         return {};
//     }
// };

// solution 2 single pass hash map O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> nums_map;
        for (int i = 0; i < nums.size(); i++) {
            int difference = target - nums[i];
            if (nums_map.find(difference) != nums_map.end()) {
                return {nums_map[difference], i};
            }
            else {
                return {};
            }
        }
    }  
};

// in the first solution, the idea is to have an outer for loop that will start at nums[0]
// and then an inner for loop that will start at nums[1] by int j = i + 1 condition and then
// we check every single possible sum pair of nums[i] and nums[j], iterating the inner for loop
// until we get to the end of the nums array
// then we iterate the outer for loop and keep checking every possible sum
// eventually given the problem constraints, we will eventually find the guaranteed answer
// O(n^2) time complexity because worst case you would do n * n = n^2 work
// (iterating through the outer loop n times and for every pass iterating the inner loop n times)

// in the second solution, the natural challenge/idea is to figure out how to get the O(n^2) solution down to O(n)
// the idea is to make a hash map that will store all of the numbers we have seen so far as we iterate through
// the nums array with a for loop
// we calculate the difference between the target and the current number we are pointing to in the for loop
// and we then check if this difference is a key in the hash map (does the difference exist)
// note: HASH_MAP.find(VALUE) != HASH_MAP.end() is a way to check if a value exists or not where end() is an iterator
// that refers to one past the last element

// there does exist other solutions like a two pass hash map and two pointers but they weren't approaches
// i came up with at the live time of solving this problem and they're less efficent than the best case 
// one pass hash map solution anyways