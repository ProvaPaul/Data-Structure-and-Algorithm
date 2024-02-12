#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class node
{
public:
  int data;
  struct node *pre;
  struct node *next;
  node(int n)
  {
    this->data = n;
    pre = NULL;
    next = NULL;
  }
};
class doubly
{
  node *head;
  node *first;
  node *temp;
  node *tail;
  int l;

public:
  doubly()
  {
    head = NULL;
    first = NULL;
    temp = NULL;
    tail = NULL;
    l = 0;
  }
  list_size()
  {
    return l;
  }
  void travesal()
  {
    node *ptr = head;
    while (ptr != NULL)
    {
      cout << ptr->data << " ";
      ptr = ptr->next;
    }
    cout << endl;
  }

  void insert_front(int n)
  {
    node *ptr = new node(n);
    if (head == NULL)
    {
      head = ptr;
      tail = ptr;
    }
    else
    {
      ptr->next = head;
      head->pre = ptr;
      head = ptr;
    }
    l++;
  }
  void insertion_at_end(int n)
  {
    node *ptr = head;
    node *temp = new node(n);
    if (head == NULL)
    {
      head = temp;
      tail = temp;
    }
    while (ptr->next != NULL)
    {
      ptr = ptr->next;
    }
    ptr->next = temp;
    temp->pre = ptr;
    tail = temp;
    l++;
  }
  void insertion_after_given_index(int index, int n)
  {
    if (index < 0 || index >= l)
    {
      cout << "INVALID INDEX" << endl;
      return;
    }
    node *ptr = head;
    for (int i = 0; i < index; i++)
    {
      ptr = ptr->next;
    }
    node *temp = new node(n);
    temp->pre = ptr;
    temp->next = ptr->next;
    if (ptr->next != NULL)
    {
      ptr->next->pre = temp;
    }
    ptr->next = temp;
    if (temp->next == NULL)
    {
      tail = temp;
    }
    l++;
  }
  void insert_after_given_value(int data, int n)
  {
    node *ptr = head;
    while (ptr != NULL && ptr->data != data)
    {
      ptr = ptr->next;
    }
    if (ptr == NULL)
    {
      cout << "DATA DOESNT EXIST" << endl;
      return;
    }
    node *temp = new node(n);
    temp->next = ptr->next;
    temp->pre = ptr;
    ptr->next = temp;
    if (ptr->next != NULL)
    {
      ptr->next->pre = temp;
    }
    ptr->next = temp;
    if (temp->next == NULL)
    {
      tail = temp;
    }
    l++;
  }
  void insert_before_given_index(int index, int n)
  {
    if (index < 0 || index >= l)
    {
      cout << "INVALID INDEX" << endl;
      return;
    }
    node *ptr = head;
    for (int i = 0; i < index - 1; i++)
    {
      ptr = ptr->next;
    }
    node *temp = new node(n);
    temp->pre = ptr;
    temp->next = ptr->next;
    if (ptr->next != NULL)
    {
      ptr->next->pre = temp;
    }
    ptr->next = temp;
    if (temp->next == NULL)
    {
      tail = temp;
    }
    
    l++;
  }
  void de_first()
  {
    node *temp = head;
    head = head->next;
    free(temp);
    l--;
  }
  void de_last()
  {
    if (head == NULL)
    {
      cout << "NOTHING TO DELETE" << endl;
      return;
    }
    if (head->next == NULL)
    {
      free(head);
      head = NULL;
      tail = NULL;
      l--;
      return;
    }
    node *temp = head;
    while (temp->next->next != NULL)
    {
      temp = temp->next;
    }
    node *dlt=temp->next;
    temp->next = NULL;
    tail = temp;
    free(dlt);
    l--;
  }
  void de_given_index(int index)
  {
    if (index < 0 || index > l)
    {
      cout << "INNDEX DOESNT EXIST" << endl;
      return;
    }
    node *ptr = head;
    for (int i = 0; i < index; i++)
    {
      ptr = ptr->next;
    }
    if (ptr == head)
    {
      head = ptr->next;
    }
    if (ptr == tail)
    {
      tail = ptr->pre;
    }
    if (ptr->pre != NULL)
    {
      ptr->pre->next = ptr->next;
    }
    if (ptr->next != NULL)
    {
      ptr->next->pre = ptr->pre;
    }
    free(ptr);
    l--;
  }

  void reverse()
  {
    node *ptr1 = head;
    node *ptr2 = ptr1->next;
    ptr1->next = NULL;
    ptr1->pre = ptr2;
    while (ptr2 != NULL)
    {
      ptr2->pre = ptr2->next;
      ptr2->next = ptr1;
      ptr1 = ptr2;
      ptr2 = ptr2->pre;
    }
    head = ptr1;
  }
};
int main()
{
  doubly a;

  a.insert_front(5);
  a.insert_front(6);
  a.insert_front(10);
  a.travesal();
  cout << endl;
  a.insertion_at_end(100);
  a.travesal();
  cout << endl;
  a.insertion_after_given_index(2, 200);
  a.travesal();
  cout << endl;
  a.insert_after_given_value(200, 25);
  a.travesal();
  cout << endl;
  a.insert_before_given_index(2, 77);
  a.travesal();
  cout << endl;
  a.de_first();
  a.travesal();
  cout << endl;
  a.de_last();
  a.travesal();
  cout << endl;
  a.de_given_index(2);
  a.travesal();
  cout << endl;
  a.reverse();
  a.travesal();
  cout << endl;
  return 0;
}