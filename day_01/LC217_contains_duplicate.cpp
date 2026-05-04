#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        std::unordered_set<int> seen;

        seen.reserve(nums.size());  // avoid rehasing as we grow
        
        for( int x : nums )
        {
            if( !seen.insert(x).second )
                return true;    // insert failed = duplicate
        }

        return false;
    }
};