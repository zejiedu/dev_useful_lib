#include <string>
#include <iostream>


#include "../include/time_process.h"
using namespace std;
    
#include <stdio.h>
#include <time.h>
long fibonacci(unsigned n)
{
    if (n < 2) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}
using namespace std;
int main ()
{
    cout<<get_time_stamp()<<endl;
    cout<<get_local_time_str()<<endl;
    cout<<to_tm_str(to_local_time(time(nullptr)))<<endl;

    Timer t("fibonacci_time");
    
    auto start = std::chrono::system_clock::now();
    std::cout << "f(42) = " << fibonacci(42) << '\n';
    auto end = std::chrono::system_clock::now(); 
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
 
    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";

    return 0;
}
