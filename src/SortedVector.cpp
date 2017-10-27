#include <iostream>
#include <iterator>
#include "SortedVector.h"

using namespace std;

SortedVector::SortedVector()
{
    Node::reset();
}

SortedVector::~SortedVector()
{
    Node::reset();
}

int SortedVector::size() const { return data.size(); }

bool SortedVector::check() const
{
    if (data.size() == 0) return true;

    vector<Node>::const_iterator it = data.begin();
    vector<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is greater than the previous node.
    while ((it != data.end()) && (*it > *prev))
    {
        prev = it;
        it++;
    }

    return it == data.end();  // Good if reached the end.
}

void SortedVector::reserve(const int size)
{
	data.reserve(size);
}

void SortedVector::prepend(const long value)
{
 data.insert(data.begin(),Node(value));
}

void SortedVector::append(const long value)
{
	data.push_back(Node(value));
}

void SortedVector::remove(const int index)
{
  data.erase(data.begin() + index);
}

void SortedVector::insert(const long value)
{

	int i=0;
	Node n(value);
	vector<Node>::const_iterator it = data.begin();
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
	//data.insert(lower_bound(data.begin(), data.end(), Node(value)),Node(value));
}

Node SortedVector::at(const int index) const
{
    return data.at(index);
}
