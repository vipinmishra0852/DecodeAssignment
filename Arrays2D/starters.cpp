#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        bool ans = true;
        string s;
        cin >> s;
        int pass = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                pass = pass - 1;
                if (pass < 0)
                {
                    ans = false;
                    break;
                }
            }
           
            else
            {
                pass =  x;

                if (pass < 0)
                {
                    ans = false;
                    break;
                }
            }
        }
        if (ans)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}