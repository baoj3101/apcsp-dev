#include <stdio.h>

int main()
{
  
  int a;
  int* ptrtoa;

  ptrtoa = &a;

  a = 5;
  printf("The value of a is %d\n", a);

  *ptrtoa = 6;
  printf("The value of a is %d\n", a);

  printf("The value of ptrtoa is %d\n", ptrtoa);
  printf("It stores the value %d\n", *ptrtoa);
  printf("The address of a is %d\n", &a);

  float d = 3.14;
  float e = 2.71;
  float* ptrtod = &d;
  float* ptrtoe = &e;

  printf ("the value of d is %8.2f\n", d);
  printf ("the value  of e is %8.2f\n", e);
  printf ("the adress of d is %d\n", &d);
  printf ("the adress of e is %d\n", &e);

  float tmp;
  tmp = *ptrtod;
  *ptrtod = *ptrtoe;
  *ptrtoe = tmp;

  printf ("the value of d is %8.2f\n",d); 
  printf ("the value of e is %8.2f\n",e); 

}

