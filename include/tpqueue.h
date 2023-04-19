// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <iostream>
#include <string>
template<typename T>
class TPQueue {// реализация шаблона очереди с приоритетом на связанном списке
 private:
    struct ITEM {
        T data;
        ITEM* next;
        ITEM* prev;
    };
    TPQueue::ITEM* create(const T& data) {
        ITEM* item=new ITEM;
        item->data=data;
        item->next = nullptr;
        item->prev = nullptr;
        return item;
    }
    ITEM* head;
    ITEM* tail;

 public:
    T pop() {
        if (head) {
            ITEM* a = head->next;
            if (a)
                a->prev = nullptr;
            T data = head->data;
            delete head;
            head = a;
            return data;
        } else {
            throw std::string("It is empty");
        }
    }
    void push(const T& data) {
        ITEM* a = head;
        ITEM* item=create(data);
        while (a && a->data.prior >= data.prior)
            a = a->next;
        if (!a && head) { // вставка в конец
            tail->next = item;
            tail->next->prev = tail;
            tail = item;
        } else if (!a && !head) {// вставка элемента в пустой список
            head = tail = item;
        } else if (!a->prev) { // вст эл  в начало
            a->prev = item;
            item->next = a;
            head = item;
        } else { // вст эл в середину
            a->prev->next = item;
            item->prev = a->prev;
            item->next = a;
            a->prev = item;     
        }
    }
};

struct SYM {
  char ch;      
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
