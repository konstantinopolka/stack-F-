#pragma once
#include "my_stack.h"

template <typename T>
my_stack<T>::my_stack() : head(nullptr), tail(nullptr), size_(0) {}

template <typename T>
void my_stack<T>::push(const T& value) {
    if (head == nullptr) {
        head = new node<T>(value);
        tail = head;
    }
    else {
        tail->next = new node<T>(value, tail);
        tail = tail->next;
    }
    size_++;
}


template <typename T>
my_stack<T>::my_stack(int n, const T& value) : my_stack()
{
    while (n--)
        push(value);
}


template <typename T>
my_stack<T>::my_stack(int n) : my_stack(n, T())
{ }

template <typename T>
my_stack<T>& my_stack<T>::operator=(my_stack<T> other) {
    swap(*this, other);
    return *this;
}
template <typename T>
my_stack<T>::my_stack(const my_stack<T>& other) : my_stack()
{
    if (!other.empty()) {
        node<T>* current = other.head;
        while (current != nullptr) {
            push(current->value);
            current = current->next;
        }
    }

}


template<typename T>
inline bool my_stack<T>::operator==(my_stack<T> const& other) const
{
    if (this->head == nullptr && other.head == nullptr)
        return true;
    if (this->head == nullptr || other.head == nullptr)
        return false;
    if (this->size_ != other.size_)
        return false;

    node<T>* current_this = this->head;
    node<T>* current_other = other.head;


    while (current_this != nullptr && current_other != nullptr) {
        if (current_this->value != current_other->value)
            return false;
        current_this = current_this->next;
        current_other = current_other->next;
    }
    return true;
}


template<typename T>
inline bool my_stack<T>::operator!=(my_stack<T> const& other) const
{
    return !(*this == other);
}

template<typename T>
inline void my_stack<T>::pop()
{
    // size > 0
    size_--;
    node<T>* temp = head;
    head = head->next;
    if (head != nullptr)
        head->previous = nullptr;
    delete temp;
    if (size_ == 0)
        tail = nullptr;
}
template <typename T>
void my_stack<T>::clear() {
    while (size_)
        pop();
}

template<typename T>
inline T& my_stack<T>::top() const
{
    // size > 0
    return tail->value;
}

template<typename T>
inline bool my_stack<T>::empty() const
{
    return !size_;
}


template<typename T>
inline int my_stack<T>::size() const
{
    return size_;
}

template<typename T>
typename my_stack<T>::node<T>* my_stack<T>::find_node(const int index) const {
    // index < size
    node<T>* found_position;
    int counter;
    if (index < size_ / 2) {
        found_position = head;
        counter = 0;
        while (counter != index) {
            counter++;
            found_position = found_position->next;
        }
    }
    else {
        found_position = tail;
        counter = size_ - 1;
        while (counter != index) {
            counter--;
            found_position = found_position->previous;
        }
    }

    return found_position;
}

template<typename T>
inline int my_stack<T>::find_value(T value) {
    if (!empty()) {
        node<T>* current = head;
        for (int i = 0; current != nullptr; i++) {
            if (current->value == value)
                return i;
            current = current->next;
        }
        return -1;
    }
}
