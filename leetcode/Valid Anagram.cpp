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