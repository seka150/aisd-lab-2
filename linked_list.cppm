export module linked_list;
import node;
import std;

export template <typename T>
class LinkedList
{
private:
    Node<T> *_head;
    Node<T> *_tail;
    int _size;

public:
    LinkedList() : _head(nullptr), _tail(nullptr), _size(0) {};

    LinkedList(const LinkedList &other) : _head(nullptr), _tail(nullptr), _size(0)
    {
        Node<T> *cur = other._head;
        while (cur)
        {
            push_tail(cur->_value);
            cur = cur->_next;
        }
    }

    int size() const
    {
        return _size;
    }

    LinkedList &operator=(const LinkedList &other)
    {
        if (this == &other)
        {
            return *this;
        }
        while (_head != nullptr)
        {
            pop_heads();
        }
        Node<T> *cur = other._head;
        while (cur)
        {
            push_tail(cur->_value);
            cur = cur->_next;
        }
        return *this;
    }

    ~LinkedList()
    {
        Node<T> *cur = _head;
        while (cur)
        {
            Node<T> *next = cur->_next;
            delete cur;
            cur = next;
        }
    }

    void push_tail(const T &value)
    {
        Node<T> *new_node = new Node<T>(value);
        if (_head == nullptr)
        {
            _head = new_node;
            _tail = new_node;
        }
        else
        {
            new_node->_prev = _tail;
            _tail->_next = new_node;
            _tail = new_node;
        }
        ++_size;
    }

    void push_head(const T &value)
    {
        Node<T> *new_node = new Node<T>(value);
        if (_head == nullptr)
        {
            _head = new_node;
            _tail = new_node;
        }
        else
        {
            new_node->_next = _head;
            _head->_prev = new_node;
            _head = new_node;
        }
        ++_size;
    }

    void pop_heads()
    {
        if (_head == nullptr)
        {
            throw std::out_of_range("List is empty");
        }

        Node<T> *temp = _head;
        _head = _head->_next;

        if (_head != nullptr)
        {
            _head->_prev = nullptr;
        }
        else
        {
            _tail = nullptr;
        }
        delete temp;
        --_size;
    }

    void pop_tails()
    {
        if (_tail == nullptr)
        {
            throw std::out_of_range("List is empty");
        }

        Node<T> *temp = _tail;
        _tail = _tail->_prev;

        if (_tail != nullptr)
        {
            _tail->_next = nullptr;
        }
        else
        {
            _head = nullptr;
        }
        delete temp;
        --_size;
    }

    void push_tail(const LinkedList &other)
    {
        if (this == &other)
        {
            LinkedList copy(other);
            push_tail(copy);
            return;
        }

        Node<T> *cur = other._head;
        while (cur)
        {
            push_tail(cur->_value);
            cur = cur->_next;
        }
    }

    void push_head(const LinkedList &other)
    {
        if (this == &other)
        {
            LinkedList copy(other);
            push_head(copy);
            return;
        }
        Node<T> *cur = other._tail;
        while (cur)
        {
            push_head(cur->_value);
            cur = cur->_prev;
        }
    }

    void delete_node(const T &value)
    {
        Node<T> *cur = _head;
        while (cur)
        {
            if (cur->_value == value)
            {
                if (cur == _head)
                {
                    pop_heads();
                }
                else if (cur == _tail)
                {
                    pop_tails();
                }
                else
                {
                    cur->_prev->_next = cur->_next;
                    cur->_next->_prev = cur->_prev;

                    delete cur;
                    --_size;
                }
                return;
            }
            cur = cur->_next;
        }
        throw std::out_of_range("Element not found");
    }

    T &operator[](int index)
    {
        if (index < 0 || index >= _size)
        {
            throw std::out_of_range("Index out of range");
        }

        Node<T> *cur = _head;
        for (int i = 0; i < index; ++i)
        {
            cur = cur->_next;
        }
        return cur->_value;
    }

    const T &operator[](int index) const
    {
        if (index < 0 || index >= _size)
        {
            throw std::out_of_range("Index out of range");
        }
        const Node<T> *cur = _head;
        for (int i = 0; i < index; ++i)
        {
            cur = cur->_next;
        }
        return cur->_value;
    }
};

export template <typename T>
std::ostream &operator<<(std::ostream &out, const LinkedList<T> &list)
{
    for (int i = 0; i < list.size(); ++i)
    {
        out << list[i] << " ";
    }
    return out;
}