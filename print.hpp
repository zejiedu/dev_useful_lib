#include <iostream>
namespace du
{

#if __cplusplus >= 201703L
template <typename T0, typename... T>
void print(T0 t0, T... t)
{
    std ::cout << t0;
    if constexpr (sizeof...(t) >= 1){
        std ::cout << " ";
        print(t...);
    }    
}
#elif __cplusplus >= 201103L
template <typename T>
void print(T x)
{
    std ::cout << x;
}
template <typename T, typename... Args>
void print(T x, Args... args)
{
    //std :: cout << sizeof ...( args ) << std :: endl ;
    std ::cout << x << " ";
    print(args...);
}
#endif

} // namespace du