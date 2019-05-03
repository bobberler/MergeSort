#include <iostream>
#include <random>
#include "LinkedList.h"

using namespace std;



int main()
{
    bool exit = false;
    while (!exit)
    {
        int numOf = 0;
        LinkedList l;
        char in;
        cout<<"Enter the number of numbers to be sorted: ";
        cin>>numOf;
        for(int i = 0; i < numOf; i++)
        {
            l.add(rand() % 100 + 1, l.getLast());
        }
        cout << "Initialized list\n";
        l.display();
        l.mergeSort(0, l.getSize()-1);
        cout<<"\nSorted numbers: \n";
        l.display();
        cout << "\nDo you want to continue (y/n)\n";
        cin >> in;
        if(in == 'n')
            exit = true;
        system("CLS");
    }

	return 0;
}



