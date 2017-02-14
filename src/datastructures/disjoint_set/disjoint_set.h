#ifndef LIBP0W3R_DISJOINT_SET_H
#define LIBP0W3R_DISJOINT_SET_H

#include <ostream>
#include <memory>
#include "../../exceptions/Libp0w3rException.h"

namespace libp0w3r {

    template <class T>
    class disjoint_set {

    public:

        class Node final {
            T _data;
            std::shared_ptr<Node> _parent;
            int _rank;

        public:
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

            inline const T& getData() const {
                return _data;
            }

            inline void setData(const T& data) {
                _data = data;
            }

            inline const std::shared_ptr<Node>& getParent() const {
                return _parent;
            }

            inline void setParent(const std::shared_ptr<Node>& parent) throw(Libp0w3rException){
                if(parent)
                    _parent = parent;
                else
                    throw IllegalNullptrAssignmentException("disjoint_set::Node::setParent( nullptr )");
            }

            inline int getRank() const {
                return _rank;
            }

            inline void setRank(int rank) {
                _rank = rank;
            }

            /*
             * inline friend function ->
             * When the compiler finds the friend declaration within the template class,
             * it not only finds the declaration but also the implementation and adds both to the enclosing scope.
             */
            inline friend std::ostream& operator<<(std::ostream& os, const Node& n) {
                os << n._data;
                return os;
            }

            inline bool operator==(const Node& rhs) const {
                return this->_data == rhs._data;
            }

            inline bool operator!=(const Node& rhs) const {
                return !this->operator==(rhs);
            }
        };
    };

}
#endif //LIBP0W3R_DISJOINT_SET_H
