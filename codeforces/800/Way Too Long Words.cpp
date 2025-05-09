#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;

        if (word.length() > 10) {
            cout << word[0] << word.length() - 2 << word[word.length() - 1] << endl;
        }
        else {
            cout << word << endl;
        }
    }

    return 0;
}

// this problem is a good review on how to take in multiple inputs determined by some integer
// to solve the problem we can take advantage of the string library to use length() for each word
// we check if the word length is strictly greater than 10 and then we print the first letter (word[0])
// we print the number of letters between first and last letter (word.length() - 2) and then
// we print the last letter, which factoring starting from 0 index, is word[word.length() - 1]
// if the word length is not strictly greater than 10, we just print the word as is