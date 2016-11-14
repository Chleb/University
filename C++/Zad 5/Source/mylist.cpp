// [Kurs C++] Zadanie 5
//
// Implementacja klasy List2Way wraz z krótkim
//            programem testowym.
//
// Autor: Tomasz Musiała

#include "mylist.hpp"

const int MyList::MyNode::capacity = 100;
Tab_bit MyList::MyNode::check(capacity);
MyList::MyNode *MyList::MyNode::NodeTab =
    static_cast<MyList::MyNode*> (::operator new (sizeof(MyList::MyNode[capacity])));

MyList::MyNode::MyNode(MyNode *p, MyNode *n, double val): next(n),
                                                          prev(p),
                                                          value(val)
{}

MyList::MyNode::~MyNode()
{
    next = nullptr;
    prev = nullptr;
    value = 0;
}

void *MyList::MyNode::operator new(size_t)
{
   int i = 0;
   while((i < capacity) && (check[i] != 0)) i++;
   if(i == capacity) throw std::string("Not enough memory!");
   check[i] = 1;
   NodeTab[i].index = i;
   return &NodeTab[i];
}

void MyList::MyNode::operator delete(void *ptr)
{
   check[((MyList::MyNode *)ptr)->index] = 0;
}

double MyList::MyNode::getValue() const
{
    return value;
}

MyList::MyNode *MyList::MyNode::addNext(double val)
{
    MyNode *n = new MyNode(nullptr, nullptr, val);

    if(next != nullptr)
    {
        next->prev = n;
        n->next = next;
    }

    n->prev = this;
    next = n;

    return n;
}

MyList::MyNode *MyList::MyNode::addNext(int i, double val)
{

    if(i == 0)
    {
        return addNext(val);
    }
    if(next == nullptr) throw std::string ("List is to short!");
    return next->addNext(i - 1, val);
}

MyList::MyNode *MyList::MyNode::addPrev(int i, double val)
{

    if(i == 0)
    {
        return addPrev(val);
    }
    if(prev == nullptr) throw std::string ("List is to short!");
    return prev->addPrev(i - 1, val);
}

MyList::MyNode *MyList::MyNode::addPrev(double val)
{
    MyNode *n = new MyNode(nullptr, nullptr, val);
    if(prev != nullptr)
    {
        prev->next = n;
        n->prev = prev;
    }

    n->next = this;
    prev = n;
    return n;
}

MyList::MyNode *MyList::MyNode::del()
{

    MyNode *res = nullptr;
    if(prev != nullptr && next != nullptr)
    {
        next->prev = prev;
        prev->next = next;
        res = next;
    }

    if(prev == nullptr && next != nullptr)
    {
        next->prev = nullptr;
        res = next;
    }
    else if(next == nullptr && prev != nullptr)
    {
        prev->next = nullptr;
        res = prev;
    }

    delete(this);

    return res;
}

MyList::MyNode *MyList::MyNode::delNext(int i)
{
    if(i == 0) return del();
    return next->delNext(i - 1);
}

void MyList::MyNode::write()
{
    MyNode *p = this;
    do
    {
        std::cout << p->getValue() <<", ";
        p = p->next;
    }
    while(p != nullptr);
    std::cout << "\n";
}

MyList::MyList(): length(0),
          begin(nullptr),
          end(nullptr)
{}

MyList::MyList(MyList const &that): length(0),
                                    begin(nullptr),
                                    end(nullptr)
{
    for(int i = 0; i < that.length; i++)
    {
        insert(i, that[i]);
    }
    length = that.length;

}

MyList::MyList(MyList &&that): length(that.length),
                                    begin(that.begin),
                                    end(that.end)
{
    that.begin = nullptr;
    that.end = nullptr;
    length = 0;
}


MyList::MyList(std::initializer_list<double> l): length(l.size())
{
    int i = 0;
    begin = new MyNode(nullptr, nullptr, *l.begin());
    end = begin;

    for(auto iter = l.begin() + 1; iter != l.end(); iter++, i++)
    {
        end = begin->addNext(i, *iter);
    }
}

MyList::~MyList()
{
    for(int i = 0; i < length; i++) delete(end);
    length = 0;
}

void MyList::insert(int i, const double val)
{
    if(length != 0)
    {
        MyNode *p;
        if(i == 0) begin = begin->addPrev(val);
        else p = begin->addNext(i - 1, val);
        if(i == length) end = p;
        length++;
    }
    else
    {
        begin = new MyNode(nullptr, nullptr, val);
        end = begin;
        length = 1;
    }
}
int MyList::getLength() const
{
    return length;
}


void MyList::del(int i)
{
    if(length == 0) throw std::string("Can not delete element from an empty list!");
    if(i >= length) throw std::string("Index out of range!");
    if(i == 0) begin = begin->del();
    else if(i == length - 1) end = end->del();
    else begin->delNext(i);
    length--;
}

void MyList::write() const
{
    if(length == 0)
    {
        std::cout << "Empty list!\n";
        return;
    }
    begin->write();
    std::cout << "Lenght = " << getLength() << "\n";
}

double MyList::getBegin() const
{
    return begin->getValue();
}

double MyList::getEnd() const
{
    return end->getValue();
}

MyList::MyNode &MyList::MyNode::getNext(int i)
{
    MyNode *p = this;
    for(int j = 0; j < i; j++) p = p->next;
    return *p;
}

MyList::MyNode &MyList::operator[](int i)
{
    return begin->getNext(i);
}
double MyList::operator[](int i) const
{
    return (begin->getNext(i)).getValue();
}

MyList &MyList::operator = (const MyList &other)
{
//std::cout <<"kopiujący\n";
    int i = 0;
    if(this == &other) return *this;
    if(this->length > other.length)
    {
        for(i = 0; i < other.length; i++) (*this)[i] = other[i];
        while(i < this->length)
        {
            this->del(i);
            i++;
        }
    }
    else
    {
        for(i = 0; i < this->length; i++) (*this)[i] = other[i];
        while(i < other.length)
        {
            this->insert(i, other[i]);
            i++;
        }
    }
    return *this;

}

MyList &MyList::operator = (MyList &&other)
{
//std::cout << "przenoszący\n";
    int i = 0;
    if(this == &other) return *this;
    for(i = 0; i < length; i++) del(i);
    length = other.length;
    begin = other.begin;
    end = other.end;
    return *this;
}

MyList::MyNode &MyList::MyNode::operator = (const MyList::MyNode &other)
{
    value = other.value;
    return *this;
}

MyList::MyNode &MyList::MyNode::operator = (const int val)
{
    value = val;
    return *this;
}



