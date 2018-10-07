#include <iostream>
#include "vtable.hpp"
#include "mlist.hpp"
void testList(){
    bruce::List<int> list;
    for (int i = 1; i < 4; ++i) {
        list.pushNodeToTrail(i);
    }
    for (int i = 5; i > 0; --i) {
        list.pushNodeToTrail(i);
    }
    bool res = list.islistpalindrome();
    if(res){
        std::cout << "islistpalindrome!" << std::endl;
    } else{
        std::cout << "is not listpalindrome!" << std::endl;
    }

//    list.description();

//    list.reverseListBySlowNode();

//    list.getSlowNode();

//    list.reserveList();


//    list.description();


}
int main() {
    std::cout << "Hello, World!" << std::endl;
    testList();
    return 0;
}