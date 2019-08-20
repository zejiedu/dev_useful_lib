
#include "print.hpp"
#include "math.hpp"
#include "fun.hpp"
#include <memory>
#include <any>
#include <string>
using namespace du;

using namespace std;

int main(){
    std ::cout << __LINE__<<  __FILE__ <<std ::endl;
    std::cout << __cplusplus << std::endl;
    //auto ini = {1,2,3,4,5,6,"duzejie"};
    initializer_list<any> ini = {1,2,3,4,5,6};
    for(auto x:ini)
        cout<<any_cast<int>(x)<<endl;
         
}
