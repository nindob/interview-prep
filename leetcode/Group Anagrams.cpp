#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

// intuitive solution with O(m * nlogn) time complexity

// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {    
//         unordered_map<string, vector<string>> sorted_strs;
//         for (const string& str : strs) {
//             string sorted_str = str;
//             sort(sorted_str.begin(), sorted_str.end());
//             sorted_strs[sorted_str].push_back(str);
//         }
//         vector<vector<string>> result;
//         for (const auto& pair : sorted_strs) {
//             result.push_back(pair.second);
//         }
//         return result;
//     }
// };

// optimized solution with O(m * n) time complexity

// instead of sorting the words with sort() use the characters themselves for each word as the key we use for each word in strs
// take advantage of only 26 lowercase letter valid characters for each word so directly have character frequency for key
// do some ASCII manipulation if needed
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {    
        unordered_map<string, vector<string>> char_count;
        char_count.reserve(strs.size());
        for (const auto& str : strs) {
            int count[26] = {0};
            for (char c : str) {
                ++count[c - 'a'];
            }
            string key;
            key.reserve(26*2);
            for (int i = 0; i < 26; i++) {
                key += '#';
                key += char('0' + count[i]);
            }
            char_count[key].push_back(str);    
        }
        vector<vector<string>> result;
        result.reserve(char_count.size());
        for (auto& pair : char_count) {
            result.push_back(move(pair.second));
        }
        return result;
    }
};

