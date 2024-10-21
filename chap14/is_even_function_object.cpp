#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class IsEven
{
  public:
  bool operator()(int x) const
  {
    return x % 2 == 0;
  }
};

int main()
{
  std::vector<int> nums = {1, 2, 3, 4, 5, 6};

  int evenCout = count_if(nums.begin(), nums.end(), IsEven());

  cout << "There are " << evenCout << " even numbers\n";

  return 0;
}
