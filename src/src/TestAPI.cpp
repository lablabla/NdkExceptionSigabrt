
#include "TestAPI.h"
#include "TestAPIImpl.h"
#include "MyException.h"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/syslog_sink.h>
#include <syslog.h>

namespace test
{
    Tester::Tester() :
        m_impl(std::make_unique<Tester::TesterImpl>())
    {
        try {
            auto syslog_logger = spdlog::syslog_logger_mt("syslog", "spdlog-android", LOG_PID);
            spdlog::set_default_logger(syslog_logger);
            spdlog::set_level(spdlog::level::trace);

            throw exception::MyException("This is a test exception", 1);
        }
        catch (exception::MyException& ex)
        {
            spdlog::error("Caught exception MyException with status {}", ex.status());
            throw;
        }
        catch (spdlog::spdlog_ex& ex) {
            spdlog::info("System logger already exists. Ignoring.");
        }
    }

    Tester::~Tester()
    {
    }

    Tester::Tester(Tester&& other) noexcept :
        m_impl(std::move(other.m_impl))
    {
    }

    Tester& Tester::operator=(Tester&& other) noexcept
    {
        m_impl = std::move(other.m_impl);
        return *this;
    }

    Tester::TesterImpl::TesterImpl()
    {

    }
}