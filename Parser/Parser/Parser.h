#ifndef PARSER_H
#define PARSER_H

#include <cstdint>
#include <string>
#include <vector>

struct FloatData;
struct QuaternionData;
struct BoolData;
struct CharData;

class Parser
{
public:
    void PrintData();
    void Parse(const char* msg);
    Parser();

private:
    int8_t Passport(char ch);
    int8_t Collector(int8_t lhs, int8_t rhs);
    std::vector<FloatData> fdata;
    std::vector<QuaternionData> qdata;
    std::vector<BoolData> booldata;
    std::vector<CharData> chdata;

};

struct FloatData
{
    int8_t id = 0;
    std::string name = "";
    float value = 0;
    bool isTransmit = false;
    std::string unit = "";
};

struct QuaternionData
{
    int8_t id = 0;
    std::string name = "";
    float value[4] = {0, 0, 0, 0};
    bool isTransmit = false;
    std::string unit = "";
};

struct BoolData
{
    int8_t id = 0;
    std::string name = "";
    bool value = false;
    bool isTransmit = false;
    std::string unit = "";
};

struct CharData
{
    int8_t id = 0;
    std::string name = "";
    char value = ' ';
    bool isTransmit = false;
    std::string unit = "?";
};

#endif // PARSER_H



