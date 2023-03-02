#include <iostream>

template <typename T>
struct Node {
    private:
        T value{};
        Node<T>* next{nullptr};

    public:
        Node(T value): value(value) {}

        T getValue() {
            return value;
        }
        Node<T>* getNext() {
            return next;
        }
        void setNext(Node<T>* node) {
            next = node;
        }
};

template <typename T>
class Stack {
    Node<T>* head{};
    size_t size {0};
    
    void insertNode(T value) {
        Node<T>* newNode = createNode(value);
        if(head == nullptr) {
            head = newNode;
        }
        else {
            newNode->setNext(head);
        }   
    }
    Node<T>* createNode(T value) {
        return new Node(value);
    }
    public:
        Stack(): head(nullptr) {}

        Stack(T value) {
            insertNode(value);
        }


        Node<T>* peek() {
            return head;
        }
        Node<T>* pop() {
            Node<T>* temp = head;
            head = head->getNext();
            return temp;
        }
        void push(T value) {
            Node<T>* newNode = createNode(value);
            newNode->setNext(head);
        }
};

int main() {
    Stack<int> stack{15};
    stack.push(12);
    stack.push(50);

    std::cout << stack.pop()->getValue() << std::endl; 
    std::cout << stack.pop()->getValue() << std::endl; 
    std::cout << stack.pop()->getValue() << std::endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}
