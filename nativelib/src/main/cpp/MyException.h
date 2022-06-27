#pragma once

#include "DllExport.h"
#include <memory>


namespace test
{
    namespace exception
    {
    class DLL_EXPORT MyException : public std::exception {
        public:
            MyException(const char *msg, int status);

            virtual ~MyException();

            MyException(const MyException &) = default;

            MyException &operator=(const MyException &) = default;

            MyException(MyException &&) noexcept = default;

            MyException &operator=(MyException &&) noexcept = default;

            /**
             * @brief Returns an error message that describes the error.
             * @return Error message.
            */
            const char *what() const noexcept override;

            /**
             * @brief Returns an error status code.
             * @return Error status.
            */
            int status() const;

    private:

        int m_status;
        static const size_t MAX_LEN = 200;
        char m_msg[MAX_LEN];
        };
    }
}
