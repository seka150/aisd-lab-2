import std;
import linked_list;

int main()
{
    try
    {
        std::cout << "1. DEFAULT CONSTRUCTOR\n";

        LinkedList<int> list;

        std::cout << "Empty list: " << list << '\n';
        std::cout << "Size: " << list.size() << "\n\n";

        std::cout << "2. PUSH TAIL / PUSH HEAD\n";

        list.push_tail(10);
        list.push_tail(20);
        list.push_tail(30);
        list.push_head(5);

        std::cout << "List: " << list << '\n';
        std::cout << "Size: " << list.size() << "\n\n";

        std::cout << "3. COPY CONSTRUCTOR\n";

        LinkedList<int> copy(list);

        std::cout << "Original: " << list << '\n';
        std::cout << "Copy:     " << copy << "\n\n";

        std::cout << "4. ASSIGNMENT OPERATOR\n";

        LinkedList<int> assigned;
        assigned = list;

        std::cout << "Assigned: " << assigned << '\n';

        assigned = assigned;

        std::cout << "After self-assignment: "
                  << assigned << "\n\n";

        std::cout << "5. PUSH ANOTHER LIST\n";

        LinkedList<int> second;
        second.push_tail(40);
        second.push_tail(50);

        list.push_tail(second);

        std::cout << "After push_tail: " << list << '\n';

        list.push_head(second);

        std::cout << "After push_head: " << list << "\n\n";

        std::cout << "6. PUSH LIST TO ITSELF\n";

        LinkedList<int> self_list;
        self_list.push_tail(1);
        self_list.push_tail(2);
        self_list.push_tail(3);

        self_list.push_tail(self_list);

        std::cout << "After self push_tail: "
                  << self_list << '\n';

        self_list.push_head(self_list);

        std::cout << "After self push_head: "
                  << self_list << "\n\n";

        std::cout << "7. POP HEAD / POP TAIL\n";

        list.pop_heads();
        std::cout << "After pop_heads: " << list << '\n';

        list.pop_tails();
        std::cout << "After pop_tails: " << list << "\n\n";

        std::cout << "8. DELETE NODE\n";

        LinkedList<int> duplicates;

        duplicates.push_tail(10);
        duplicates.push_tail(20);
        duplicates.push_tail(10);
        duplicates.push_tail(30);
        duplicates.push_tail(10);

        std::cout << "Before deletion: " << duplicates << '\n';

        duplicates.delete_node(10);

        std::cout << "After delete_node(10): "
                  << duplicates << "\n\n";

        std::cout << "9. INDEX OPERATOR\n";

        std::cout << "Element [0]: " << duplicates[0] << '\n';

        duplicates[0] = 100;

        std::cout << "After changing [0]: "
                  << duplicates << "\n\n";

        std::cout << "10. REVERSE LIST\n";

        std::cout << "Before: " << duplicates << '\n';

        reverse_list(duplicates);

        std::cout << "After:  " << duplicates << "\n\n";

        std::cout << "11. RANDOM CONSTRUCTOR\n";

        LinkedList<int> random_list(5, 1, 100);

        std::cout << "Random list: "
                  << random_list << '\n';

        std::cout << "Size: "
                  << random_list.size() << "\n\n";

        std::cout << "12. ONE ELEMENT\n";

        LinkedList<int> one_element;

        one_element.push_tail(42);

        std::cout << "Before deletion: "
                  << one_element << '\n';

        one_element.pop_heads();

        std::cout << "After pop_heads: "
                  << one_element << '\n';

        std::cout << "Size: "
                  << one_element.size() << "\n\n";

        std::cout << "13. EXCEPTION TESTS\n";

        try
        {
            one_element.pop_heads();
        }
        catch (const std::out_of_range &error)
        {
            std::cout << "Empty list pop_heads: "
                      << error.what() << '\n';
        }

        try
        {
            one_element.pop_tails();
        }
        catch (const std::out_of_range &error)
        {
            std::cout << "Empty list pop_tails: "
                      << error.what() << '\n';
        }

        try
        {
            std::cout << one_element[0] << '\n';
        }
        catch (const std::out_of_range &error)
        {
            std::cout << "Invalid index: "
                      << error.what() << '\n';
        }

        try
        {
            duplicates.delete_node(999);
        }
        catch (const std::out_of_range &error)
        {
            std::cout << "Missing element: "
                      << error.what() << '\n';
        }

        std::cout << "\nALL TESTS COMPLETED\n";
    }
    catch (const std::exception &error)
    {
        std::cout << "Unexpected error: "
                  << error.what() << '\n';

        return 1;
    }

    return 0;
}