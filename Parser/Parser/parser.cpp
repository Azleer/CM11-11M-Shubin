#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
#include "Parser.h"

void Parser::PrintData()
{
    std::cout.precision(8);
    std::cout.width(40);
    std::cout << "----------------" << std::endl;

    for (auto &i : this->qdata) {
        if (i.isTransmit) {
            std::cout
                << i.name     << ""
                << i.value[0] << "; "
                << i.value[1] << "; "
                << i.value[2] << "; "
                << i.value[3] << ";"
                << i.unit     << std::endl;
        }
    }

    for (auto &i : this->fdata) {
        if (i.isTransmit) {
            std::cout
                << i.name  << ""
                << i.value << ""
                << i.unit  << std::endl;
        }
    }

    for (auto &i : this->chdata) {
        if (i.isTransmit) {
            std::cout
                << i.name  << ""
                << i.value << ""
                << i.unit  << std::endl;
        }
    }

    for (auto &i : this->booldata) {
        if(i.isTransmit) {
                          std::cout << i.name  << "";
            if(i.value) { std::cout << "true"  << "";}
            else        { std::cout << "false" << "";}
                          std::cout << i.unit  << std::endl;
        }
    }
}

void Parser::Parse(const char* msg)
{
    if (msg == nullptr){ return; }
    bool readMod = false;                    // false - read ID, true - read dada;
    int8_t ID = 0;
    int8_t buff[4] = {0,0,0,0};
    const void* prt_buff = &buff;
    int offset = 0;


    while(msg[offset] != '\0') {
        if(readMod) {
            for (auto &i : this->fdata) {
                if (i.id == ID) {
                    i.isTransmit = true;
                    buff[0] = Collector(Passport(msg[offset+6]), Passport(msg[offset+7]));
                    buff[1] = Collector(Passport(msg[offset+4]), Passport(msg[offset+5]));
                    buff[2] = Collector(Passport(msg[offset+2]), Passport(msg[offset+3]));
                    buff[3] = Collector(Passport(msg[offset]), Passport(msg[offset+1]));
                    i.value = *(float*)prt_buff;
                    offset += 8;

                }
            }

            for (auto &i : this->qdata) {
                if (i.id == ID) {
                    i.isTransmit = true;
                    for (int k = 0; k < 4; ++k) {
                        buff[0] = Collector(Passport(msg[offset+6]), Passport(msg[offset+7]));
                        buff[1] = Collector(Passport(msg[offset+4]), Passport(msg[offset+5]));
                        buff[2] = Collector(Passport(msg[offset+2]), Passport(msg[offset+3]));
                        buff[3] = Collector(Passport(msg[offset]), Passport(msg[offset+1]));
                        i.value[k] = *(float*)prt_buff;
                        offset += 8;

                    }
                }
            }

            for (auto &i : this->chdata) {
                if (i.id == ID) {
                    i.isTransmit = true;
                    buff[0] = Collector(Passport(msg[offset]), Passport(msg[offset+1]));
                    i.value = *(char*)prt_buff;
                    offset += 2;

                }
            }

            for (auto &i : this->booldata) {
                if (i.id == ID) {
                    i.isTransmit = true;
                    buff[0] = Collector(Passport(msg[offset]), Passport(msg[offset+1]));
                    i.value = *(bool*)prt_buff;
                    offset += 2;


                }
            }

            readMod = false;

        }
        else {
            ID = Collector(Passport(msg[offset]), Passport(msg[offset+1]));
            buff[0] = 0; buff[1] = 0; buff[2] = 0; buff[3] = 0;
            readMod = true;
            offset += 2;
        }

    }
}


int8_t Parser::Passport(char ch)
{
    if (ch >= 'a' && ch <= 'f') {
        return ch - 'a' + 10;
    }
    if (ch >= '0' && ch <= '9') {
        return ch - '0';
    }
    if (ch >= 'A' && ch <= 'F') {
        return ch - 'A' + 10;
    }
    std::cout << "EROOR PASPORT" << std::endl;
    return ' ';
}

int8_t Parser::Collector(int8_t lhs, int8_t rhs)
{
    int8_t temp = 0;
    temp += lhs;
    temp <<= 4;
    temp += rhs;
    return temp;
}


Parser::Parser() {
    fdata = {
        { 5 , "kHeading        ", 0, false, "[degree]"},
        { 24, "kPith           ", 0, false, "[degree]"},
        { 25, "kRoll           ", 0, false, "[degree]"},
        { 7 , "kTemperature    ", 0, false, "[temp. C]"},
        { 21, "kAccelX         ", 0, false, "[g]"},
        { 22, "kAccelY         ", 0, false, "[g]"},
        { 23, "kAccelZ         ", 0, false, "[g]"},
        { 27, "kMagX           ", 0, false, "[mT]"},
        { 28, "kMagY           ", 0, false, "[mT]"},
        { 29, "kMagZ           ", 0, false, "[mT]"},
        { 74, "GyroX           ", 0, false, "[rad/s]"},
        { 75, "GyroY           ", 0, false, "[rad/s]"},
        { 76, "GyroZ           ", 0, false, "[rad/s]"},
    };

    qdata = {
        { 77, "kQuaternion     ", {0, 0, 0, 0}, false, ""}
    };

    chdata  = {
        { 79,"kHeadingStatus   ", '?', false, ""}
    };

    booldata = {
        { 8, "kDistortion      ", false, false, ""},
        { 9, "kCalStatus       ", false, false, ""},
    };
}
