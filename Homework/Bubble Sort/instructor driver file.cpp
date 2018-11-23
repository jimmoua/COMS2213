
#include "sortBS.h"
#include "UList.h"
#include "sortBS.h"
#include "UList.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
   UList<int> list;

   if (list.empty()) {
     while (list.size()<10) {
       int item=rand()%500;
       if (!list.find(item))
         list.insert(item);
     }
   }
   if (!list.empty()) {
     cout<<list.size()<<endl<<list<<endl;
     sort(list);
     cout<<list.size()<<endl<<list<<endl;
     list.erase(383);
     cout<<list.size()<<endl<<list<<endl;
     sort(list);
     cout<<list.size()<<endl<<list<<endl;
   }
   return 0;
}
