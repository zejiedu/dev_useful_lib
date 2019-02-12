#pragma once
#include<iostream>
#include <sstream> 
#include <string>       // std::string

class DUZEJIE_LOG
{
private:        
    bool out;
    bool quit;
    std::ostream &o;
public:
    template<class T>
    DUZEJIE_LOG & operator << (T t){        
        if (out)           
            o <<t<<" ";         
        return *this;
    }
    DUZEJIE_LOG(bool test, bool isQuit, std::ostream &os):out(test), quit(isQuit), o(os){   } 
    ~DUZEJIE_LOG(){      
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

#define CHECK(x)       if (!(x)){ std::cerr<<std::endl;std::cerr<< getCurrentTimeStr() <<"CHECK failed: "<<__FILE__<<", line:" <<__LINE__<< ". "; } DUZEJIE_LOG(!(x), !(x),std::cerr)
#define INFO                      std::clog<<std::endl;std::clog<< getCurrentTimeStr() <<"INFO:         "<<__FILE__<<", line:" <<__LINE__<< ". ";   std::clog
#define WARNING(x)     if (!(x)){ std::clog<<std::endl;std::clog<< getCurrentTimeStr() <<"WARNING:      "<<__FILE__<<", line:" <<__LINE__<< ". "; } DUZEJIE_LOG(!(x), false, std::clog)   
#define CAUTION                   std::clog<<std::endl;std::clog<< getCurrentTimeStr() <<"CAUTION:      "<<__FILE__<<", line:" <<__LINE__<< ". ";   DUZEJIE_LOG(true, false, std::clog)   
