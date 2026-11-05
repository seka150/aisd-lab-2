export module node;

export template <typename T>
struct Node
{
    T _value;
    Node<T> *_prev;
    Node<T> *_next;
    Node(const T &value) : _value(value), _prev(nullptr), _next(nullptr) {}
};