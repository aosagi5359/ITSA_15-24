# 題目18. QWERTY

```c++
#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    getline(cin, input); // 讀取一整行輸入文字

    string keyboard = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./"; // 鍵盤上的所有字元

    for (int i = 0; i < input.length(); i++) {
        char c = input[i];
        int index = keyboard.find(c);

        if (index != string::npos) { // 如果找到了輸入字元在鍵盤上對應的位置
            char next_c = keyboard[index+1];

            // 處理特殊情況：如果右邊的字元是上層字元或不可見的字元，就要再往右找一個字元
            if (next_c == '!' || next_c == '@' || next_c == '#' || next_c == '$' || next_c == '^' ||
                next_c == '*' || next_c == '(' || next_c == ')' || next_c == '_' || next_c == '+' ||
                next_c == '{' || next_c == '}' || next_c == '|' || next_c == ':' || next_c == '\"' ||
                next_c == '<' || next_c == '>' || next_c == '?' || next_c == '\n' || next_c == '\r' ||
                next_c == '\t' || next_c == '\b' || next_c == '\\' || next_c == ']') {
                next_c = keyboard[index+2];
            }

            cout << next_c;
        } else {
            cout << c;
        }
    }

    cout << endl;

    return 0;
}
```

先將件旁上的所有字元定義在 keyboard 中，再讀入 input，逐一處理每個輸入的字元，若字元在 keyboard 中對應的位置，並輸出位置右邊的字元，如果該字元在是上層或不可見的字元，則再網友找一個字元，如果字元不在 keyboard 中，就照樣輸出。最後記得要輸出換行符號。
