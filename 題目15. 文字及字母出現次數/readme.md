# 題目15. 文字及字母出現次數

```c++
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
```

本題使用unordered_map ，它能夠快速地根據鍵（這裡是字母）找到對應的值（這裡是出現次數）。

遍歷輸入的整行文字，每當遇到一個新的字母，就讓字數加一，同時讓該字母的出現次數加一；最後依序輸出各個字母的出現次數。

tolower 和 isalpha 這兩個函數。tolower 能夠把字母轉成小寫，這樣就能夠避免大小寫不同的字母被算作不同的字母；而 isalpha 則能夠判斷一個字符是否為字母。
