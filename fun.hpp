#pragma once

#if __cplusplus >= 201402L

#elif __cplusplus >= 201102L

#include <memory>
template <typename T, typename... Args>
std ::unique_ptr<T> make_unique(Args &&... args)
{
    return std ::unique_ptr<T>(new T(std ::forward<Args>(args)...));
}
#endif
