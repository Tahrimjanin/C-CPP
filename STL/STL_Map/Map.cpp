#include <bits/stdc++.h>
using namespace std;

int main() {
    // Map declaration
    map<string, int> mp;    
    map<int ,int> m;       

    // Initialization
    mp["apple"] = 3; 
    m[1] = 10; 
    m[2] = 20;
    cout << m[1] << " " << m[2] << "\n";//10 20

    //pair 
    map<pair<int,int >,int > m3;
    m3[{1, 10}] = 100; 
    m3[{10,11}] = 1000 ;
    m3[{9,8}] = 90 ;
    cout << m3[{1, 10}] << " " << m3[{10,11}] << " " << m3[{9,8}] << "\n"; //100 1000 90

    // for more data types (vector as value type) 
    map <int ,vector<int>>m4 ; 
    m4[3] = {1, 2, 3};
    m4[2] = {4, 5, 6};
    cout << m4[1][0] << " " << m4[2][1] << "\n"; // 1 5

    m4[3].push_back(2);
    m4[3].push_back(5);
    m4[3].push_back(10);

    m4[2].push_back(20);
    m4[2].push_back(-10);
    m4[2].push_back(-11);

    for (int a : m4[3]) {
        cout << a << " "; // 1 2 3 2 5 10
    }
    cout << "\n";

    for (int a : m4[2]) {
        cout << a << " "; // 4 5 6 20 -10 -11
    }
    cout << "\n";

    cout<< m4[3].size() << "\n"; //6
    cout<< m4[2].size() << "\n"; //6



    // Insertion
    mp["apple"] = 5;                     // Direct assignment (replace 3 -> 5)
    mp.insert({"banana", 10});           // insert with pair
    mp.insert(make_pair("mango", 7));    // make_pair
    mp.emplace("orange", 12);            // emplace (faster)

    // Access and Modification
    cout << "apple count: " << mp["apple"] << "\n";     // apple count: 5
    cout << "banana count: " << mp.at("banana") << "\n"; //banana count: 10

    // Update
    mp["apple"] = 20; // Now apple -> 20

    // Search and Check Existence
    if (mp.find("mango") != mp.end()) {
        cout << "mango found!\n";        //mango found!
    } else {
        cout << "mango not found!\n";
    }

    // Erase
    mp.erase("banana");                  // banana removed
    if (mp.find("mango") != mp.end())    // mango exists, erase it
        mp.erase(mp.find("mango"));

    // Iterate
    cout << "\nCurrent map:\n";  
    for (auto &it : mp) {
        cout << it.first << " -> " << it.second << "\n";
        // Expected Output:
        // apple -> 20
        // orange -> 12
    }

    // Using iterator explicitly
    cout << "\nUsing iterator:\n";
    for (map<string,int>::iterator it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << " => " << it->second << "\n"; // same output 
       
    }

    // Size & Empty

     mp["banana"] = 7; 
    cout << mp["banana"]<< endl;
    cout <<mp.size()<<endl;

    cout << (mp.empty() ? "empty" : "not empty") << "\n"; // Output:not empty

    // Clear all
    mp.clear();
    cout << "\nAfter clear, size: " << mp.size() << "\n";    //After clear, size: 0

    return 0;
}
