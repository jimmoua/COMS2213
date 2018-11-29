#include <cstdlib>
#include <time.h>
#include <string>
#include <iostream>

#include "UList.h"
#include "sortIS.h"

int main()
{
  UList<int> object;
  srand(time(NULL));
  for(int i = 0; i < 10; i++)
  {
    object.insert(rand()%500-250);
  }

  sort(object);
  std::cout << "The list has " << object.size() << " items: ";
  std::cout << object << std::endl;

  std::string message("");
  for(int i = 0; i < 3; i++)
  {
    int removeItem;
    std::cout << "Remove: ";
    std::cin >> removeItem;
    message.append(std::to_string(removeItem));
    if(object.erase(removeItem))
      message.append(" was removed.\n");
    else
      message.append(" was not removed.\n");
  }
  std::cout << message;
  std::cout << "The list has " << object.size() << " items: ";
  std::cout << std::endl << object << std::endl;

  message.clear();
  for(int i = 0; i < 3; i++)
  {
    int findItem;
    std::cout << "Find: ";
    std::cin >> findItem;
    message.append(std::to_string(findItem));
    if(object.erase(findItem))
      message.append(" was found.\n");
    else
      message.append(" was not found.\n");
  }
  std::cout << message;
  return EXIT_SUCCESS;
}
