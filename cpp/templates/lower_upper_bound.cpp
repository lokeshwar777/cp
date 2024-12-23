#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution
{
public:
    int n;
    int lowerBound(vector<int> &nums, int target)
    {
        int low = 0, high = n - 1, ans = -1;
        while (low <= high)
        {
            int mid = ((high - low) >> 1) + low;
            // cout << mid << " " << nums[mid] << endl;
            if (nums[mid] == target)
                ans = mid;
            if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return ans;
    }
    int upperBound(vector<int> &nums, int target)
    {
        int low = 0, high = n - 1, ans = -1;
        while (low <= high)
        {
            int mid = ((high - low) >> 1) + low;
            if (nums[mid] == target)
                ans = mid;
            if (nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        n = nums.size();
        int first = lowerBound(nums, target);
        // cout << first;
        if (first == -1)
            return {-1, -1};
        int second = upperBound(nums, target);
        return {first, second};
    }
};
int main()
{
    Solution solution;
    int target;
    cin >> target;
    string input_string;
    cin >> input_string;
    input_string = input_string.substr(1, input_string.length() - 2);
    stringstream ss(input_string);
    vector<int> nums;
    string temp;
    while (getline(ss, temp, ','))
        nums.push_back(stoi(temp));
    vector<int> res = solution.searchRange(nums, target);
    cout << "[" << res[0] << "," << res[1] << "]" << endl;
    return 0;
}