#ifndef LIBP0W3R_LIBP0W3REXCEPTION_H
#define LIBP0W3R_LIBP0W3REXCEPTION_H

#include <exception>
#include <sstream>

namespace libp0w3r {

    class Libp0w3rException : public std::exception {
    protected:
        std::stringstream _msgBuffer;
        std::string _msg;

    public:
        Libp0w3rException() {
            _msgBuffer << "libp0w3r Exception thrown!" << std::endl;
            _msg = _msgBuffer.str();
        }

        virtual const char* what() const noexcept override {
            return _msg.c_str();
        }
    };

}

#endif //LIBP0W3R_LIBP0W3REXCEPTION_H
