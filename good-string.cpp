#include <iostream>
#include <string>
#include <climits>
#include <vector>

using namespace std;
int main()
{
    int t;
    cin >> t;
    char m[15] = {
        '0',
        '1',
        '2',
        '3',
        '4',
        '5',
        '6',
        '7',
        '8',
        '9',
    };

    while (t--)
    {
        int minn = 100000000;
        int ch = 0;
        string s;
        cin >> s;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                ch = 0;
                int flag = 1;
                for (int k = 0; k < s.length(); k++)
                {
                    if (s[k] == m[i] && flag == 1)
                    {
                        flag = 0;
                        if (i == j)
                            ch++;
                    }
                    else if (s[k] == m[j] && flag == 0)
                    {
                        flag = 1;
                        if (i == j)
                            ch++;
                        else
                            ch += 2;
                    }
                }
                int len = s.length();
                minn = min(minn, len - ch);
            }
        }
        cout << minn << endl;
    }
}