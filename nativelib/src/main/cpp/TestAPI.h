#pragma once

#include "DllExport.h"
#include <memory>

namespace test
{
    class DLL_EXPORT Tester
    {
    public:
        Tester();
        virtual ~Tester() = default;

        Tester(const Tester&) = delete;
        Tester& operator=(const Tester&) = delete;
        Tester(Tester&&) noexcept = default;
        Tester& operator=(Tester&&) noexcept = default;
    };
}