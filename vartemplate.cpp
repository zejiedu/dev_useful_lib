
#include "print.hpp"
#include "math.hpp"
using namespace du;

using namespace std;

int main()
{
    print(1, "23", "ty\n");
    print(1, 2, 3, "34www\n");
    std::cout << __cplusplus << std::endl;
    std ::cout << du::sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << std ::endl;
    std ::cout << __LINE__<<  __FILE__ <<std ::endl;
}
