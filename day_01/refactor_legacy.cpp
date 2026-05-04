// LEGACY VERSION
#include <vector>
#include <map>
#include <iostream>
#include <string>

bool processOrders(std::vector<std::pair<std::string,int>>* orders)
{
    if( orders == NULL )
        return false;

    std::map<std::string,int> totals;
    for( std::vector<std::pair<std::string,int>>::iterator it = orders->begin(); it != orders->end(); ++it )
    {
        totals[it->first] = totals[it->first] + it->second;
    }

    for( std::map<std::string,int>::iterator it = totals.begin(); it != totals.end(); ++it )
    {
        std::cout << it->first << " : " << it->second << std::endl;
    }

    return true;
}