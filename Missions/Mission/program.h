#ifndef PROGRAM_H
#define PROGRAM_H

#include<list>
#include<memory>
#include<vector>
#include<fstream>
#include"mission.h"


enum class Exit{Saving, WithoutSaving};
enum class cmd {non, clear, help, exit, open, close, save, add, rm, edit, mv, chk, lk, wf, rename};

class Program
{
public:
    Program();
    //Program(const char* file);
    void run();
//private:
    void wf();
    void non(); //Боже, это что-то стремное..
    void clear();
    void help();
    void exit();
    void open(std::string& filename);
    void close();
    void save();
    void parse(std::string &data);
    void rename(std::string& filename);
    void add(const std::vector<std::string>& cmd);
    void rm(const std::vector<std::string>& cmd);
    void edit(const std::vector<std::string>& cmd);
    void mv(const std::vector<std::string>& cmd);
    void chk();
    void lk(const std::vector<std::string>& cmd);

    cmd hashit (std::string const& command );
    std::list<std::unique_ptr<Mission>>::iterator getIt(size_t index, bool &error);
    bool is_number(std::string str);
    void editMode(const std::vector<std::string>& cmd, std::list<std::unique_ptr<Mission>>::iterator it);


    double X = 0, Y = 0, Z = 0;
    bool Exit = 0;
    bool is_save = false;
    bool erors = false;
    std::string filename = "";
    int countOfMission = 0;
    std::list<std::unique_ptr<Mission>> task;
};



#endif // PROGRAM_H
