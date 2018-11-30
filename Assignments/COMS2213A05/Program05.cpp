/* ----------------------------------------------------------------------------
 * Jim Moua
 * Program #5
 * Due: 12/02/2018
 *
 * Description:
 * This program will insert items into a binary search tree. It can also erase,
 * print in an by traversing via inorder, postorder, or preorder, and other
 * binary search tree-related manipulations.
 *
 * Input:
 * The user does not have to input anything, since inserting is mostly done by
 * hardcoding.
 *
 * Output:
 * The output will output the binary search tree objects. There are three
 * different binary search tree objects. The output outputs to standard console
 * output the inorder, postorder, and preorder traversal of the tree. The other
 * outputs are the tree after manipulation is done to them.
 *
 * Special Processing Requirements:
 * Requires C++ 11.
 * --------------------------------------------------------------------------*/
#include "BSTType.h"

int ThatOneFunctionWhoseSolePurposeIsToReturnThisWonderful_Thing();

int main()
{
  BSTType<int> AbsurdlyLongObjectNameOfClass_BSTType_below80Chars;
  AbsurdlyLongObjectNameOfClass_BSTType_below80Chars.insert(11);
  AbsurdlyLongObjectNameOfClass_BSTType_below80Chars.insert(6);
  AbsurdlyLongObjectNameOfClass_BSTType_below80Chars.insert(4);
  AbsurdlyLongObjectNameOfClass_BSTType_below80Chars.insert(5);
  AbsurdlyLongObjectNameOfClass_BSTType_below80Chars.insert(8);
  AbsurdlyLongObjectNameOfClass_BSTType_below80Chars.insert(10);
  AbsurdlyLongObjectNameOfClass_BSTType_below80Chars.insert(19);
  AbsurdlyLongObjectNameOfClass_BSTType_below80Chars.insert(17);
  AbsurdlyLongObjectNameOfClass_BSTType_below80Chars.insert(43);
  AbsurdlyLongObjectNameOfClass_BSTType_below80Chars.insert(31);
  AbsurdlyLongObjectNameOfClass_BSTType_below80Chars.insert(49);

  // This is a copy via operator
  BSTType<int> AnotherRidiculouslyLongNameThatHoldsNoMeaning = 
    AbsurdlyLongObjectNameOfClass_BSTType_below80Chars;

  // This is another copy via copy constructor
  BSTType<int> TheTruePointlessNameThatTrulyHasNoMeaning_orDoesIt
    (AnotherRidiculouslyLongNameThatHoldsNoMeaning);

  std::cout << "Inorder:  ";
  AbsurdlyLongObjectNameOfClass_BSTType_below80Chars.traverse(std::cout, IN);
  std::cout << std::endl;

  std::cout << "Preorder:  ";
  AnotherRidiculouslyLongNameThatHoldsNoMeaning.traverse(std::cout, PRE);
  std::cout << std::endl;

  std::cout << "Postorder:  ";
  TheTruePointlessNameThatTrulyHasNoMeaning_orDoesIt.traverse(std::cout, POST);
  std::cout << std::endl;

  // Remove things from first copy
  AnotherRidiculouslyLongNameThatHoldsNoMeaning.erase(4);
  AnotherRidiculouslyLongNameThatHoldsNoMeaning.erase(17);
  AnotherRidiculouslyLongNameThatHoldsNoMeaning.erase(11);
  std::cout << "After removing things from the first copy, its size is now: "
    << AnotherRidiculouslyLongNameThatHoldsNoMeaning.size() << std::endl;

  // Copy the first copy into the second copy now
  TheTruePointlessNameThatTrulyHasNoMeaning_orDoesIt =
    AnotherRidiculouslyLongNameThatHoldsNoMeaning;

  // Print it
  TheTruePointlessNameThatTrulyHasNoMeaning_orDoesIt.traverse(std::cout, IN);
  std::cout << std::endl;
  std::cout << "Size: " <<
    TheTruePointlessNameThatTrulyHasNoMeaning_orDoesIt.size() <<
    std::endl;

  // Finding three values from the third object.
  for(int i = 6; i != 10; i++)
  {
    if(TheTruePointlessNameThatTrulyHasNoMeaning_orDoesIt.find(i))
      std::cout << "Found the value: " << i << std::endl;
    else
      std::cout << i << " not found.\n";
  }

  // Delete everything from the first object.
  std::cout << "Deleting everything from the original object...\n";
  AbsurdlyLongObjectNameOfClass_BSTType_below80Chars.erase(11);
  AbsurdlyLongObjectNameOfClass_BSTType_below80Chars.erase(6);
  AbsurdlyLongObjectNameOfClass_BSTType_below80Chars.erase(4);
  AbsurdlyLongObjectNameOfClass_BSTType_below80Chars.erase(5);
  AbsurdlyLongObjectNameOfClass_BSTType_below80Chars.erase(8);
  AbsurdlyLongObjectNameOfClass_BSTType_below80Chars.erase(10);
  AbsurdlyLongObjectNameOfClass_BSTType_below80Chars.erase(19);
  AbsurdlyLongObjectNameOfClass_BSTType_below80Chars.erase(17);
  AbsurdlyLongObjectNameOfClass_BSTType_below80Chars.erase(43);
  AbsurdlyLongObjectNameOfClass_BSTType_below80Chars.erase(31);
  AbsurdlyLongObjectNameOfClass_BSTType_below80Chars.erase(49);
  if(AbsurdlyLongObjectNameOfClass_BSTType_below80Chars.empty())
    std::cout << "The original object is now empty\n";

  return ThatOneFunctionWhoseSolePurposeIsToReturnThisWonderful_Thing();
}

int ThatOneFunctionWhoseSolePurposeIsToReturnThisWonderful_Thing()
{
  // An elaborate and next-level way to return 0.
  bool WhatToDoWithThisBooleanValue__maybeJustReturnIt = false;
  while(false == false && true == true && ((1234 - 1234) == 0))
  {
    if(1 != 2)
    {
      WhatToDoWithThisBooleanValue__maybeJustReturnIt = true;
      break;
    }
  }
  if(WhatToDoWithThisBooleanValue__maybeJustReturnIt)
  {
    return 0;
  }
  else
    return (500+1)-(500)-1;
}
