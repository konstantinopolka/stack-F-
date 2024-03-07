#pragma once
#pragma once
template <typename T>
class my_stack {
public:
    my_stack();
    explicit my_stack(int n); // OK
    my_stack(int n, const T& value); // OK
    my_stack(const my_stack<T>& list); // OK
    my_stack<T>& operator=(my_stack<T> other); // OK

    bool operator==(my_stack<T> const& other) const; // OK
    bool operator!=(my_stack<T> const& other) const; // OK

  
    int size() const; // OK
    bool empty() const; // OK

    T& top() const; // OK
    void push(const T& value); // OK
    void pop(); // OK
   
    void clear(); // OK

    static void swap(my_stack<T>& list1, my_stack<T>& list2) // OK
    {
        using std::swap;
        swap(list1.size_, list2.size_);
        swap(list1.head, list2.head);
        swap(list1.tail, list2.tail);
    }

    template <typename T>
    class node {
    public:

        T value;
        node* previous;
        node* next;
        node() : value(T()), previous(nullptr), next(nullptr) {}
        node(T value, node* previous) : value(value), previous(previous), next(nullptr) {}
        node(T value, node* previous, node* next) : value(value), previous(previous), next(next) {}
        node(T value) : value(value), previous(nullptr), next(nullptr) {}
    };


    //1.	Напишіть метод, який буде шукати елемент із заданим ключем у однозв'язному списку.

    int find_value(T value); // OK


private:
    node<T>* head;
    node<T>* tail;
    int size_;
    node<T>* find_node(const int index) const; // OK
};





