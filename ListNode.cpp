/** @file
 *
 *  @course CS1521
 *  @section 1
 *
 *  Implementation file for a node in the linked implementation of the
 *  ADT list that grants friendship to the LinkedList class.
 *
 *  Not in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 24 Oct 2018
 *
 *  @version 7.0 */

#include <memory>

template <typename ItemType>
LinkedList<ItemType>::ListNode::ListNode(const ItemType& anItem,
                                         ListNodePtr nextListNodePtr)
   : item(anItem),
     next(nextListNodePtr) {
}

#ifdef DTOR_TEST

#include <iostream>

template <typename ItemType>
LinkedList<ItemType>::ListNode::~ListNode() {

   std::cout << "ListNode destructor called on:\n\titem: "
             << item
             << "\n\tnext: "
             << next.get()
             << std::endl;
}

#endif
