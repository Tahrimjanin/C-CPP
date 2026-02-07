/*
A haiku poem consists of 17 syllables split into three phrases, containing 5, 7 and 5 syllables correspondingly (the first phrase should 
contain exactly 5 syllables, the second phrase should contain exactly 7 syllables, and the third phrase should contain exactly 5 syllables). 
A haiku masterpiece contains a description of a moment in those three phrases. Every word is important in a small poem, which is why haiku are 
rich with symbols. Each word has a special meaning, a special role. The main principle of haiku is to say much using a few words.
To simplify the matter, in the given problem we will consider that the number of syllable in the phrase is equal to the number of vowel
 letters there. Only the following letters are regarded as vowel letters: "a", "e", "i", "o" and "u".
Three phases from a certain poem are given. Determine whether it is haiku or not.

Input
The input data consists of three lines. The length of each line is between 1 and 100, inclusive. The i-th line contains the i-th phrase 
of the poem. Each phrase consists of one or more words, which are separated by one or more spaces. A word is a non-empty sequence of 
lowercase Latin letters. Leading and/or trailing spaces in phrases are allowed. Every phrase has at least one non-space character.
 See the example for clarification.

 on  codeforces 
beta round is running
   a rustling of keys 

Output
Print "YES" (without the quotes) if the poem is a haiku. Otherwise, print "NO" (also without the quotes).

YES

*/

#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
   
    return (c == 'a' || c == 'o' || c == 'e' || c == 'u' || c == 'i');
}

int vowelcount(const string& s) {
    int count = 0;
    for (char c : s) {
        if (isVowel(c)) {
            count++;
        }
    }
    return count;
}

int main(){
    string s1, s2, s3;
    getline(cin, s1);
    getline(cin, s2);
    getline(cin, s3);

 if  (vowelcount(s1) == 5 && vowelcount(s2) == 7 && vowelcount(s3) == 5) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;

}