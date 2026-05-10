/*A. String Task

Petya started to attend programming lessons. On the first lesson his task was to write a simple program. The program was supposed to do the following: in the given string, consisting if uppercase and lowercase Latin letters, it:

deletes all the vowels,
inserts a character "." before each consonant,
replaces all uppercase consonants with corresponding lowercase ones.
Vowels are letters "A", "O", "Y", "E", "U", "I", and the rest are consonants. The program's input is exactly one string, it should return the output as a single string, resulting after the program's processing the initial string.

Help Petya cope with this easy task.

Input
The first line represents input string of Petya's program. This string only consists of uppercase and lowercase Latin letters and its length is from 1 to 100, inclusive.

Output
Print the resulting string. It is guaranteed that this string is not empty.*/


#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
   
    return (c == 'a' || c == 'o' || c == 'y' || c == 'e' || c == 'u' || c == 'i');
}

int main() {
    string s;
    cin >> s;
    string ans = " ";

    // Convert to lowercase and remove vowels
    for (char c : s) {
        c = tolower(c);
    }


    // Process the string
    for (char c : s) {
        c = tolower(c) ;
        if (isVowel(c)) continue  ;{ 
            ans  += '.'; 
            ans  += c;   
        }
    }

    cout << ans << endl; 
    return 0;
}