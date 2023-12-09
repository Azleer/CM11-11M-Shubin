#include <iostream>
#include "mylist.h"

using namespace std;

int main()
{
    MyList<int> Lhs;
    Lhs.push_back(1); Lhs.push_back(2); Lhs.push_back(2); Lhs.push_back(1);  Lhs.push_back(2); Lhs.push_back(4); Lhs.push_back(15); Lhs.push_back(0); Lhs.push_back(100);  Lhs.push_back(2);
<<<<<<< HEAD
=======
    Rhs.push_back(1); Rhs.push_back(3); Rhs.push_back(12); Rhs.push_back(14);
>>>>>>> fef52fccf09175df12834ca5715711e4306244c2

    Lhs.bublesort();
    Lhs.print();


    return 0;
}
