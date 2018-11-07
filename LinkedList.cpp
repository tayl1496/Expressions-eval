/** @file
 *
 *  @course CS1521
 *  @section 1
 *
 *  Implementation file for a pointer-based implementation of the ADT
 *  list that uses smart pointers and a protected, nested type for the
 *  list's nodes (so that clients do not have access to them - they
 *  should be hidden as they are an implementation detail).
 *
 *  Adapted from pages 298-300, 442 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 24 Oct 2018
 *
 *  @version 7.0 */

// #define NDEBUG

#include <iostream>
#include <string>
#include <new>
#include <memory>

#include <cassert>

#include "PrecondViolatedExcep.h"

template <typename ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList) {

   itemCount = aList.itemCount;
   headPtr = copyChain(aList.headPtr);
}

#ifdef DTOR_TEST

#include <iostream>

template <typename ItemType>
LinkedList<ItemType>::~LinkedList() {

   std::cerr << "LinkedList destructor called on:\n"
             << "\theadPtr = "
             << headPtr
             << "\n\titemCount = "
             << itemCount
             << std::endl;

}

#endif

template <typename ItemType>
bool LinkedList<ItemType>::isEmpty() const {

   return !itemCount;
}

template <typename ItemType>
int LinkedList<ItemType>::getLength() const {

   return itemCount;
}

template <typename ItemType>
bool LinkedList<ItemType>::insert(int newPosition,
                                  const ItemType& newEntry) {

   bool ableToInsert(newPosition >= 1 &&
                     newPosition <= itemCount + 1);

   if (ableToInsert) {
      try {
         if (newPosition == 1) {
            headPtr = std::make_shared<ListNode>(newEntry,
                                                 headPtr);
         }
         else {
            auto prevPtr(getNodeAt(newPosition - 1) );

            prevPtr->next = std::make_shared<ListNode>(newEntry,
                                                       prevPtr->next);
         }

         ++itemCount;
      }
      catch (const std::bad_alloc&) {
         ableToInsert = false;
      }
   }

   return ableToInsert;
}

template <typename ItemType>
bool LinkedList<ItemType>::remove(int position) {

   bool ableToRemove(position >= 1 &&
                     position <= itemCount);

   if (ableToRemove) {
      if (position == 1) {
         headPtr = headPtr->next;
      }
      else {
         auto prevPtr(getNodeAt(position - 1) );
         auto curPtr(prevPtr->next);

         prevPtr->next = curPtr->next;
      }

      --itemCount;
   }

   return ableToRemove;
}

template <typename ItemType>
void LinkedList<ItemType>::clear() {

   headPtr.reset();
   itemCount = 0;
}

template <typename ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const {

   bool ableToGet(position >= 1 &&
                  position <= itemCount);

   if (!ableToGet) {
      std::string message("LinkedList::getEntry() called with an empty ");
      message += "list or an invalid position.";

      throw PrecondViolatedExcep(message);
   }

   auto nodePtr(getNodeAt(position) );

   return nodePtr->item;
}

template <typename ItemType>
ItemType LinkedList<ItemType>::replace(int position,
                                       const ItemType& newEntry) {

   bool ableToSet(position >= 1 &&
                  position <= itemCount);

   if (!ableToSet) {
      std::string message("LinkedList::setEntry() called with an empty ");
      message += "list or an invalid position.";

      throw PrecondViolatedExcep(message);
   }

   auto nodePtr(getNodeAt(position) );
   ItemType oldEntry(nodePtr->item);

   nodePtr->item = newEntry;

   return oldEntry;
}

template <typename ItemType>
auto LinkedList<ItemType>::getNodeAt(int position) const {

   assert(position >= 1 && position <= itemCount);

   auto curPtr(headPtr);

   for (auto skip(1); skip < position; ++skip) {
      curPtr = curPtr->next;
   }

   return curPtr;
}

// The return type below is specified *before* we are within the
// LinkedList scope. Thus we must properly scope the "ListNode" type:
// "LinkedList<ItemType>::ListNode". The returned shared_ptr is
// pointing at an object of this type. The use of the "typename"
// keyword tells the compiler to look for a "ListNode" type nested in
// "LinkedList", rather than a static member.
template <typename ItemType>
std::shared_ptr<typename LinkedList<ItemType>::ListNode>
LinkedList<ItemType>::copyChain(const ListNodePtr& origChainPtr) const {

   ListNodePtr copiedChainPtr;

   if (origChainPtr) {
      // Note that std::make_shared may throw a std::bad_alloc exception:
      copiedChainPtr = std::make_shared<ListNode>(origChainPtr->item);

      copiedChainPtr->next = copyChain(origChainPtr->next);
   }

   return copiedChainPtr;
}

template <typename ItemType>
bool LinkedList<ItemType>::operator==(const LinkedList<ItemType>& rhs) const {

   bool isEqual(itemCount == rhs.itemCount);

   if (isEqual) {
      auto lhsPtr(headPtr);
      auto rhsPtr(rhs.headPtr);

      while (isEqual &&
             lhsPtr &&
             rhsPtr) {
         isEqual = lhsPtr->item == rhsPtr->item;

         lhsPtr = lhsPtr->next;
         rhsPtr = rhsPtr->next;
      }
   }

   return isEqual;
}


template <typename ItemType>
LinkedList<ItemType>& LinkedList<ItemType>::operator=(const LinkedList<ItemType>& rhs) {

   // Commit or rollback:
   if (this != &rhs) {
      // Save lhs linked chain:
      auto oldLinkedChainPtr(headPtr);

      try {
         // Try to copy rhs linked chain (may throw bad_alloc):
         headPtr = copyChain(rhs.headPtr);

         // Deep copy successful, so COMMIT:
         itemCount = rhs.itemCount;
      }
      catch (const std::bad_alloc&) {
         // Deep copy failed, so ROLLBACK:
         headPtr = oldLinkedChainPtr;

         throw;
      }
   }

   return *this;
}

template <typename ItemType>
const LinkedList<ItemType> LinkedList<ItemType>::operator+(const LinkedList<ItemType>& rhs) const {

   LinkedList<ItemType> concatList;

   concatList.itemCount = itemCount + rhs.itemCount;

   concatList.headPtr = copyChain(headPtr);

   auto concatListTailPtr(concatList.headPtr);

   if (concatListTailPtr) {
      while (concatListTailPtr->next) {
         concatListTailPtr = concatListTailPtr->next;
      }
      concatListTailPtr->next = copyChain(rhs.headPtr);
   }
   else {
      concatListTailPtr = copyChain(rhs.headPtr);
   }

   // Note that if any of the calls to copyChain above throw a
   // bad_alloc exception, that exception is not handled here. Thus
   // the exception will propogate up the call stack to the
   // client. This means that the concatList object goes out of scope
   // and is properly destroyed and the return statement below never
   // executes. Therefore, there are no memory leaks because of smart
   // pointer use and the client is alerted via the bad_alloc being
   // thrown.

   return concatList;
}

// Being granted friendship, this overloaded operator has access to
// the nested ListNode type. Since the ListNode class has granted
// public access to all members, this overloaded operator can access
// the ListNode::item and ListNode::next data members directly in the
// code below.
template <typename ItemType>
std::ostream& operator<<(std::ostream& outputStream,
                         const LinkedList<ItemType>& outputList) {

   int position(1);
   auto curPtr(outputList.headPtr);

   while (curPtr) {
      outputStream << position
                   << "\t"
                   << curPtr->item;

      curPtr = curPtr->next;

      if (curPtr) {
         outputStream << std::endl;
      }

      ++position;
   }

   return outputStream;
}
