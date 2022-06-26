
#include "MyException.h"

namespace test
{
    namespace exception {
        class MyException::MyExceptionImpl {
        public:
            MyExceptionImpl(const char *msg, int status);

            ~MyExceptionImpl() = default;

            MyExceptionImpl(const MyExceptionImpl &) = default;

            MyExceptionImpl &operator=(const MyExceptionImpl &) = default;

            MyExceptionImpl(MyExceptionImpl &&) noexcept = default;

            MyExceptionImpl &operator=(MyExceptionImpl &&) noexcept = default;

            const char *what() const;

            int status() const;

        private:

            int m_status;
            static const size_t MAX_LEN = 200;
            char m_msg[MAX_LEN];
        };
    }
}
