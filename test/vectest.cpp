#include<iostream>
#include<vector>
#include <string>

int main() {

    std::vector<int> test;
    test.push_back(10);
    test.push_back(20);
    
    std::vector<std::pair<std::string, std::string>> foo;
    
    foo.push_back(std::make_pair("key", "value"));

    for(std::pair<std::string, std::string> i : foo) {
        std::cout << i.first << i.second <<std::endl;
    }

    std::cout<<test.size()<<std::endl;
    return 0;
}