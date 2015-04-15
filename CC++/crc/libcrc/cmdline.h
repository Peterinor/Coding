
#ifndef _CMDLINE_H_
#define _CMDLINE_H_

#include <string>
using namespace std;

namespace cmdline{
    class Parser{
    public:
        Parser(){
        }

        Parser(int argc, char *argv[]){
        }

        template<class T>
        void add(string name, string shortcut, string description, bool mandatory, T defVaule){

        }
    };
}

#endif