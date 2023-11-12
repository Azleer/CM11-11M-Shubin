#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
#include <stdint.h>



template<typename TYPE>
class MyList
{
private:
    struct Node
    {
        TYPE* data = nullptr;
        Node* next = nullptr;
        Node* prev = nullptr;
    };

    Node* newNode(const TYPE &value);
    void deleteNode(Node* element);
    void swap(Node* lhs_ptr,  Node* rhs_ptr);
    Node* getNode(size_t index);

    void smerge(Node* lhsH, Node* rhsH);
    bool compare(Node* lhs, Node* rhs);

    Node* Tail;
    Node* Head;
    size_t countOfNods = 0;
public:
    MyList();
    void insert(const TYPE &value, size_t index);
    void push_front(const TYPE &obj);
    void push_back(const TYPE &obj);
    void erease(size_t index);
    void swap(size_t lhs, size_t rhs);
    void sort();
    void print(); // optional, debug
};










template<typename TYPE>
typename MyList<TYPE>::Node *MyList<TYPE>::newNode(const TYPE &value)
{
    return new Node{new TYPE{value}};
}

template<typename TYPE>
void MyList<TYPE>::deleteNode(Node *element)
{
    delete element->data;
    element->next = nullptr;
    element->prev = nullptr;
    delete element;
}

template<typename TYPE>
void MyList<TYPE>::swap(Node *lhs_ptr, Node *rhs_ptr)
{
    TYPE* temp = lhs_ptr->data;
    lhs_ptr->data = rhs_ptr->data;
    rhs_ptr->data = temp;
}

template<typename TYPE>
typename MyList<TYPE>::Node* MyList<TYPE>::getNode(size_t index)
{
    if(index > countOfNods || index <= 0)
    {
        std::cout << "Out of range " <<std::endl;
        return nullptr;
    }

    Node* it;
    if(index <= countOfNods/2)
    {
        // Идет к эл. с начала списка
        it = Head;
        for (size_t to = 1; to < index; ++to) { //too-to..
            it = it->next;
        }
    }
    else
    {
        //Идем с конца списка;
        it = Tail;
        for (size_t to = countOfNods; to > index; --to) {
            it = it->prev;
        }
    }

    return it;
}

template<typename TYPE>
bool MyList<TYPE>::compare(Node *lhs, Node *rhs)
{
    return lhs->data < lhs->data;
}

template<typename TYPE>
MyList<TYPE>::MyList()
{
    Tail = nullptr;
    Head = nullptr;
    countOfNods = 0;
}

template<typename TYPE>
void MyList<TYPE>::insert(const TYPE &value, size_t index)
{
    if(index > countOfNods || index < 0)
    {
        std::cout << "MyList--insert: Out of range" <<std::endl;
        return;
    }

    Node* node = newNode(value);

    if (Head == nullptr)
    {
        Head = node;
        Tail = node;
        this->countOfNods++;
        return;
    }

    if (index == 1 && index != countOfNods)
    {
        // push_front
        node->prev = nullptr;
        node->next = Head;
        Head->prev = node;
        Head = node;
        ++countOfNods;
        return;
    }

    if (index == countOfNods)
    {
        //Push_back;
        Tail->next = node;
        node->prev = Tail;
        node->next = nullptr;
        Tail = node;
        this->countOfNods++;
        return;
    }

    //Insert
    Node* it = this->getNode(index);
    this->countOfNods++;
    Node* prevnode = it->prev;
    node->next = it;
    node->prev = prevnode;
    it->prev = node;
    prevnode->next = node;
}

template<typename TYPE>
void MyList<TYPE>::push_front(const TYPE &obj)
{
    this->insert(obj, 1);
}

template<typename TYPE>
void MyList<TYPE>::push_back(const TYPE &obj)
{
    this->insert(obj, this->countOfNods);
}

template<typename TYPE>
void MyList<TYPE>::erease(size_t index)
{
    Node* it = this->getNode(index);
    if (it == nullptr) {
        return;
    }

    if (index == 1)
    {
        Head = it->next;
        Head->prev = nullptr;
        this->deleteNode(it);
        --countOfNods;
        return;
    }

    if (index == countOfNods)
    {
        Tail = it->prev;
        Tail->next = nullptr;
        it->next = nullptr;
        it->prev = nullptr;
        this->deleteNode(it);
        --countOfNods;
        return;
    }
    else
    {
        it->prev->next = it->next;
        it->next->prev = it->prev;

        it->next = nullptr;
        it->prev = nullptr;
        this->deleteNode(it);
        --countOfNods;
    }
}

template<typename TYPE>
void MyList<TYPE>::swap(size_t lhs, size_t rhs)
{
    Node* lhs_ptr = this->getNode(lhs);
    Node* rhs_ptr = this->getNode(rhs);

    TYPE* temp = lhs_ptr->data;
    lhs_ptr->data = rhs_ptr->data;
    rhs_ptr->data = temp;
}

template<typename TYPE>
void MyList<TYPE>::sort()
{
    // слияние + вставка



    MyList temp;

    Head = temp.Head;
    Tail = temp.Tail;

}

template<typename TYPE>
void MyList<TYPE>::print()
{
    Node* it = Head;
    std::cout << "Head->Tail" << std::endl;
    std::cout << "[";
    while (it != nullptr)
    {
        std::cout << *it->data << ", ";
        it = it->next;
    }
    std::cout << "]" << std::endl;

    it = Tail;
    std::cout << "Tail->Head" << std::endl;
    std::cout << "[";
    while (it != nullptr) {
        std::cout << *it->data << ", ";
        it = it->prev;
    }
    std::cout << "]" << std::endl;
}

#endif // MYLIST_H
