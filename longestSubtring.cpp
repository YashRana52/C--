#include <bits/stdc++.h>
using namespace std;

int solve(string s) {
    vector<int> lastIndex(256, -1);  
    int i = 0, maxLen = 0;

    for (int j = 0; j < s.size(); j++) {
        char c = s[j];

        if (lastIndex[c] >= i) {
            i = lastIndex[c] + 1;   
        }

        lastIndex[c] = j;  

        maxLen = max(maxLen, j - i + 1);
    }

    return maxLen;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    int len = solve(s);
    cout << "Longest substring length = " << len << endl;

    return 0;
}