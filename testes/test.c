#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "queue.h"
#include "linkedlist.h"

char *string_add_last(char *string, char *c) {

  size_t prev_size = sizeof(*string);

  size_t index = prev_size/sizeof(char)-1;

  printf("prev_size: %lu\n", prev_size);
  printf("index: %lu\n", index);

  string = (char *)realloc(string, prev_size + sizeof(c));

  for (int i=0; strcmp(&c[i],"\0")!=0; i++) {

      string[index] = c[i];
      index++;

  }

  return string;

}

char * str() {

    char buffer [50];

    int n = sprintf(buffer,"que cena fixe");

    printf("size: %d\n", n);

    char *r =  (char *) realloc(buffer,sizeof(char)*n);

    return r;

}

#include <stdio.h>
#include <math.h> /* Used for log10() */

int main()
{
    int num;


    /* Input number from user */
    printf("Enter any number: ");
    scanf("%d", &num);

    /* Calculate total digits */
    int count = log10(num) + 1;

    printf("Total digits: %d\n", count);

    return 0;
}

// int main() {
//
//   // QUEUE *q1 = mk_empty_queue(10);
//   // QUEUE *q2 = mk_empty_queue(10);
//   //
//   // enqueue(5,q1);
//   // enqueue(5,q1);
//   // enqueue(5,q1);
//   // enqueue(5,q1);
//   //
//   // enqueue(5,q2);
//   // enqueue(5,q2);
//   // enqueue(5,q2);
//   // enqueue(5,q2);
//   // enqueue(5,q2);
//   // enqueue(5,q2);
//   // dequeue(q2);
//   // dequeue(q2);
//   // dequeue(q2);
//   // enqueue(5,q2);
//   //
//   //
//   // printf("comprimento? %d\n", comprimento(q2));
//
//
//
//
//
//   // char *t= (char *) malloc(0);
//   // // size_t size =0;
//   // t = string_add_last(t,"boas ");
//   //
//   // printf("%lu\n", sizeof(t));
//   // printf("%s\n", t);
//
//
//   printf("%s\n",str());
//
//   return 0;
//
// }
