#ifndef LIBP0W3R_DISJOINT_SET_H
#define LIBP0W3R_DISJOINT_SET_H

#include <ostream>
#include <memory>

namespace libp0w3r {

    template <class T>
    class disjoint_set {

    public:

        struct Node final{
            T _data;
            std::shared_ptr<Node> _parent;
            int _rank;

            //nullptr indicates that the node instance is a root node!
            Node() : _data(), _parent(nullptr), _rank(0) {}
            Node(const T& data) : _data(data), _parent(nullptr), _rank(0) {}
            Node(const T&& data) : _data(data), _parent(nullptr), _rank(0) {}
            Node(const T& data, std::shared_ptr<Node> p) : _data(data), _parent(p), _rank(0) {}
            Node(const T&& data,  std::shared_ptr<Node>&& p) : _data(data), _parent(p), _rank(0) {}

            Node(const Node& n) = delete;
            Node(const Node&& n) = delete;
            void operator=(const Node& n) = delete;
            void operator=(const Node&& n) = delete;

            /*
             * inline friend function ->
             * When the compiler finds the friend declaration within the template class,
             * it not only finds the declaration but also the implementation and adds both to the enclosing scope.
             */
            friend std::ostream& operator<<(std::ostream& os, const Node& n) {
                os << n._data;
                return os;
            }
        };
    };

}
#endif //LIBP0W3R_DISJOINT_SET_H
