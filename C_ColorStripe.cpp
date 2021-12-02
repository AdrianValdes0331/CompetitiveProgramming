//C_ColorStripes
#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>

using namespace std;

string str, str1, str2;
int n, k;

void solveForTwo(int ans, int sum) {
    for (int i = 0; i < n; i++) {
        if (i % 2 && str1[i] != 'A') {
            sum++;
            str1[i] = 'A';
        }
        else if (i % 2 == 0 && str1[i] != 'B') {
            sum++;
            str1[i] = 'B';
        }
    }

    ans = sum;
    sum = 0;

    for (int i = 0; i < n; i++) {
        if (i % 2 && str2[i] != 'B') {
            sum++;
            str2[i] = 'B';
        }
        else if (i % 2 == 0 && str2[i] != 'A') {
            sum++, str2[i] = 'A';
        }
    }

    ans = min(ans, sum);
    cout << ans << endl;

    if (ans == sum) {
        cout << str2 << endl;
    }
    else {
        cout << str1 << endl;
    }
}

void solveMoreThan2(int ans) {

    for (int i = 1; i < n; i++) {
        if (str[i] == str[i - 1]) {
            ans++;
            for (int j = 0; j < k; j++) {

                if (i != n - 1) {
                    if ('A' + j != str[i - 1] && 'A' + j != str[i + 1]) {
                        str[i] = 'A' + j;
                        break;
                    }
                }

                else {
                    if ('A' + j != str[i - 1]) {
                        str[i] = 'A' + j;
                        break;
                    }
                }

            }
        }
    }

    cout << ans << endl;
    cout << str << endl;
}

int main() {
    int ans = 0, sum = 0;
    cin >> n >> k;
    cin >> str;
    str1 = str;
    str2 = str;

    if (k == 2) {
        solveForTwo(ans, sum);
    }

    else {
        solveMoreThan2(ans);
    }

    return 0;
}
// Con ayuda de esta referencia: 
// https://www.programmerall.com/article/42381746121/
