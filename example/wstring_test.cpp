#include<iostream>
#include<string>
using namespace std;

int main()
{
    wstring wstr = L"杜泽杰duzejie";
    char *s = (char*)&wstr[1];
    //char   *s = wstr[1].data();
    //wcout<< wstr[1]<<endl;

    if(wstr[1]==L'泽')
        cout<<"yes"<<endl;
    if(L'6'< L'9')
        cout<<"yes"<<endl;
}
/*
//要想输出宽字符，加上这句就可以了
    wcout.imbue(locale("", LC_CTYPE));
    wstring wstr = L"杜泽杰duzejie";
    char *s = (char*)&wstr[1];
    //char   *s = wstr[1].data();
    wcout<< wstr[1]<<endl;

    if(wstr[1]==L'泽')
        cout<<"yes"<<endl;  
*/