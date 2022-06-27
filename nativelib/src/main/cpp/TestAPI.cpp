
#include "TestAPI.h"
#include "MyException.h"

namespace test
{
    Tester::Tester()
    {
        try {
            throw exception::MyException("This is a test exception", 1);
        }
        catch (exception::MyException& ex)
        {
            printf("Caught exception %s", ex.what());
            throw;
        }
    }
}