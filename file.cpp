# include "Node.cpp"
# include "strings.h"

int main()
{
  Node *head = NULL;
  head = insert(head,1);
  display(head);
  head = insert(head,2);
  display(head);
  head = insert(head,3);
  display(head);
  head = insert(head,4);
  display(head);
  head = insert(head,5,1);
  display(head);
  head = insert(head,6,0);
  display(head);
  head = insert(head,7,10);
  display(head);
  // head = remove(head,0);
  // display(head);
  // head = remove(head,3);
  // display(head);
  // head = remove(head,20);
  // display(head);
  // head = insert(head,8);
  // display(head);
  // head = insert(head,9);
  // display(head);
  // head = remove(head);
  // display(head);
  // head = pop(head);
  // display(head);
  Node *nth;
  nth = nthNodeFromEnd(head,0);
  try {
    if (nth)
      cout << nth->data << endl;
    else
      throw(0);
  }
  catch (int error){
    cout << "'nthNodeFromEnd' returned NULL" << endl;
  }
}
