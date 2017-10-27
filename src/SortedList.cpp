#include <iostream>
#include <iterator>
#include "SortedList.h"

using namespace std;

SortedList::SortedList()
{
    Node::reset();
}

SortedList::~SortedList()
{
    Node::reset();
}

int SortedList::size() const { return data.size(); }

bool SortedList::check()
{
    if (data.size() == 0) return true;

    list<Node>::iterator it = data.begin();
    list<Node>::iterator prev = it;

    it++;

    // Ensure that each node is greater than the previous node.
    while ((it != data.end()) && (*it > *prev))
    {
        prev = it;
        it++;
    }

    return it == data.end();  // Good if reached the end.
}

void SortedList::prepend(const long value)
{
 data.insert(data.begin(),Node(value));
}

void SortedList::append(const long value)
{
 data.push_back(Node(value));
}

void SortedList::remove(const int index)
{
	list<Node>::iterator it = data.begin();
	if(data.size()>index)
		std::advance(it,index);
  data.erase(it);
}

//HOW TO DO???!
void SortedList::insert(const long value)
{
 
	int i=0;
		Node n(value);
		list<Node>::const_iterator it = data.begin();
		while(i<data.size())
		{
			if(*it>n)
				{
					data.insert(it,n);
					return;
				}
			std::advance(it,1);
			i++;
		}
}

Node SortedList::at(const int index)
{
	list<Node>::iterator it = data.begin();
	std::advance(it,index);
   return *it;
   
}
