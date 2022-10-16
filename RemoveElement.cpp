#include <bits/stdc++.h>
using namespace std;

int removeElement(vector<int> &nums, int val)
{
  // Initialize a variable len which will count the number of elements except val...
  int len = 0;
  // Loop through all the elements of the array from left to right...
  for (int i = 0; i < nums.size(); i++)
  {
    // If the element is not val...
    if (nums[i] != val)
    {
      nums[len++] = nums[i]; // Add that element to the place of len..
    }
  }
  return len; // Return the number...
}

int main()
{
  vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
  int val;
  cin >> val;
  cout << removeElement(nums, val) << endl;
}