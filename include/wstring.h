#include<string>
#include <locale>
#include <codecvt>
#pragma once

namespace du
{
        using convert_typeX = std::codecvt_utf8<wchar_t>;

        static std::wstring s2ws(const std::string& str)
        {
            std::wstring_convert<convert_typeX, wchar_t> converterX;

            return converterX.from_bytes(str);

        }

        static std::string ws2s(const std::wstring& wstr)
        {
            std::wstring_convert<convert_typeX, wchar_t> converterX;

            return converterX.to_bytes(wstr);

        }
}
