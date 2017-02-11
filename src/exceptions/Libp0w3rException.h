#ifndef LIBP0W3R_LIBP0W3REXCEPTION_H
#define LIBP0W3R_LIBP0W3REXCEPTION_H

#include <exception>
#include <sstream>

namespace libp0w3r {

    class Libp0w3rException : public std::exception {
    protected:
        std::string _msg;

    public:
        Libp0w3rException() {
            _msg.append("libp0w3r Exception thrown!\n");
        }

        virtual const char* what() const noexcept override {
            return _msg.c_str();
        }
    };

    class IllegalNullptrAssignmentException : public Libp0w3rException {
    public:
        IllegalNullptrAssignmentException(const std::string& msg) {
            _msg.append("=> IllegalNullptrAssignmentException\n");
            _msg.append(msg);
        }
    };
}

#endif //LIBP0W3R_LIBP0W3REXCEPTION_H
