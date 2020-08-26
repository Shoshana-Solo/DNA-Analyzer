#ifndef  __EXECUTEHANDLER_H__
#define  __EXECUTEHANDLER_H__
#include <iostream>
#include <map>
#include "Load.h"



class ExecuteHandler{
public:
    ExecuteHandler();
    IExecuteHandler * convertStrToFunc(std::string str){std::cout<< "in convert";}

private:
    IExecuteHandler * m_IExecuteHandler;
//    Params * params;

};

//static void init_map_command() {
//
////    std::pair<std::string, IExecuteHandler *> PAIR1;
////    PAIR1.first = "load";
////    PAIR1.second = new Load();
////    m_commands.insert(PAIR1);
//    std::map<std::string, IExecuteHandler *> commands;
//    commands.insert(std::pair<std::string ,IExecuteHandler *>("load",new Load()));
//
//
////    return m_commands;
//}


//m_commands.insert(std::make_pair<std::string ,Command*>("load",new Load()));


#endif //__EXECUTEHANDLER_H__