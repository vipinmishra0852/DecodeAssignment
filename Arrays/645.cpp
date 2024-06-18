#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> v(2, -1);
        vector<int> result;
        map<int, int> m;
        bool b = true;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i]== nums[i+1])
            {
                v[0] = nums[i];
                break;
            }
        }

        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }
        for (auto it : m)
        {
            result.push_back(it.first);
        }

        for (int i = 0; i < result.size(); i++)
        {
            if (result[i] != i + 1)
            {
                v[1] = i + 1;
                b = false;
                break;
            }
        }
        if (b)
        {
            v[1] = nums.size();
        }

        return v;
    }
};


int main(){

return 0;
}