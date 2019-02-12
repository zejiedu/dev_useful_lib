#include <string>
#include <iostream>


#include "../include/wstring.h"
using namespace std;
    
 

int main()
{
    wcout.imbue(locale(locale(),"zh_CN.utf8",LC_CTYPE)); 
//    setlocale(LC_ALL, "zh_CN.utf8");  //locale -a

    wstring wstr = L"杜泽杰duzejie";   
    std::wcout << wstr<<endl ;     

    wchar_t wc=        wstr[1];   
    std::wcout << wc <<endl;
    
    //std::cout << du::ws2s(wc) ;
    wstring ws1(wstr[1],1);
    setlocale(LC_ALL, "C");
    std::wcout<<L"--杜泽杰---"<<endl;
    std::cout<<"--杜泽杰---"<<endl;
    return 0;
}