#ifndef LIBP0W3R_DISJOINT_SET_H
#define LIBP0W3R_DISJOINT_SET_H

#include <ostream>

namespace libp0w3r {

    template <class T>
    class disjoint_set {

    public:


        struct Node final{
            T _data;
            Node* _parent;
            int _rank;

            Node() : _data(), _parent(this), _rank(0) {}
            Node(const T& data) : _data(data), _parent(this), _rank(0) {}
            Node(const T&& data) : _data(data), _parent(this), _rank(0) {}
            Node(const T& data, Node* p) : _data(data), _parent(p), _rank(0) {}
            Node(const T&& data, Node* p) : _data(data), _parent(p), _rank(0) {}

            Node(const Node& n) = delete;
            Node(const Node&& n) = delete;
            void operator=(const Node& n) = delete;
            void operator=(const Node&& n) = delete;
        };
    };

}
#endif //LIBP0W3R_DISJOINT_SET_H
