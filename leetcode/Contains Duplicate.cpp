#include <vector>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> nums_map;
        for (int i = 0; i < nums.size(); i++) {
            nums_map[nums[i]]++;
            if (nums_map[nums[i]] > 1) {
                return true;
            }
        }
        return false;
    }
};

// if you know your common data structures this problem is pretty straightforward, otherwise it's tricky on first glance
// a naive approach would be to use a nested for loop
// your outer loop would start from the first index and your inner for loop would iterate through rest of the numbers
// then update outer for loop and repeat the process until we've exhuasted the entire array
// you end up with O(n^2) time complexity because inner loop does O(n) work for each iteration of the outer loop
// which gives n * n => O(n^2) time complexity 

// the better approach, which is what I did, was to use a hash map through unordered_map in C++
// our keys and values are both type int as each integer (key) has a unique frequency count (value)
// we iterate through the nums array and for each element we check if it's already a key in the hash map
// if it is then the frequency associated it with it gets incremented by 1 for each occurance of the key in the array
// if the key did not previously exist in the hash map, then the new key arr[i] gets added and since the
// value is of type int, it has a default value of 0 which gets incremented to 1 by the ++ operator
// we check for each key if the frequency is greater than 1, which means we have a duplicate and we return true
// otherwise return false out of the for loop
// time complexity is O(n) because we only iterate through n elements in the array once and insertion/lookup
// in a hash map is (assuming a well designed hash map) O(1) time complexity

// slightly unnecessary but you could argue you could also make a set of the nums array
// then compare the size of the original nums array vector and the set
// if the set size is less than the nums array size, then there must be duplicates so return true
// else return false
// turns out that while this is also O(n) and arguably more intuitive with a very basic mathematical background
// it turns out that std::set is implemented as a red-black tree which has O(logn) time complexity for insertion/lookup
// which actually makes this slower than the hash map implementation
// explains why using the set approach I only beat in 5% submissions in execution time lol