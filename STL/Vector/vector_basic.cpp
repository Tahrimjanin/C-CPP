#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    cout << v[0] << " " << v[1] << " " << v[2] << endl; // 1 2 3

    v[1] = 3;
    cout << v[0] << " " << v[1] << " " << v[2] << endl; // 1 3 3

    cout << v.size() << endl; // 3
    for (int i = 0; i < v.size(); i++) cout << v[i] << " "; // 1 3 3
    cout << endl;

    // v1 element print + size
    vector<int> v1 = {2, 3, 4};

    cout << v1.size() << endl; // 3
    for (int i = 0; i < v1.size(); i++) cout << v1[i] << " "; // 2 3 4
    cout << endl;

    // all values clear
    v.clear();
    cout << v.size() << endl;      // 0
    cout << v.empty() << endl;     // 1 (true, because v is empty)
    cout << v1.empty() << endl;    // 0 (false, because v1 is not empty)

    // vector size change using resize (adds default-initialized elements)
    v1.resize(5);
    cout << v1.size() << endl; // 5
    for (int i = 0; i < v1.size(); i++) cout << v1[i] << " "; // 2 3 4 0 0
    cout << endl;

    vector<int> a(5); // 0 initialized
    // vector<int> a(5, 3); // => 3 3 3 3 3

    cout << a.size() << endl; // 5
    for (int i = 0; i < a.size(); i++) cout << a[i] << " "; // 0 0 0 0 0
    cout << endl;

    a = v1;
    for (auto u : a) cout << u << " "; // 2 3 4 0 0
    cout << endl;

    // iterator example
    vector<int>::iterator it;
    for (it = a.begin(); it != a.end(); it++) cout << *it << " "; // 2 3 4 0 0
    cout << endl;

    a = {3, 4, 5, 1, 2};
    sort(a.begin(), a.end()); // ascending sort
    for (auto u : a) cout << u << " "; // 1 2 3 4 5
    cout << endl;

    /*
    sort(a.begin() + 1, a.begin() + 4);
    for (auto u : a) cout << u << " "; // 3 1 4 5 2 => only indices 1 to 3 sorted
    */

    sort(a.rbegin(), a.rend()); // reverse sort
    for (auto u : a) cout << u << " "; // 5 4 3 2 1
    cout << endl;

    a = {3, 4, 5, 1, 2};
    sort(a.begin(), a.end(), greater<int>()); // descending using comparator
    for (auto u : a) cout << u << " "; // 5 4 3 2 1
    cout << endl;

    a = {3, 4, 5, 1, 2};
    reverse(a.begin(), a.end());
    for (auto u : a) cout << u << " "; // 2 1 5 4 3
    cout << endl;

    cout << a.back() << endl; // 3
    a.pop_back(); // removes last element
    cout << a.back() << endl; // 4

    a = {3, 4, 5, 1, 2};
    cout << *a.begin() << endl; // 3 (first element)
    a.erase(a.begin()); // remove first element
    for (auto u : a) cout << u << " "; // 4 5 1 2
    cout << endl;

    a.erase(a.begin() + 2); // remove 3rd element (index 2)
    for (auto u : a) cout << u << " "; // 4 5 2
    cout << endl;

    a = {1, 1, 2, 2, 2, 3, 3};
    unique(a.begin(), a.end()); // removes adjacent duplicates but doesn’t shrink vector
    for (auto u : a) cout << u << " "; // 1 2 3 2 2 3 3
    cout << endl;

    a = {1, 1, 2, 2, 2, 3, 3};
    sort(a.begin(), a.end());
    int n = unique(a.begin(), a.end()) - a.begin(); // get new size
    cout << n << endl; // 3
    for (int i = 0; i < n; i++) cout << a[i] << " "; // 1 2 3
    cout << endl;

    a = {2, 3, 1, 5};
    cout << max_element(a.begin(), a.end()) - a.begin() << endl; // index = 3
    cout << *max_element(a.begin(), a.end()) << endl; // 5

    return 0;
}
