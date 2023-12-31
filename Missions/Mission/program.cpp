#include <conio.h> //clrscr();
#include <iostream>
#include <fstream>
#include <memory>
#include <sstream>
#include <iterator>
#include <vector>

#include "program.h"
#include "mission.h"
#include "lift.h"
#include "return.h"
#include "dive.h"
#include "move.h"



Program::Program()
{


}

void Program::run()
{
    while(!this->Exit)
    {
       std:: cout <<"#> ";
       std::string cmd;
       std::getline(std::cin, cmd);
       cmd += " #end#";
       std::stringstream ss(cmd);
       std::istream_iterator<std::string> begin(ss);
       std::istream_iterator<std::string> end;
       std::vector<std::string> command(begin, end);

       switch (hashit(command[0]))
        {
           case cmd::clear: { this->clear();              break; } //
           case cmd::help:  { this->help();               break; }
           case cmd::exit:  { this->exit();               break; }
           case cmd::open:  { this->open(command[1]);     break; }
           case cmd::close: { this->close();              break; }
           case cmd::save:  { this->save();               break; }
           case cmd::add:   { this->add(command);         break; }
           case cmd::rm:    { this->rm(command);          break; }
           case cmd::edit:  { this->edit(command);        break; }
           case cmd::mv:    { this->mv(command);          break; }
           case cmd::chk:   { this->chk();                break; }
           case cmd::lk:    { this->lk();                 break; }
           case cmd::non:   { this->non();                break; }
           case cmd::wf:    { this->wf();                 break; }
           case cmd::rename:{ this->rename(command[1]);   break; }

        default:{
           std::cout << "There is no such command." << std::endl;
           break;}
        }
    }
}

void Program::wf()
{
    if (this->filename == "") {std::cout << "File without a name." << std::endl; return;}
    std::cout << "File name: "<< this->filename << std::endl;
}

void Program::non()
{
   // std::cout << "There is no such command." << std::endl;
}

void Program::clear()
{
    system("cls");
}

void Program::help()
{
    std::cout << "Syntax:  [COMMAND] [KEY_1], [KEY_2], ... \n\nCommands:" << std::endl;

    std::cout << "clear \t\t\t\t\t - Clear console\n"<< std::endl;
    std::cout << "wf \t\t\t\t\t - Print filename\n"<< std::endl;
    std::cout << "rename [filename] \t\t\t - Rename file\n"<< std::endl;
    std::cout << "exit \t\t\t\t\t - exit program\n"<< std::endl;
    std::cout << "open [filename] \t\t\t - open file [filename] and load mission data.\n"<< std::endl;
    std::cout << "close \t\t\t\t\t - close opened file.\n"<< std::endl;
    std::cout << "save [filename] \t\t\t - sawe file with name [filename].\n"<< std::endl;
    std::cout << "add [TypeMission] \t\t\t - add mission to end list of mission."
              << "\t\t\t\t\t\t\t\t\t\t - TypeMission: Return, Move, Lift, Dive; \n" << std::endl;

    std::cout << "rm [index] \t\t\t\t - remowe mission lacated by [index].\n"<< std::endl;

    std::cout << "mv [destIndex] [sourceIndex] \t\t - Move mission lacated by [surceIndex] to [destIndex] location.\n"<< std::endl;

    std::cout << "chk \t\t\t\t\t - Check the correctness of the mission.\n"<< std::endl;
    std::cout << "lk \t\t\t\t\t - Print list of mission.\n"<< std::endl;

    std::cout << "edit [Index] [arg_1] [arg_2] ... \t - Edit parameters of mission locaded by [index]. \n" << std::endl;
    std::cout << "See the arguments depended on the type fo mission:" << std::endl;

    std::cout << "Dive [depth] [sns] [type] \t\t - Dive to [depth], use sensor [sns]. Type of movment [type]. \n"
              << "\t\t\t\t\t - depth: [0,-100] m; \n"
              << "\t\t\t\t\t - types:  0 - Stiral, 1 - Straight, 2 - Oher;\n"
              << "\t\t\t\t\t - sensor: 0 - EchoSounder, 1 - Depth, 2 - Other;\n" << std::endl;

    std::cout << "Lift [depth] [sns] [type] \t\t - Lift to [depth], use sensor [sns]. Type of movment [type]. \n"
              << "\t\t\t\t\t - depth: [0,-100] m; \n"
              << "\t\t\t\t\t - types: 0 - Stiral, 1 - Straight, 2 - Oher;\n"
              << "\t\t\t\t\t - sensor: 0 - EchoSounder, 1 - Depth, 2 - Other;\n" << std::endl;

    std::cout << "Move [x] [y] [type] [sns] [accuracy] \t - Move to point [x],[y] with precision [accuracy], use sensor [sns]. Type of movment [type]. \n"
              << "\t\t\t\t\t - x,y: [0,10000] m; \n"
              << "\t\t\t\t\t - types: 0 - Stiral, 1 - Straight, 2 - Oher;\n"
              << "\t\t\t\t\t - sensor: 0 - EchoSounder, 1 - Depth, 2 - Other;\n"
              << "\t\t\t\t\t - accurancy: [0-100] m.\n" << std::endl;

    std::cout << "Return \t\t\t\t\t - Returning the ROV back to the starting point."  << std::endl;
}

void Program::exit()
{
    this->Exit = 1;
}

void Program::open(std::string& filname)
{
    this->filename = filname;
    std::ifstream file;
    std::string data;
    file.open(this->filename);
    if(file.is_open()) {
        while (std::getline(file, data)) {
            this->parse(data);
        }
    } else {
        std::cout << "File no open" << std::endl;
    }
}

void Program::close()
{
    if (is_save) {
        task.clear();
        this->filename = "";
    } else {
        char ans = ' ';
        std::cout << "Do you want to save the file? (y/n)"  << std::endl;
        while (!(ans == 'y' || ans == 'n')) {
            std::cin >> ans;
        }
        if (ans == 'n')
        {
            task.clear();
            this->countOfMission = 0;
        }
        else
        {
            this->save();
            task.clear();
            this->filename = "";
        }
    }
}

void Program::save()
{
    if (erors){ this->chk(); return;}
    std::ofstream file;
    if (this->filename == "") {
        std::cout << "Enter file name" << std::endl;
        std::cin >> this->filename;
    }
    file.open(filename, std::ios_base::out);
    if(file.is_open()) {
        for (auto &i : task) {
            i.get()->save(file);
        }
        is_save = true;
    }
    else
    {
        std::cout << "Error Open file: " << filename[1] << std::endl;
    }
    file.close();
}

void Program::parse(std::string &data)
{
    std::stringstream ss(data);
    std::istream_iterator<std::string> begin(ss);
    std::istream_iterator<std::string> end;
    std::vector<std::string> token(begin, end);

    if (token[0] == "Move")
    {
        this->countOfMission++;
        this->task.push_back(std::make_unique<Move>());
        auto ptr = dynamic_cast<Move*>(this->task.back().get());
        ptr->setData(std::stoi(token[3]), std::stoi(token[5]), (Action)std::stoi(token[17]), (Sensor)std::stoi(token[13]), std::stoi(token[9]));
        return;
    }
    if (token[0] == "Dive")
    {
        this->countOfMission++;
        this->task.push_back(std::make_unique<Dive>());
        auto ptr = dynamic_cast<Dive*>(this->task.back().get());
        ptr->setData(std::stoi(token[2]), (Sensor)std::stoi(token[6]), (Action)std::stoi(token[10]));
        return;
    }
    if (token[0] == "Lift")
    {
        this->countOfMission++;
        this->task.push_back(std::make_unique<Lift>());
        auto ptr = dynamic_cast<Lift*>(this->task.back().get());
        ptr->setData(std::stoi(token[2]), (Sensor)std::stoi(token[6]), (Action)std::stoi(token[10]));
        return;
    }
    if (token[0] == "Return")
    {
        this->countOfMission++;
        this->task.push_back(std::make_unique<Return>());
        return;
    }
}

void Program::rename(std::string& name )
{
    this->filename = name;
}

void Program::add(const std::vector<std::string> &cmd)
{
    if(cmd[1] == "Dive")   {this->task.push_back(std::make_unique<Dive>());   is_save = false;  countOfMission++; return;}
    if(cmd[1] == "Lift")   {this->task.push_back(std::make_unique<Lift>());   is_save = false;  countOfMission++; return;}
    if(cmd[1] == "Move")   {this->task.push_back(std::make_unique<Move>());   is_save = false;  countOfMission++; return;}
    if(cmd[1] == "Return") {this->task.push_back(std::make_unique<Return>()); is_save = false;  countOfMission++; return;}
    std::cout << "No such mission" << std::endl;
}

void Program::rm(const std::vector<std::string>& cmd)
{
    if (countOfMission == 0)
    {
        std::cout << "There are no missions." << std::endl;
        return;
    }
    if (cmd.size() > 3) { std::cout << "There are to many argument." << std::endl; return; }
    if (cmd.size() < 3) { std::cout << "There are to few argument."  << std::endl; return; }
    if (!this->is_number(cmd[1])) {
        std:: cout << "argument: " << cmd[1] << " no number!" << std::endl;
        return;
    }

    bool error = false;
    auto it = this->getIt(std::stoi(cmd[1]), error);
    if (!error)
    {
        this->task.erase(it);
        countOfMission--;
        is_save = false;
    } else
    {
        std::cout << "No such index." << std::endl;
    }
}

void Program::edit(const std::vector<std::string>& cmd)
{
    if (countOfMission == 0)
    {
        std::cout << "There are no missions." << std::endl;
        return;
    }
    if (!this->is_number(cmd[1])) {
        std:: cout << "argument: " << cmd[1] << " no number!" << std::endl;
        return;
    }
    bool error = false;
    auto it = this->getIt(std::stoi(cmd[1]), error);
    if (!error)
    {
        this->editMode(cmd, it);
    }
    else
    {
        std::cout << "No such index." << std::endl;
    }
}

void Program::mv(const std::vector<std::string>& cmd)
{
    if (countOfMission == 0)
    {
        std::cout << "There are no missions." << std::endl;
        return;
    }
    bool error = false;
    if (cmd.size() > 4) { std::cout << "There are to many argument." << std::endl; return; }
    if (cmd.size() < 4) { std::cout << "There are to few argument."  << std::endl; return; }
    if (!(is_number(cmd[1]) && is_number(cmd[2]))) { std::cout <<"There is a non-numeric argument."<<std::endl; return;}
    auto lhs = this->getIt(std::stoi(cmd[1]), error);
    auto rhs = this->getIt(std::stoi(cmd[2]), error);
    if (!error)
    {
       is_save = false;
       this->task.splice(lhs, this->task, rhs);
    }
    else
    {
        std::cout << "No such index." << std::endl;
    }
}

void Program::chk()
{
    int numberMission = 0;
    for (auto &v : this->task) {
        if(v.get()->getTypeMission() == Type::Return)
        {
            X += -X;
            Y += -Y;
            Z += -Z;
        }
        if(v.get()->getTypeMission() == Type::Move)
        {
            auto ptr = dynamic_cast<Move*>(v.get());
            X = ptr->data.x;
            Y = ptr->data.y;
        }
        if(v.get()->getTypeMission() == Type::Dive) {
            auto ptr = dynamic_cast<Dive*>(v.get());
            Z = ptr->data.dive;
        }
        if(v.get()->getTypeMission() == Type::Lift) {
            auto ptr = dynamic_cast<Lift*>(v.get());
            Z = ptr->data.lift;
        }
        if( !((X>=0 && X<=10000) && (Y>=0 && Y<=10000) && (Z>=0 && Z <=100 )))
        {
            erors = true;
            std::cout << "ERROR The mission " << numberMission << " crouched down to a mistake." << std::endl;
            return;
        }
        numberMission++;
    }
    if (this->task.back().get()->getTypeMission() != Type::Return) {
        std::cout << "Mission planning should end with a Return!" << std::endl;
        erors = true;
        return;
    }
    std::cout << "There are no mistakes" << std::endl;
}

void Program::lk()
{
    int i = 0;
    if (countOfMission == 0) {std::cout << "There are no missions yet" << std::endl; return;}
    std::cout << std::endl;
    for (auto &v : this->task) {
        std::cout << i << ") ";
        v->print();
        i++;
    }
    std::cout << std::endl;
}

cmd Program::hashit(const std::string &command)
{
    if ( command == "help" ) return cmd::help;
    if ( command == "clear") return cmd::clear;
    if ( command == "exit" ) return cmd::exit;
    if ( command == "open" ) return cmd::open;
    if ( command == "close") return cmd::close;
    if ( command == "save" ) return cmd::save;
    if ( command == "add"  ) return cmd::add;
    if ( command == "rm"   ) return cmd::rm;
    if ( command == "edit" ) return cmd::edit;
    if ( command == "mv"   ) return cmd::mv;
    if ( command == "chk"  ) return cmd::chk;
    if ( command == "lk"   ) return cmd::lk;
    if ( command == "wf"   ) return cmd::wf;
    if ( command == "rename"   ) return cmd::rename;

    return cmd::non;
}

std::list<std::unique_ptr<Mission>>::iterator Program::getIt(size_t index, bool &error)
{
    std::list<std::unique_ptr<Mission>>::iterator it = this->task.begin();
    if (countOfMission < index)
    {
        error = true;
        return it;
    }
    while (index != 0) {
        index--;
        it++;
    }
    return it;
}

bool Program::is_number(std::string str)
{
    bool res = true;
    for (auto ch : str) {
        res *= (ch >= '0' && ch <= '9');
    }
    return res;
}

void Program::editMode(const std::vector<std::string> &cmd, std::list<std::unique_ptr<Mission>>::iterator it)
{
    if (it->get()->getTypeMission() == Type::Dive)
    {
        if (cmd.size() > 6) { std::cout << "There are to many argument." << std::endl; return; }
        if (cmd.size() < 6) { std::cout << "There are to few argument."  << std::endl; return; }
        if (!(is_number(cmd[2]) && is_number(cmd[3]) && is_number(cmd[4]))) { std::cout <<"There is a non-numeric argument."<<std::endl; return;}

            auto ptr = dynamic_cast<Dive*>(it->get());
            is_save = false;
            ptr->setData(std::stoi(cmd[2]), (Sensor)std::stoi(cmd[3]), (Action)std::stoi(cmd[4]));
    }
    if (it->get()->getTypeMission() == Type::Lift)
    {
        if (cmd.size() > 6) { std::cout << "There are to many argument." << std::endl; return; }
        if (cmd.size() < 6) { std::cout << "There are to few argument."  << std::endl; return; }
        if (!(is_number(cmd[2]) && is_number(cmd[3]) && is_number(cmd[4]))) { std::cout <<"There is a non-numeric argument."<<std::endl; return;}

            auto ptr = dynamic_cast<Lift*>(it->get());
            is_save = false;
            ptr->setData(std::stoi(cmd[2]), (Sensor)std::stoi(cmd[3]), (Action)std::stoi(cmd[4]));
    }
    if (it->get()->getTypeMission() == Type::Move) {
        if (cmd.size() > 8) { std::cout << "There are to many argument." << std::endl; return; }
        if (cmd.size() < 8) { std::cout << "There are to few argument."  << std::endl; return; }
        if (!(is_number(cmd[2]) && is_number(cmd[3]) && is_number(cmd[4]) && is_number(cmd[5]) && is_number(cmd[6]))) { std::cout <<"There is a non-numeric argument."<<std::endl; return;}

            auto ptr = dynamic_cast<Move*>(it->get());
            is_save = false;
            ptr->setData(std::stoi(cmd[2]), std::stoi(cmd[3]), (Action)std::stoi(cmd[4]), (Sensor)std::stoi(cmd[5]), std::stoi(cmd[6]));
    }


}


