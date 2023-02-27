#include <iostream>
#include <stack>
template <typename T>
struct Node {
    private:
        T value{};
        Node<T>* left{nullptr},* right{nullptr};

    public:
        Node(T value): value(value) {}

        void setLeft(Node<T>* newNode) {
            left = newNode;
        }
        void setRight(Node<T>* newNode) {
            right = newNode;
        }
        Node<T>* getLeft() {
            return left;
        }
        Node<T>* getRight() {
            return right;
        }
        T getValue() {
            return value;
        }
};

template <typename T>
class BinaryTree {
    private:
        Node<T>* root{};

    public:
        BinaryTree(): root(nullptr) {}
        BinaryTree(T value) {
            insertRoot(value);
        }

        void insertRoot(T value) {
            root = createNode(value);
        }
        Node<T>* createNode(T value) {
            return new Node(value);
        }

        void add(T value) {
            if(root == nullptr) {
                insertRoot(value);
            }
            else {
                insertNode(root, createNode(value));
            }
        }

        void inOrder() {
            std::stack<Node<T>*> stack{};

            Node<T>* currentNode = root;

            while(currentNode != nullptr || !stack.empty()) {
                while(currentNode != nullptr) {
                    stack.push(currentNode);
                    currentNode = currentNode->getLeft();
                }

                currentNode = stack.top();
                stack.pop();
                std::cout << currentNode->getValue() << '\n';
                currentNode = currentNode->getRight();
            }
            std::cout << std::flush;
        }
    private:
        void insertNode(Node<T>* node, Node<T>* newNode) {
            if(newNode->getValue() < node->getValue()) {
                if(node->getLeft() == nullptr) {
                    node->setLeft(newNode);
                } else {
                    insertNode(node->getLeft(), newNode);
                }
            } else {
                if(node->getRight() == nullptr) {
                    node->setRight(newNode);
                } else {
                    insertNode(node->getRight(), newNode);
                }
            }
        }
};

int main() {
    BinaryTree<int> myTree{15};
    myTree.add(20);
    myTree.add(4);
    myTree.add(8);
    myTree.add(13);
    myTree.add(26);
    myTree.inOrder();
    return 0;
}
