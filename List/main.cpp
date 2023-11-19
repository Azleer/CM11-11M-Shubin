#include <iostream>
#include "mylist.h"

using namespace std;

int main()
{
    MyList<int> Lhs, Rhs;
    Lhs.push_back(4); Lhs.push_back(1); Lhs.push_back(123); Lhs.push_back(4); Lhs.push_back(23);
    //Rhs.push_back(1); Rhs.push_back(3); Rhs.push_back(13); Rhs.push_back(14);

     Lhs.pastesort();

    Lhs.print();






    return 0;
}
