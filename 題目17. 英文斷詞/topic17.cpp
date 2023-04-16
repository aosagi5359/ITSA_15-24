#include <iostream>
#include <vector>
#include <string> // 添加了 string 標頭檔
#include <sstream>
#include <algorithm> // 添加了 algorithm 標頭檔
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