#include<iostream>
#include<string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "zh_CN.utf8");  // $locale -a #列出系统支持的编码，在程序调用宽体字符前设置编码格式。
                                      // 会导致wcout与cout冲突，只能全局用宽体字符
    wstring wstr = L"杜泽杰duzejie";
    char *s = (char*)&wstr[1];
    //char   *s = wstr[1].data();
    //wcout<< wstr[1]<<endl;

    if(wstr[1]==L'泽')
        wcout<<L"yes"<<endl;
    if(L'6'< L'9')
        wcout<<L"yes"<<endl;

    std::wcout<<L"--杜泽杰---"<<endl;
  
}
