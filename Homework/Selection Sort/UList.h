#ifndef ULIST_H
#define ULIST_H
#include <cstddef>
#include <vector>
#include <ostream>

template<class T>
class UList
{
  public:
    UList(size_t = 10);
    void insert(const T&);
    bool erase(const T&);
    bool find(const T&) const;
    size_t size() const;
    bool empty() const;
    template<class U>
        friend std::ostream& operator<<(std::ostream&, const UList<U>&);
    template<class U>
        void friend sort(UList<U>&);
  protected:
    std::vector<T> items;
};

template<class T>
UList<T>::UList(size_t n)
{
  items.reserve(n);
}

template<class T>
void UList<T>::insert(const T& valueToInsert)
{
  items.push_back(valueToInsert);
}

template<class T>
bool UList<T>::erase(const T& itemToErase)
{
  bool itemErasedFromListSuccessfully = false;
  for(auto iter = items.begin(); iter != items.end(); iter++)
  {
    if(*iter == itemToErase)
    {
      items.erase(iter);
      itemErasedFromListSuccessfully = true;
      break;
    }
  }
  return itemErasedFromListSuccessfully;
}

template<class T>
bool UList<T>::find(const T& itemToFind) const
{
  bool itemFound = false;
  for(auto iter = items.begin(); iter != items.end(); iter++)
  {
    if(*iter == itemToFind)
    {
      items.erase(iter);
      itemFound = true;
      break;
    }
  }
  return itemFound;
}

template<class T>
size_t UList<T>::size() const
{
  return items.size();
}

template<class T>
std::ostream& operator<<(std::ostream& os, const UList<T>& obj)
{
  if(!obj.items.empty())
  {
    os << *obj.items.begin();
    for(auto iter = obj.items.begin()+1; iter != obj.items.end(); iter++)
    {
      os << ", " << *iter;
    }
  }
  else
    os << "Empty.";
  return os;
}

#endif
