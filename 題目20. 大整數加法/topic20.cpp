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