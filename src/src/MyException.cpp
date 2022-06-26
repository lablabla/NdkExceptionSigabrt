
#include "MyException.h"
#include "MyExceptionImpl.h"
#include <string.h>

using namespace test::exception;

MyException::MyException(const char* msg, BlStatus status) :
        m_impl(std::make_unique<MyException::BlExceptionImpl>(msg, status))
{

}

MyException::~MyException()
{

}

MyException::MyException(const MyException& other) :
        m_impl(std::make_unique<MyException::MyExceptionImpl>(*other.m_impl))
{
}

MyException& MyException::operator=(const MyException& other)
{
    m_impl = std::make_unique<MyException::MyExceptionImpl>(*other.m_impl);
    return *this;
}

MyException::MyException(MyException&& other) noexcept :
    m_impl(std::move(other.m_impl))
{
}

MyException& MyException::operator=(MyException&& other) noexcept
{
    m_impl = std::move(other.m_impl);
    return *this;
}

const char* MyException::what() const noexcept
{
    return m_impl->what();
}

int MyException::status() const
{
    return m_impl->status();
}

MyException::MyExceptionImpl::MyExceptionImpl(const char* msg, BlStatus status) :
        m_status(status)
{
    if (strlen(msg) > MAX_LEN)
    {
        strncpy(m_msg, msg, MAX_LEN);

    }
    else
    {
        strcpy(m_msg, msg);

    }
}

const char* MyException::MyExceptionImpl::what() const
{
    return m_msg;
}

int MyException::MyExceptionImpl::status() const
{
    return m_status;
}