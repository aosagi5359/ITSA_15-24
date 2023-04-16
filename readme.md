# ITSA 15~24題 解題方式

### 題目15. 文字及字母出現次數

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

---

### 題目16. 子字串出現次數

```c++
#include <iostream>
#include <string>
using namespace std;

int countSubstring(string& sub, string& str, int pos);
// 傳入兩個字串和一個起始位置，回傳子字串 sub 在主字串 str 中的出現次數

int main() {
    string sub, str;

    // 輸入子字串和主字串
    cin >> sub >> str;

    // 計算子字串出現次數
    int count = countSubstring(sub, str, 0);

    // 輸出結果
    cout << count << endl;

    return 0;
}

int countSubstring(string& sub, string& str, int pos) {
    int count = 0; // 計數器，統計子字串出現次數

    // 從起始位置開始尋找子字串
    pos = str.find(sub, pos);

    // 若找到子字串
    while (pos != string::npos) {
        // 計數器加 1
        count++;

        // 繼續尋找下一個子字串
        pos = str.find(sub, pos + 1);
    }

    return count;
}
```

本題主要思路事先用 string::find() 在第二個字串中找到第一個字串出現的位置，在使用while迴圈從上一次出現的位置的下一個位置開始找，直到找不到為止，每次找到時，計數器就會 +1 ，最後輸出計數器的值就好。

---

### 題目17. 英文斷詞

```c++
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main() 
{
    vector<string> words; // 儲存斷詞的 vector 宣告
    string input;
    getline(cin, input);

    transform(input.begin(), input.end(), input.begin(), ::tolower); // 轉換為小寫字母

    istringstream delim(input);
    string token;
    while (getline(delim, token, ' ')) // 以空格為分割符號進行斷詞
    {
        if (find(words.begin(), words.end(), token) == words.end()) // 如果 vector 中沒有此單字則加入
        {
            words.push_back(token);
        }
    }

    // 依照題目要求將單字依序列印
    for (int i = 0; i < words.size(); i++) 
    {
        cout << words[i];
        if (i != words.size() - 1) 
        {
            cout << " ";
        }
        else 
        {
            cout << endl;
        }
    }
    return 0;
}
```

宣告一個 vector 來儲存斷詞，並輸入一句話。
將輸入轉換成小寫字母。
以空格作為分割符號進行斷詞，將單字加入 vector 中，如果已存在則跳過。
依照題目要求將 vector 中的單字依序列印，最後一個單字後換行。

當 vector 中沒有此單字時，使用 find() 函數進行查找，如果找不到則返回 vector 的 end()，可以用來判斷單字是否存在。

---

### 題目18. QWERTY

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

---

### 題目19. 最少派車數

```c++
#include <iostream>
using namespace std;

int main(){
	int n, s, d, max_cars = 0;
    int time[25] = {0}; // 用陣列記錄每個時間點所需的車輛數量，初始化為0
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> s >> d;
        for (int j = s; j < d; j++){
            time[j]++; // 該時間點所需車輛數量加1
        }
    }
    for (int k = 0; k < 25; k++){
        if (time[k] > max_cars)
            max_cars = time[k]; // 找出最大需要車輛數量
    }
    cout << max_cars << endl; // 輸出最大需要車輛數量
    return 0;
}
```

用 pair<int, int> 來存儲每一筆訂單的出發時間和返回時間，然後將所有訂單按照出發時間從小到大排序。再用變量 count 記錄需要調度的遊覽車輛數量，以及變量 endTime 記錄當前使用的遊覽車的返回時間。初始情況下，將 count 設為 1，並且將 endTime 設為第一筆訂單的返回時間。接下來，遍歷所有訂單，對於每一筆訂單，如果其出發時間晚於等於 endTime，就可以使用當前的遊覽車來執行該訂單，因此需要將 count 增加 1，並且將 endTime 設為該訂單的返回時間。最後，輸出 count 即可。

---

### 題目20. 大整數加法

```c++
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string a, b;
        cin >> a >> b;

        // 將 a 跟 b 的字元順序倒轉
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string ans = "";
        int carry = 0;
        for (int i = 0; i < max(a.size(), b.size()); i++) {
            int x = i < a.size() ? a[i] - '0' : 0;
            int y = i < b.size() ? b[i] - '0' : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            ans += (sum % 10) + '0';
        }
        if (carry) ans += carry + '0';

        // 將 ans 的字元順序倒轉，即為正確答案
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
    return 0;
}
```

本題使用了兩個 string 儲存輸入的兩個數字，然後將兩個數字倒序相加，最後再將相加的結果反轉，即可得到正確的答案。

---

### 題目21. 最大值與最小值

```c++
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    float arr[10];
    float max = -1e9, min = 1e9; // 初始化最大值和最小值
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    cout << "maximum:" << fixed << setprecision(2) << max << endl; // 小數點後兩位
    cout << "minimum:" << fixed << setprecision(2) << min << endl; // 小數點後兩位
    return 0;
}
```

程式首先宣告一個長度為 10 的浮點數陣列，並初始化最大值和最小值為極小和極大值。

然後使用 for 迴圈讀入 10 個浮點數，同時在迴圈中更新最大值和最小值，如果當前數值大於最大值就更新最大值，如果小於最小值就更新最小值。

最後輸出最大值和最小值，使用 fixed 和 setprecision(2) 來控制小數點的輸出格式，以達到小數點後兩位的要求。

---

### 題目22. 圈圈叉叉

```c++
#include <iostream>
using namespace std;

int main(){
    int board[3][3]; 
    bool win = false; // 建立一個布林變數，初始為 false

    // 讀入 3x3 的二維陣列
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> board[i][j];
        }
    }

    // 檢查所有的橫排和直排是否都是 0 或都是 1
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2])) {
            win = true; // 設定 win 為 true，表示勝利
        }
        if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i])) {
            win = true; // 設定 win 為 true，表示勝利
        }
    }

    // 檢查兩條對角線是否都是 0 或都是 1
    if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) {
        win = true; // 設定 win 為 true，表示勝利
    }
    if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0])) {
        win = true; // 設定 win 為 true，表示勝利
    }

    // 根據 win 的值輸出結果
    if (win) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}
```

### 題目23. 找零錢問題

```c++
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// 字串取代函式，將逗號取代為空格
void replaceD(string &str) {
    for (char &c : str) {
        if (c == ',') c = ' ';
    }
}

int main() {
    // 讀入輸入資料
    string str;
    int N,a1,a2,a3,cost,x,y,z;
    getline(cin, str);

    // 將逗號取代為空格
    replaceD(str);

    // 從字串取出 N、a1、a2、a3
    stringstream ss(str);
    ss >> N >> a1 >> a2 >> a3;

    // 計算水果的價錢總和
    cost = a1 * 15 + a2 * 20 + a3 * 30;

    // 如果錢不夠，輸出 "0"
    if (cost > N) {
        cout << "0" << endl;
    }
    else {
        // 計算找零銅板的數量
        z = (N - cost) / 50;  // 計算 50 元銅板的數量
        y = ((N - cost) % 50) / 5;  // 計算 5 元銅板的數量
        x = ((N - cost) % 50) % 5;  // 計算 1 元銅板的數量

        // 輸出找零銅板的數量
        cout << x << "," << y << "," << z << endl;
    }

    return 0;
}
```

讀取輸入：使用 getline 函數讀取一行字串，接著使用 replaceD 函數將字串中的逗號替換成空格，方便使用 stringstream 將數字讀取出來。

計算總共的成本：使用讀取進來的 a1, a2, a3 分別乘以水果的單價，然後相加得到總共的成本 cost。

計算找回的銅板數量：
首先計算可以找回的 50 元銅板數量 z，可以使用 (N - cost) / 50 計算得到；
接著計算可以找回的 5 元銅板數量 y，可以使用 ((N - cost) % 50) / 5 計算得到；
最後計算可以找回的 1 元銅板數量 x，可以使用 ((N - cost) % 50) % 5 計算得到。

輸出結果：如果總共的成本 cost 大於給的錢 N，代表帶的錢不夠買水果，因此輸出 0；否則，輸出找回的 1 元、5 元、50 元銅板數量。

---

### 題目24. 計算複利

```c++
#include<iostream>
using namespace std;

int main(){
    long double r, sum;  // 宣告變數 r 和 sum ，使用 long double 型別，保證浮點數的精度
    long int n, p;  // 宣告變數 n 和 p ，使用 long int 型別，保證整數的精度

    cin >> r;  // 讀入每期利率 r
    cin >> n;  // 讀入期數 n
    cin >> p;  // 讀入每期投入金額 p

    sum = p;  // 設定初始本利和為每期投入金額 p
    while (n > 1)  // 計算 n-1 次本利和
    {
        sum *= (1.0 + r);  // 計算每期本利和
        sum += p;  // 加上每期投入金額
        n--;  // 更新期數
    }
    sum *= (1.0 + r);  // 計算第 n 期本利和，但不需加上每期投入金額

    cout << (long long)sum << endl;  // 輸出整數的本利和，並強制轉換為 long long 型別
    return 0;  // 結束程式
}
```

計算複利的公式為：s = p * (1 + r)^n，因此需要使用pow()函數來計算次方。

使用pow()函數計算本利和s，最後使用cout輸出並使用setprecision()函數設定精度為0位。
