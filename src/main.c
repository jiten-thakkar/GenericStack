#include "stack.h"


int intCompare(const void* a, const void* b) {
  int *ia = (int*)a;
  int *ib = (int*)b;
  return *ia < *ib;
}

int main() {
  Stack *s = createStack(sizeof(int), 3);
  assert(s);
  assert(s->memberSize == sizeof(int));
  assert(s->totalElements == 3);
  int a=4,b=5,c=7;
  int d, r;
 
  r = stackPush(s, (void*)&a);
  assert(s->top == 0);
  assert(r == 0);
 
  r = stackPush(s, (void*)&b);
  assert(s->top == 1);
  assert(r == 0);

  r = stackPop(s, (void*)&d);
  assert(r == 0);
  assert(s->top == 0);
  assert(d == 5);

  r = stackTop(s, (void*)&d);
  assert(r == 0);
  assert(s->top == 0);
  assert(d == 4);

  r = stackPush(s, (void*)&c);
  assert(s->top == 1);
  assert(r == 0);

  r = stackPop(s, (void*)&d);
  assert(s->top == 0);
  assert(d == 7);
  assert(r == 0);

  r = stackPop(s, (void*)&d);
  assert(s->top == -1);
  assert(d == 4);
  assert(r == 0);

  r = stackPop(s, (void*)&d);
  assert(s->top == -1);
  assert(r == 1);

  r = stackTop(s, (void*)&d);
  assert(s->top == -1);
  assert(r == 1);

  r = stackPush(s, (void*)&a);
  assert(s->top == 0);
  assert(r == 0);

  r = stackPush(s, (void*)&b);
  assert(s->top == 1);
  assert(r == 0);

  r =stackPush(s, (void*)&c);
  assert(s->top == 2);
  assert(r == 0);

  r =stackPush(s, (void*)&c);
  assert(s->top == 3);
  assert(r == 0);
  assert(s->totalElements == 6);

  r = getMax(s, (void*)&d, intCompare);
  assert(r == 0);
  assert(s->top == 3);
  assert(d == 7);

  r = stackDestroy(s);
  assert(r == 0);

  printf("success\n");
}
