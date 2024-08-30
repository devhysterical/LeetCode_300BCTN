/**
 * @file 706.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-08-30
 *
 * @copyright Copyright (c) 2024
 * @link https://leetcode.com/problems/design-hashmap/submissions/1373236204/
 * Time Complexity O(1)
 * Space Complexity O(N)
 */

#include <vector>

class MyHashMap
{
private:
  static const int SIZE = 1000;

  struct Node
  {
    int key;
    int value;
    Node *next;
    Node(int k, int v) : key(k), value(v), next(nullptr) {}
  };

  std::vector<Node *> table;

  int hash(int key)
  {
    return key % SIZE;
  }

public:
  MyHashMap() : table(SIZE, nullptr) {}

  void put(int key, int value)
  {
    int index = hash(key);
    Node *current = table[index];

    while (current)
    {
      if (current->key == key)
      {
        current->value = value;
        return;
      }
      current = current->next;
    }

    Node *newNode = new Node(key, value);
    newNode->next = table[index];
    table[index] = newNode;
  }

  int get(int key)
  {
    int index = hash(key);
    Node *current = table[index];

    while (current)
    {
      if (current->key == key)
      {
        return current->value;
      }
      current = current->next;
    }

    return -1;
  }

  void remove(int key)
  {
    int index = hash(key);
    Node *current = table[index];
    Node *prev = nullptr;

    while (current)
    {
      if (current->key == key)
      {
        if (prev)
        {
          prev->next = current->next;
        }
        else
        {
          table[index] = current->next;
        }
        delete current;
        return;
      }
      prev = current;
      current = current->next;
    }
  }

  ~MyHashMap()
  {
    for (Node *head : table)
    {
      while (head)
      {
        Node *temp = head;
        head = head->next;
        delete temp;
      }
    }
  }
};