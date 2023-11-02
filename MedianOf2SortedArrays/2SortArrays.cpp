class Solution
{
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
  {
    if (nums1.size() > nums2.size())
    {
      swap(nums1, nums2);
    }
    int m = nums1.size();
    int n = nums2.size();

    int left = 0, right = m;
    while (left <= right)
    {
      int partitionX = (left + right) / 2;
      int partitionY = (m + n + 1) / 2 - partitionX;

      int maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
      int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];

      int minX = (partitionX == m) ? INT_MAX : nums1[partitionX];
      int minY = (partitionY == n) ? INT_MAX : nums2[partitionY];

      if (maxX <= minY && maxY <= minX)
      {
        if ((m + n) % 2 == 0)
        {
          return (max(maxX, maxY) + min(minX, minY)) / 2.0;
        }
        else
        {
          return max(maxX, maxY);
        }
      }
      else if (maxX > minY)
      {
        right = partitionX - 1;
      }
      else
      {
        left = partitionX + 1;
      }
    }
    // If we reach here, it means the input arrays are not sorted.
    throw invalid_argument("Input arrays are not sorted.");
  }
};