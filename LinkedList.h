#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

class Link
{
    public:
        int contents;
        Link* next;
        Link* previous;
};

class LinkedList
{
    public:
        LinkedList();
        virtual ~LinkedList();
        void display();
        int getSize ();
        Link* getFirst();
        Link* getLast();
        void add(Link* newLink, Link* destination);
        void add(int newContent, Link* destination);
        void remove(Link* link);
        bool isEmpty();
        Link* getLinkAt(int _location);
        void mergeSort(int, int);
        void merge(int, int, int);

    protected:

    private:
        int size;
        Link* first;
        Link* last;
};

#endif // LINKEDLIST_H
