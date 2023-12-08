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

    Node* Tail;
    Node* Head;
    size_t countOfNods = 0;

    Node* newNode(const TYPE &value);
    void deleteNode(Node* element);
    //Node* getNode(size_t index);

    void swap(Node* lhs_ptr,  Node* rhs_ptr);







public:
    MyList();
    void insert(const TYPE &value, size_t index);
    void push_front(const TYPE &obj);
    void push_back(const TYPE &obj);
    void erease(size_t index);
    void swap(size_t lhs, size_t rhs);
    void sort();
    void bublesort();
    void print(); // optional, debug

    void move(Node* prevnode, Node* node);

    Node* getNode(size_t index);
    Node* Max();
    MyList* pastesort();
    void smerge(MyList* list);
    bool compare(Node* lhs, Node* rhs);
    void insert(Node* it, Node* node);
    Node* cut(Node* it);
    MyList split(size_t it);
    MyList& operator=(const MyList& right);

    bool is_sort();
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
MyList<TYPE> &MyList<TYPE>::operator=(const MyList &right)
{
    this->Head = right.Head;
    this->Tail = right.Tail;
    this->countOfNods = right.countOfNods;
    return *this;
}

template<typename TYPE>
bool MyList<TYPE>::is_sort()
{
    bool is_sort = true;
    Node* lhs = Head;
    Node* rhs = Head->next;
    while (rhs != nullptr)
    {

        is_sort *= this->compare(lhs,rhs);
        lhs = lhs->next;
        rhs = rhs->next;
    }
    return is_sort;
}

template<typename TYPE>
void MyList<TYPE>::smerge(MyList *list)
{
    Node* it_this = Head;
    while (list->Head != nullptr) {

        if (it_this == nullptr) {
            this->insert(Tail, list->cut(list->Head));
            continue;
        }

        if (!this->compare(it_this, list->Head))
        {
            this->insert(it_this, list->cut(list->Head));
        }
        else
        {
            it_this = it_this->next;
        }

    }
}

template<typename TYPE>
 MyList<TYPE>* MyList<TYPE>::pastesort()
{
    MyList temp;


    temp = this->split(this->countOfNods/2 + 1);

    if (this->countOfNods <= 1 && temp.countOfNods <= 1) {
        this->smerge(&temp);
        return this;
    } else {
        temp.pastesort();
        this->pastesort();
        this->smerge(&temp);
        return this;
    }





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
bool MyList<TYPE>::compare(Node* lhs, Node* rhs)
{
    return *lhs->data <= *rhs->data;
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
void MyList<TYPE>::insert(Node* it, Node* node)
{
    if (it == node) {return;}

    if (Head == nullptr)
    {
        Head = node;
        Tail = node;
        this->countOfNods++;
        return;
    }

    if (it == Head && it != Tail)
    {
        // push_front
        node->prev = nullptr;
        node->next = Head;
        Head->prev = node;
        Head = node;
        ++countOfNods;
        return;
    }

    if (it == Tail)
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
    this->countOfNods++;
    Node* prevnode = it->prev;
    node->next = it;
    node->prev = prevnode;
    it->prev = node;
    prevnode->next = node;
}

template<typename TYPE>
typename MyList<TYPE>::Node *MyList<TYPE>::cut(Node *it)
{
    if (it == nullptr) {
        return it;
    }

    if (it->next == nullptr && it->prev == nullptr && countOfNods != 1) {
        return it;
    }

    if (countOfNods == 1 && it == Tail)
    {
       Tail->next = nullptr;
       Tail->prev = nullptr;
       Tail = nullptr;
       Head = nullptr;
       --countOfNods;
        return it;
    }

    if (Head == it)
    {
        Head = it->next;
        Head->prev = nullptr;
        it->next = nullptr;
        it->prev = nullptr;
        --countOfNods;
        return it;
    }

    if (Tail == it)
    {
        Tail = it->prev;
        Tail->next = nullptr;
        it->next = nullptr;
        it->prev = nullptr;
        --countOfNods;
        return it;
    }
    else
    {
        it->prev->next = it->next;
        it->next->prev = it->prev;

        it->next = nullptr;
        it->prev = nullptr;
        --countOfNods;
        return it;
    }
    return it;
}

template<typename TYPE>
MyList<TYPE> MyList<TYPE>::split(size_t index)
{
    if (countOfNods <= 1) return *this;

    MyList temp;
    Node* newhead = this->getNode(index);

    temp.Head =  newhead;
    temp.Tail = Tail;

    this->Tail = newhead->prev;
    Tail->next = nullptr;
    newhead->prev = nullptr;

    temp.countOfNods = this->countOfNods - index + 1;
    this->countOfNods = index - 1;

    return temp;
}

template<typename TYPE>
typename MyList<TYPE>::Node* MyList<TYPE>::Max()
{
    Node* it = Head->next;
    Node* Max = Head;
    while (it != nullptr) {
        if (!this->compare(it, Max)) {
            Max = it;
        }
        it = it->next;
    }
    return Max;
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



    if (this->countOfNods % 2 == 0)
    {
        this->pastesort();
    } else {
        MyList temp;
        auto it = this->cut(Tail);
        temp.insert(temp.Head, it);
        this->pastesort();
        this->smerge(&temp);
    }






}

template<typename TYPE>
void MyList<TYPE>::bublesort()
{
    Node* lhs = Head;
    Node* rhs = Head->next;
   while (!this->is_sort())
   {
       if (rhs == nullptr) {
           lhs = Head;
           rhs = Head->next;
       }

    if (!this->compare(lhs,rhs)) {
        this->swap(lhs, rhs);
    }

    lhs = lhs->next;
    rhs = rhs->next;
   }


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

template<typename TYPE>
void MyList<TYPE>::move(Node *prevnode, Node *node)
{
    this->cut(node);
    this->insert(prevnode->next, node);
}



#endif // MYLIST_H
