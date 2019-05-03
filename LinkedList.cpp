#include "LinkedList.h"

LinkedList::LinkedList()
{
    size = 0;
    first = NULL;
    last = NULL;
}

LinkedList::~LinkedList()
{
    //dtor
}

void LinkedList::display ()
{
    Link* temp = first;
	while(temp != NULL)
	{
		cout << temp->contents << " ";
		temp=temp->next;
	}
}

void LinkedList::add(Link* newLink, Link* destination) //Adds the new Link after destination
{
    size++;

    if(first == NULL)
    {
        newLink->next = NULL;
        newLink->previous = NULL;

        first = newLink;
        last = newLink;
    }
    else if(destination == last)
    {
        newLink->next = NULL;
        newLink->previous = destination;

        destination->next = newLink;

        last = newLink;
    }
    else
    {
        newLink->next = destination->next;
        newLink->previous = destination;

        destination->next->previous = newLink;
        destination->next = newLink;
    }
}

void LinkedList::add(int newContent, Link* destination)
{

    Link* l = new Link;
    l->contents = newContent;

    add(l, destination);
}

void LinkedList::remove(Link* link)
{
    if(first == NULL) //Chain is empty
        return;
    if (link == NULL)
        return;

    size--;

    if(first == link and last == link) //If the link the the only one in the chain
    {
        first = NULL;
        last = NULL;
    }
    else if(first == link) //link is the first in the chain
    {
        link->next->previous = NULL;
        first = link->next;
    }
    else if(last == link) //link is the last in the chain
    {
        link->previous->next = NULL;
        last = link->previous;
    }
    else
    {
        link->previous->next = link->next;
        link->next->previous = link->previous;
    }

    link->next = NULL;
    link->previous = NULL;

    delete(link);

    return;
}

bool LinkedList::isEmpty()
{
    return (size < 1);
}

int LinkedList::getSize ()
{
    return size;
}

Link* LinkedList::getFirst ()
{
    return first;
}

Link* LinkedList::getLast ()
{
    return last;
}

Link* LinkedList::getLinkAt(int _location)
{
	Link* temp = first;

	if (temp == NULL) // Empty list
		return NULL;

	for(int i = 0; i < _location; i++)
	{
		if(temp == last) // Reached end of list.
			return NULL;

		temp = temp->next;
	}

	return temp; // Found link
}

void LinkedList::mergeSort(int low, int high)
{
	if(low < high)
	{
		int mid = (low + high) / 2;

		mergeSort(low, mid);
		mergeSort(mid + 1, high);

		merge(low, high, mid);
	}

	return;
}

void LinkedList::merge(int low, int high, int mid)
{
	int i = 0;
	int j = 0;
	int k = low;

	int n1 = mid - low + 1;
	int n2 = high - mid;

	LinkedList left, right;

	for(i = 0; i < n1; i++)
    {
        left.add(getLinkAt(low + i)->contents, left.getLast());
    }

    for(j = 0; j < n2; j++)
    {
        right.add(getLinkAt(mid + 1 + j)->contents, right.getLast());
    }

	i = 0;
	j = 0;


    while(i < n1 and j < n2)
    {
        if(left.getLinkAt(i)->contents <= right.getLinkAt(j)->contents)
        {
            add(left.getLinkAt(i)->contents, getLinkAt(k));
			remove(getLinkAt(k));
            i++;
        }

        else
        {
            add(right.getLinkAt(j)->contents, getLinkAt(k));
			remove(getLinkAt(k));
            j++;
        }

        k++;
    }

    while (i < n1)
    {
        add(left.getLinkAt(i)->contents, getLinkAt(k));
		remove(getLinkAt(k));
        i++;
        k++;
    }

    while (j < n2)
    {
        add(right.getLinkAt(j)->contents, getLinkAt(k));
		remove(getLinkAt(k));
        j++;
        k++;
    }

	return;
}

