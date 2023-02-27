#include <iostream>

template <typename T>

struct Node {
    T value{};
    Node<T>* next{};

    Node(T value): value(value) {}
};

template <typename T>
class LinkedList {
public:
    Node<T>* head{};
    Node<T>* tail{};

    LinkedList(): head(nullptr), tail(nullptr) {}
    LinkedList(T value) {
        insertNode(value);
    }

    void insertNode(T value) {
        Node<int>* newNode = new Node{value};

        if(head == nullptr) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
    }

    void print() {
        Node<T>* traverser = head;

        while(traverser != nullptr) {
            std::cout << traverser->value << std::endl;
            traverser = traverser->next;
        }
    }
};

template <typename T>
bool searchList(const LinkedList<T> list, T target) {
    Node<T>* head = list.head;
    while(head != nullptr) {
        if(head->value == target) return true;
        head = head->next;
    }
    return false;
}
int main() {
    LinkedList<int> myList{15};
    myList.insertNode(20);
	myList.insertNode(25);
    myList.insertNode(40);
    myList.insertNode(45);
    myList.insertNode(50);
    std::cout << std::boolalpha;
    int number{};
    std::cout << "Enter a number to search: ";
    std::cin >> number;
    std::cout << searchList(myList, number) << std::endl;
    return 0;
}
