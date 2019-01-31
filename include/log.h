#pragma once
#include<iostream>
#include <sstream> 
#include <string>       // std::string

class DUZEJIE_LOG
{
private:        
    bool out=false;
public:
    template<class T>
    DUZEJIE_LOG & operator << (T t){        
        if (out) {               
            std::cout <<t<<" ";  
        }
        return *this;
    }
    DUZEJIE_LOG(bool test):out(!test){   } 
    ~DUZEJIE_LOG(){
        if (out) {                       
            std::cout <<std ::endl;
            exit(0);       ///  
        }
    }
};



#define CHECK(x)  if (!(x)) { std::cout<<std::endl;std::cout<< __FILE__<<" at line " <<__LINE__<< "  Check failed. "; } DUZEJIE_LOG((x))
//#define CHECK(x)     if (!(x)) { std::cout<<std::endl;std::cout<< __FILE__<<" at line " <<__LINE__<< "  Check failed"<<std ::endl; exit(0); } std::cout
#define INFO       std::cout<<std::endl; std::cout<< __FILE__<<" at line " <<__LINE__<< "  INFO:" ; std::cout



