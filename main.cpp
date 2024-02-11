#include <iostream>

template<typename Type>
class MyDeck {
private:
    struct Node {
        Type value;
        Node *next;
        Node *prev;

        Node(const Type val) : value(val), next(nullptr), prev(nullptr) {}
    };
    Node *begin;
    Node *end;
    size_t size;

public:
    MyDeck() : begin(nullptr), end(nullptr), size(0) {}
    ~MyDeck() {
        Node *curr = begin;
        while(curr != nullptr) {
            Node *next = curr->next;
            delete curr;
            curr = next;
        }
    }
    void push_back(const Type& value) {
        Node *newNode = new Node(value);
        if (begin == nullptr) {
            begin = newNode;
            end = newNode;
        }
        else {
            newNode->prev = end;
            end->next = newNode;
            end = newNode;
        }
        size++;
    }
    void pop_back() {
        if (size == 0)
            return;
        if (size == 1) {
            delete end;
            begin = nullptr;
            end = nullptr;
        }
        else {
            Node *prevNode = end->prev;
            prevNode->next = nullptr;
            delete end;
            end = prevNode;
        }
        size--;
    }
    void push_front(const Type& value) {
        Node *newNode = new Node(value);
        if (begin == nullptr) {
            begin = newNode;
            end = newNode;
        }
        else {
            newNode->next = begin;
            begin->prev = newNode;
            begin = newNode;
        }
        size++;
    }
    void pop_front() {
        if (size == 0)
            return;
        if (size == 1) {
            delete begin;
            begin = nullptr;
            end = nullptr;
        }
        else {
            Node *nextNode = begin->next;
            nextNode->prev = nullptr;
            delete begin;
            begin = nextNode;
        }
        size--;
    }
    size_t sized() const {
        return size;
    }
    friend std::ostream& operator<<(std::ostream& out, const MyDeck& deck) {
        Node *curr = deck.begin;

        out << "( ";
        while (curr != nullptr) {
            out << curr->value << " ";
            curr = curr->next;
        }
        out << ")";

        return out;
    }
};

int main() {
    MyDeck<float> deck;
    deck.push_front(0.5);
    deck.push_back(9.8);

    std::cout << deck << std::endl;

    deck.pop_back();

    std::cout << deck << std::endl;

    deck.push_back(9.8);
    deck.pop_front();

    std::cout << deck << std::endl;
}
