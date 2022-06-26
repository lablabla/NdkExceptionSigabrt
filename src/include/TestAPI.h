#pragma once

#include "DllExport.h"
#include <memory>

namespace test
{
    class DLL_EXPORT Tester
    {
    public:
        Tester();
        virtual ~Tester();

        Tester(const Tester&) = delete;
        Tester& operator=(const Tester&) = delete;
        Tester(Tester&&) noexcept;
        Tester& operator=(Tester&&) noexcept;

    protected:

        class TesterImpl;
        std::unique_ptr<TesterImpl> m_impl;
    };
}