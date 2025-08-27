#include <stdio.h>
#include <stlib.h>
#include <string.h>


int insertR(struct Node **node, int y)
{
  if (*node == NULL)
  {
    *node = makeNode(y);
    return 1;
   }
  if ((*node)->val<y) return insertR(&((*node)->left), y);
}
int main() 
{
  

  




  
}
