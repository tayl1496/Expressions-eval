/** @file
 *
 *  @course CS1521
 *  @section 1
 *
 *  Header file for the LinkedList::ListNode nested class.
 *
 *  Adapted from page 443 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 24 Oct 2018
 *
 *  @version 7.0 */

#ifndef LIST_NODE_
#define LIST_NODE_

#include <memory>

// Everything is declared public here as the type itself is a
// protected member of the LinkedList class template, and thus,
// clients do not have access to any of the members. Making the
// constructors and destructor public is critical because the
// make_shared function must have access to the constructors to be
// able to build ListNodes; and the shared_ptr class must have access
// to the destructor in order to properly destroy objects of this
// type.
template <typename ItemType>
class LinkedList<ItemType>::ListNode {
public:
   using ListNodePtr = std::shared_ptr<ListNode>;

   ItemType item;
   ListNodePtr next;

   ListNode() = default;

   ListNode(const ItemType& anItem,
            ListNodePtr nextNodePtr);

#ifdef DTOR_TEST
   virtual ~ListNode();
#else
   virtual ~ListNode() = default;
#endif
};

#include "ListNode.cpp"

#endif
