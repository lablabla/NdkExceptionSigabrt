
#include "MyException.h"
#include <string.h>

using namespace test::exception;

MyException::MyException(const char* msg, int status) :
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

MyException::~MyException()
{

}

const char* MyException::what() const noexcept
{
    return m_msg;
}

int MyException::status() const
{
    return m_status;
}