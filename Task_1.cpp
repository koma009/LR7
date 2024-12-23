#include <bits/stdc++.h>
#include <string>
using namespace std;

string toComplementCode(const string& directCode) {
    string complementCode = directCode;

    for (size_t i = 0; i < directCode.size(); ++i) {
        complementCode[i] = (directCode[i] == '1') ? '0' : '1';
    }

    return complementCode;
}

int main() {
    string directCode;
    cout << "Введите число в прямом коде: ";
    cin >> directCode;

    string result = toComplementCode(directCode);
    cout << "Обратный код: " << result << endl;

    return 0;
}