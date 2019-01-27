#include <iostream>
#pragma once

namespace du
{

#if __cplusplus >= 201703L

//折叠表达式
template <typename... T>
auto sum(T... t)
{
    return (t + ...);
}
//std ::cout << sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << std ::endl;
#elif __cplusplus >= 201103L

#endif




} // namespace du