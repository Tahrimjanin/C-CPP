/*
Lexicographical order is often known as alphabetical order when dealing with strings.
It is similar to the order in which strings are arranged in a dictionary. A string is greater than another string if it comes later in a 
lexicographically sorted list.Gaurav has a simple problem for which he needs your help. 
Given a word, create a new word by swapping some or all of its characters. This new word must meet two criteria:
It must be greater than the original word
 It must be the smallest word that meets the first condition
For example, given the word w=abcd, the next largest word is w=abdc.
Basically, Gaurav needs to find the smallest string which is lexographically greater than the given string using the same character
s present in the input string.

Input Format:
The first line of input contains ,T the number of test cases.
Each of the next T lines contains a string w.
Constraints:
1<=T<=10^5
1<=|w|<=100
string w will contain only letters in the range ascii[a..z].

3
abcd
adeg
dcba

Output Format: 
For each test case, output the string meeting the criteria. If no answer exists, print no answer.

abdc
adge
no answer

*/
#include <bits/stdc++.h>
using namespace std;

int getModIndex(const string &s) {
    int n = s.size();
    for (int i = n - 2; i >= 0; --i) {
        if (s[i] < s[i + 1]) {
            return i; // first decreasing point from right
        }
    }
    return -1; 
}

int getSwapIndex(const string &s, int modIndex) {
    char target = s[modIndex];
    int n = s.size();
    for (int i = n - 1; i > modIndex; --i) {
        if (s[i] > target) {
            return i; // smallest char greater than s[modIndex] from right side
        }
    }
    return -1; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        int modIndex = getModIndex(s);
        if (modIndex == -1) {
            cout << "no answer\n";
        } else {
            int swapIndex = getSwapIndex(s, modIndex);
            swap(s[modIndex], s[swapIndex]);
            sort(s.begin() + modIndex + 1, s.end()); // sort right part to get smallest greater
            cout << s << "\n";
        }
    }
    return 0;
}
