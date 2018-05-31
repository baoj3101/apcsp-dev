#include <stdio.h>
#include <string.h>

int mycmp (char* str1, char* str2) {
  // use strcmp to test if they are the same or not 
  if (strcmp (str1, str2) == 0) {
    printf ("String 1 and string 2 are identical.\n");
  } else {
    printf ("String 1 and string 2 are different.\n");
  }
}

int main () {
  // create two strings
  char str1[27];
  char str2[] = "abcdefghijklmnopqrstuvwxyz";
  char str3[53];

  // 'a' is the ASCII of lower case 'a'
  // 'a' + i is the ASCII of the i-th lower case letter 
  for (int i = 0; i < 26; i++) {
    str1[i] = 'a' + i;
  }

  mycmp(str1, str2);

  // convert string 1 to upper case
  for (int i = 0; i < 26; i++) {
    str1[i] = str1[i] - 'a' + 'A';
  }
 
  mycmp(str1, str2);

  // strcpy str1 to str3
  strcpy(str3, str1);

  // concat str2 to str3
  strcat (str3, str2);

  // print all three strings
  printf ("string 1: %s\n", str1);
  printf ("string 2: %s\n", str2);
  printf ("string 3: %s\n", str3);
}
	


