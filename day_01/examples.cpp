#include <iostream>

#include <vector>
#include <map>
#include <string>


int main()
{

    // 1. Auto

    std::vector<std::pair<std::string,int>> v;

    auto it = v.begin(); // instead of std::vector<std::pair<...>>::iterator

    auto x = 42;    // int

    auto y = 3.14;  // double

    auto  z = "hello";  // const char* and not std::string

    auto s = std::string{"hi"}; // std::string


    // Senior-level gotcha #1: auto strips references and top-level const.

    int some_int = 10;
    const int& ref = some_int;

    auto a = ref;   // a is int( not const int&), copy made

    auto& a2 = ref; // a2 is const int&, reference preserved

    const auto& a3 = ref;   // a3 is const int&, most common form

    // Senior-level gotcha #2: auto with proxy types lies.
    std::vector<bool> v1 = {true,false,true};
    
    auto var = v1[0];  // x is std::vector<bool>::reference and not bool
    // Its a proxy that holds a pointer into v.

    // Use bool x = v[0]; or auto x = static_cast<bool>(v[0]);


    // 2. Range based for

    std::vector<int> nums = {1,2,3,4};

    // Read only
    for( auto n : nums ) { /*copy*/ }
    for( const auto& n : nums ) { /* no copy, can't modify - preferred for heavy types */}

    // Modify
    for( auto& n : nums ) { n*= 2; }

    // Map iteration with structured binding( C++ 17 )
    std::map<std::string,int> count = {{"a",1},{"b",2}};

    for( const auto& [key,value] : count )
    {
        std::cout << key << "-->" << value << "\n";
    }

    // Senior-level gotcha: invalidating the container while iterating.
    // BAD - modifying vector during range for is Undefined behavior

    for( auto& n : nums )
    {
        if( n == 2 )
            nums.push_back(99); // iterator invalidation, undefined behavior
        // If you need to modify during iteration, use index-based loops or build a new container.
    }



    // 3. nullptr
    /* void f(int);
    void f(char*);

    f(NULL);    // calls f(int)
    f(0);       // calls f(int)
    f(nullptr); // calls f(char*)

    Always use nullptr and not NULL
    */

    // 4. Uniform initialization
    int x1{42};
    std::vector<int> v2{1,2,3,4};
    std::pair<int,std::string> p{1,"hi"};
    //MyClass obj{arg1,arg2};

    // Senior-level gotcha: the initializer_list hijack.

    std::vector<int> v3(3,5);   // 3 elements all 5 : {5,5,5}
    std::vector<int> v4{3,5};   // 2 elements : {3,5}
    // Brace int prefers initializer_list constructor of vector

}