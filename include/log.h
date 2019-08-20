#pragma once
#include<iostream>
#include <sstream> 
#include <string>       // std::string
#include <ctime>
class Log
{
private:        
    bool out;
    bool quit;
    std::ostream &o;
public:
    template<class T>
    Log & operator << (T t){        
        if (out)           
            o <<t<<" ";         
        return *this;
    }
    Log(bool test, bool isQuit, std::ostream &os):out(test), quit(isQuit), o(os){   } 
    ~Log(){      
        if(quit)
            exit(0);       ///          
    }
};

static std::string  getCurrentTimeStr(){
	time_t t = time(NULL);
	char ch[64] = {0};
	strftime(ch, sizeof(ch) - 1, "[%Y-%m-%d %H:%M:%S]", localtime(&t));     //年-月-日 时-分-秒
	return ch;
}

#define CHECK(x)       if (!(x)){ std::cerr<<std::endl;std::cerr<< getCurrentTimeStr() <<"CHECK failed: "<<__FILE__<<", line:" <<__LINE__<< ". "; } Log(!(x), !(x),std::cerr)
#define INFO                      std::clog<<std::endl;std::clog<< getCurrentTimeStr() <<"INFO:         "<<__FILE__<<", line:" <<__LINE__<< ". ";   std::clog
#define WARNING(x)     if (!(x)){ std::clog<<std::endl;std::clog<< getCurrentTimeStr() <<"WARNING:      "<<__FILE__<<", line:" <<__LINE__<< ". "; } Log(!(x), false, std::clog)   
#define CAUTION                   std::clog<<std::endl;std::clog<< getCurrentTimeStr() <<"CAUTION:      "<<__FILE__<<", line:" <<__LINE__<< ". ";   Log(true, false, std::clog)   
    


    