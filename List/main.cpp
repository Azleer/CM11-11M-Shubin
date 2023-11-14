#include <iostream>
#include "mylist.h"

using namespace std;

int main()
{
    MyList<int> Lhs, Rhs;
    Lhs.push_back(2); //Lhs.push_back(4); Lhs.push_back(6); Lhs.push_back(8); Lhs.push_back(12);
    Rhs.push_back(1); //Rhs.push_back(3); Rhs.push_back(13);


    Lhs.smerge(&Rhs);





    return 0;
}
