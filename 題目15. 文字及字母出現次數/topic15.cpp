#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    string s;
    getline(cin, s); // 讀入整行文字
    unordered_map<char, int> freq; // 宣告一個空的 unordered_map

    int wordCount = 0; // 字數
    char c;
    for (int i = 0; i < s.length(); i++) {
        c = tolower(s[i]); // 轉成小寫
        if (isalpha(c)) { // 如果是字母
            freq[c]++; // 字母出現次數加一
            if (i == 0 || !isalpha(s[i - 1])) { // 如果這是一個新字的開頭
                wordCount++; // 字數加一
            }
        }
    }

    cout << wordCount << endl; // 輸出字數
    for (char c = 'a'; c <= 'z'; c++) { // 依序輸出各個字母出現次數
        if (freq[c] > 0) {
            cout << c << " : " << freq[c] << endl;
        }
    }

    return 0;
}