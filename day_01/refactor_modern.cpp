// LEGACY VERSION
#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>

bool processOrders( const std::vector<std::pair<std::string,int>>* orders)
{
    if( orders == nullptr )
        return false;

    std::unordered_map<std::string,int> totals;
    for( const auto& [name,qty] : *orders )
    {
        totals[name] += qty;
    }

    for( const auto& [name,total] : totals )
    {
        std::cout << name << " : " << total << '\n';
    }

    return true;
}