#include <string>
#include <iostream>
#include "Parser.h"


int main ()
{
    const char* msg1 = "053F80000009011C40000000";
    const char* msg2 = "4C41A400004B3F91BCD8";
    const char* msg3 = "0741a40000053F91Bcd819413547aE";
    const char* msg4 = "05430d083b183f91bcd8193edf4de94d422869e241f8f5c341dec28f3c594d0e";
    const char* msg5 = "05430d083b183f91bcd8193edf4de94f00080015bca408c0163bfb4dab173f80f5081bc16ea4371cc12d31271d42513d4f4a000000004b000000004c00000000";
    const char* msgHomeWork = "05430D083B183F91BCD8193EDF4DE94F00080015BCA408C0163BFB4DAB173F80F5081BC16EA4371cc12d31271d42513d4f4a000000004b000000004c00000000";

    Parser data;
    data.Parse(msgHomeWork);
    data.PrintData();
    return 0;
}
