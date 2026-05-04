#include <array>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

        if( s.size() != t.size() )
            return false;

        array<int,26> count{};// use unordered_map if not lowercase english letters

        for( auto c : s )
            count[c]++;

        for( auto c : t )
        {
            if( --count[c] < 0 )
                return false;
        }

        return true;
        
    }
};