#pragma once

#include "TestAPI.h"

namespace test
{
    class Tester::TesterImpl
    {
    public:

        TesterImpl();

        ~TesterImpl() = default;

        TesterImpl(const TesterImpl&) = delete;
        TesterImpl& operator=(const TesterImpl&) = delete;

        TesterImpl(TesterImpl&&) noexcept = default;
        TesterImpl& operator=(TesterImpl&&) noexcept = default;
    };
}