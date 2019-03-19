// A test for AssocList
// The test returns exit code 0 for success and 1 for failure


#include "../AssocList.h"

using namespace std;

int main()
{
  AssocList<int, int> list;
  
  int buff[10];
  for (int i = 0; i < 11; ++i)
    {
      
      buff[i] = i*i*i;
      list.add(i,&buff[i]);
    }
  
  if (list.lookup(1) != &buff[1]){
    return 1;
  }
  
  if (list.lookup(4) != &buff[4])
    return 1;

  if (list.lookup(7) != &buff[7])
    return 1;
  
  if (list.lookup(0) != &buff[0])
    return 1;

  return 0;
}

