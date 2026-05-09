// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
  // реализация шаблона очереди с приоритетом на связанном списке
 private:
    struct Node {
        T data;
        Node* next;
        explicit Node(const T& value) : data(value), next(nullptr) {}
    };
    Node* head;

  public:
    TPQueue() : head(nullptr) {}
    ~TPQueue() {
        clear();
    }
    void push(const T& value) {
        Node* newNode = new Node(value);
        if (head == nullptr || value.prior > head->data.prior) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr && 
          current->next->data.prior >= value.prior) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    T pop() {
        if (head == nullptr) {
            return T();
        }
        Node* temp = head;
        T value = head->data;
        head = head->next;
        delete temp;
        return value;
    }
    bool empty() const {
        return head == nullptr;
    }
    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
