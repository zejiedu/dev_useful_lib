#include <string>
#include <iostream>


#include "../include/string_process.h"
using namespace std;
    
 

int main()
{
    string num = "12345646.3242345";
    cout<< du::to_int(num)<<endl;
    cout<< du::to_double(num,NULL)<<endl;
    return 0;
}

