#include <iostream>
#include "myvector.h"

using namespace std;

int main()
{
    MyList<int> L;

    for (int var = 0; var < 20; ++var)
    {
        L.push_back(var);
    }

    L.print();

    return 0;
}
