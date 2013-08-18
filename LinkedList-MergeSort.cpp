#include <iostream>
#include <vector>

using namespace std;

struct Node{
  int data;
  Node * pNext;
  Node(int _data){
    data=_data;
    pNext=NULL;
  }
};

