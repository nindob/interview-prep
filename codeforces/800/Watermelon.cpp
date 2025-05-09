#include <iostream>

using namespace std;

int main() {
    int w;
    cin >> w;

    if (w % 2 == 0 && w > 2) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    
    return 0;
}

// after reading the problem, it is pretty clear that
// the answer is YES if w even (mod 2 == 0) and NO if w is odd (mod 2 != 0)
// only edge case if w == 2 where we print NO because we cannot split the watermelon into two even parts (1 and 1)

