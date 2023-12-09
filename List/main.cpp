#include <iostream>
#include "mylist.h"

using namespace std;

int main()
{
    MyList<int> Lhs;
    Lhs.push_back(1); Lhs.push_back(2); Lhs.push_back(2); Lhs.push_back(1);  Lhs.push_back(2); Lhs.push_back(4); Lhs.push_back(15); Lhs.push_back(0); Lhs.push_back(100);  Lhs.push_back(2);

    Lhs.bublesort();
    Lhs.print();


    return 0;
}
