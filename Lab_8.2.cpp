#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void ToUpperBeforeSpace(string& s) {
    size_t spacePos = s.find(' ');
    if (spacePos == string::npos) return;

    for (size_t i = 0; i < spacePos; ++i) {
        if (islower(s[i])) {
            s[i] = toupper(s[i]);
        }
    }
}

int main() {
    string str;
    cout << "Enter string:" << endl;
    getline(cin, str);

    ToUpperBeforeSpace(str);

    cout << "Modified string: " << str << endl;

    return 0;
}