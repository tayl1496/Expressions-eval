/** @file
 *
 *  @course CS1521
 *  @section 1
 *
 *  Header file for a pointer-based implementation of the ADT list
 *  that uses smart pointers.
 *
 *  Adapted from pages 297-298, 442 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 24 Oct 2018
 *
 *  @version 7.0 */

#ifndef LINKED_LIST_
#define LINKED_LIST_

#include <iostream>
#include <memory>

#include "ListInterface.h"
// Cannot include LinkedList::ListNode here as the LinkedList class is
// not yet known to the compiler....

/** @class LinkedList LinkedList.h "LinkedList.h"
 *
 *  Specification of a pointer-based ADT list. */
template <typename ItemType>
class LinkedList : public ListInterface<ItemType> {
protected:
   // Nested class template declaration. Also called a "member type."
   // This is a nested class template based on ItemType -- the same
   // type as the containing class. Note that this is a nested *type*
   // (i.e. a member type) and making this type protected keeps
   // clients from having access to this type of object.
   //
   // This nested class template is defined in ListNode.h:
   class ListNode;

private:
   // The nested type can be used within the containing class template
   // without a template parameter as it shares the template parameter
   // of the nesting class:
   using ListNodePtr = std::shared_ptr<ListNode>;

   ListNodePtr headPtr;

   int itemCount = 0;

   /** Locates the node at the specified position in this list.
    *
    *  @pre 1 <= position <= itemCount
    *
    *  @post None.
    *
    *  @param position The desired position to locate.
    *
    *  @return A shared pointer to the position-th node in this list.
    */
   auto getNodeAt(int position) const;

   /** Copy the chain of nodes pointed to by chainPtr.
    *
    * @pre None.
    *
    * @post None.
    *
    * @param chainPtr A pointer to the chain of nodes to copy.
    *
    * @return A pointer to a deep copy of the nodes pointed to by
    *         chainPtr.
    *
    * @throws std::bad_alloc When memory allocation fails.
    */
   ListNodePtr copyChain(const ListNodePtr& chainPtr) const;

public:
   LinkedList() = default;

   LinkedList(const LinkedList<ItemType>& aList);

#ifdef DTOR_TEST
   virtual ~LinkedList();
#else
   virtual ~LinkedList() = default;
#endif

   bool isEmpty() const override;

   int getLength() const override;

   bool insert(int newPosition,
               const ItemType& newEntry) override;

   bool remove(int position) override;

   void clear() override;

   ItemType getEntry(int position) const override;

   ItemType replace(int position,
                    const ItemType& newEntry) override;

   bool operator==(const LinkedList<ItemType>& rhs) const;

   LinkedList<ItemType>& operator=(const LinkedList<ItemType>& rhs);

   const LinkedList<ItemType> operator+(const LinkedList<ItemType>& rhs) const;

   template <typename FriendItemType>
   friend std::ostream& operator<<(std::ostream& s,
                                   const LinkedList<FriendItemType>& outputList);
};

// Must include the nested (ListNode) class template type (and its
// implementation) before the LinkedList method template
// implementations so that the nested class is completely defined
// before it is used in LinkedList.cpp.
#include "ListNode.h"

#include "LinkedList.cpp"

#endif
