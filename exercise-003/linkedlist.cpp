#include "linkedlist.h"

LinkedList::~LinkedList()
{
  while (size() != 0) {
    auto tmp = m_head; /* save the element to be deleted */
    if(remove(tmp)){
      delete tmp;
    }
  }
}

bool LinkedList::insert_tail(LinkedListNode *node)
{
  bool ret = false;
  if (nullptr == node) {
    return ret;
  }
  if (nullptr == m_tail) {
    // Wenn die Liste leer ist, füge das erste Element ein
    m_head = node;
    m_tail = node;
    ret = true;
  } else {
    // Füge das Element ans Ende der Liste hinzu
    m_tail->pNext = node;
    m_tail = node;
    ret = true;
  }
  return ret;
}

bool LinkedList::insert_head(LinkedListNode *node)
{
  bool ret = false;
  if (nullptr == node) {
    return ret;
  }
  node->pNext = m_head;
  m_head = node;
  ret = true;
  return ret;
}

bool LinkedList::insert_after(LinkedListNode *loc, LinkedListNode *node)
{
  bool ret = false;
  if ((nullptr == loc) || (nullptr == node)) {
    return ret;
  }
  if (nullptr == loc->pNext){
    m_tail = node;
  }
  auto tmp = loc->pNext;
  loc->pNext = node;
  node->pNext = tmp;
  ret = true;
  return ret;
}

bool LinkedList::insert_before(LinkedListNode *loc, LinkedListNode *node)
{
  bool ret = false;
  if ((nullptr == loc) || (nullptr == node)){
    return ret;
  }
  LinkedListNode *ptr = LinkedList::m_head;
  while(ptr->pNext != loc || ptr->pNext != nullptr){
      ptr = ptr->pNext;
  }
  if (ptr == nullptr){
    return ret;
  }
  auto tmp = ptr->pNext;
  ptr->pNext = node;
  node->pNext = tmp;
  ret = true;
  return ret;
}

bool LinkedList::remove(LinkedListNode *node)
{
  bool ret = false;
  auto *ptr = m_head;
  if (nullptr == m_head || nullptr == m_tail){
    return false;
  }
  if (node = m_head){
    m_head = nullptr;
    m_tail = nullptr;
    return true;
    }
  while(ptr->pNext != node){
      ptr = ptr->pNext;
      if (ptr == nullptr){
        return ret;
      }
  }
  ptr->pNext = node->pNext;
  ret = true;
  return ret;
}

size_t LinkedList::size()
{
  size_t count = 0;
  /* using a lambda to count objects in the list*/
  traverse([&count](LinkedListNode *node) { count++; });
  return count;
}


void LinkedList::traverse(std::function<void(const std::string &)> func)
{
  traverse([&](LinkedListNode *node) { func(node->m_name); });
}

void LinkedList::traverse(std::function<void(LinkedListNode *node)> func)
{
  for (auto tmp = m_head; tmp != nullptr; tmp = tmp->pNext) {
    func(tmp);
  }
}