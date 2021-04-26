// CPP program to demonstrate use of std::map
/*

      | map             | unordered_map
---------------------------------------------------------
Ordering        | increasing  order   | no ordering
                | (by default)        |

Implementation  | Self balancing BST  | Hash Table
                | like Red-Black Tree |  

search time     | log(n)              | O(1) -> Average 
                |                     | O(n) -> Worst Case

Insertion time  | log(n) + Rebalance  | Same as search
                      
Deletion time   | log(n) + Rebalance  | Same as search
*/
#include <iostream>
#include <map>
#include <unordered_map>
#include <utility>

int main()
{
    // Ordered map
    std::map<int, int> order;

    // Mapping values to keys
    order[5] = 10;
    order[3] = 5;
    order[20] = 100;
    order[1] = 1;

    // Iterating the map and
    // printing ordered values
    for (auto i = order.begin(); i != order.end(); i++)
    {
        std::cout << i->first
                  << " : "
                  << i->second << '\n';
    }
    return(0);
}

int main_x()
{
    // Unordered map
    std::unordered_map<int, int> order;

    // Mapping values to keys
    order[5] = 10;
    order[3] = 5;
    order[20] = 100;
    order[1] = 1;

    // Iterating the map and
    // printing unordered values
    for (auto i = order.begin();
         i != order.end(); i++)
    {
        std::cout << i->first
                  << " : "
                  << i->second << '\n';
    }
    return(0);
}

typedef std::pair<std::string,std::string> pair;
 
int mainxx()
{
    std::map<pair,int> map =
    {
        { std::make_pair("C++", "C++14"), 2014 },
        { std::make_pair("C++", "C++17"), 2017 },
        { std::make_pair("Java", "Java 7"), 2011 },
        { std::make_pair("Java", "Java 8"), 2014 },
        { std::make_pair("C", "C11"), 2011 }
    };
 
    for (const auto &entry: map)
    {
        auto key_pair = entry.first;
        std::cout << "{" << key_pair.first << "," << key_pair.second << "}, "
                  << entry.second << '\n';
    }
 
    return 0;
}