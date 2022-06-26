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

            MyException(const MyException &);

            MyException &operator=(const MyException &);

            MyException(MyException &&) noexcept;

            MyException &operator=(MyException &&) noexcept;

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

        protected:

            class MyExceptionImpl;
            std::unique_ptr<MyExceptionImpl> m_impl;
        };
    }
}
