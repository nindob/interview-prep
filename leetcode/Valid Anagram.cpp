#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// solution 1: use sort()

// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         sort(s.begin(), s.end());
//         sort(t.begin(), t.end());
//         if (s != t) {
//             return false;
//         }
//         return true;
//     }
// };

// solution 2: use hash map

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        unordered_map<char, int> countS;
        unordered_map<char, int> countT;

        for (int i = 0; i < s.length(); i++) {
            countS[s[i]]++;
        }

        for (int i = 0; i < t.length(); i++) {
            countT[t[i]]++;
        }

        if (countS != countT) {
            return false;
        }

        return true;
    }
};

// in the first solution, the idea is to apply the built in sort() function to both strings
// if they are exactly the same, this implies same length for both strings and exactly the same letters
// this means they are anagrams and if they are not exactly the same after sorting
// they are not anagrams
// time complexity is O(nlogn) because sort() is really just an implementation of
// https://en.wikipedia.org/wiki/Comparison_sort
// tldr: we do a comparison sort which is O(nlogn) time complexity

// in the second solution, we have a hash map for each string that counts the frequency of each letter
// note that the first check of the base strings being the same length is not strictly needed (can be removed)
// using a for loop to iterate through the lengths of each string, we increment the hash map
// if we see a letter for the first time that key gets added and value intialized with 1 otherwise the value goes up
// then we compare the two hash maps and if they are not exactly the same this implies they are not anagrams
// otherwise they are anagrams