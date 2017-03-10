#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct {
  int memberSize;
  int totalElements;
  void* data;
  int top;
} Stack;

Stack* createStack(int memberSize, int totalElements);
int stackDestroy(Stack *s);
int stackPush(Stack *s, void *data);
int stackPop(Stack *s, void *target);
int stackTop(Stack *s, void *target);
int getMax(Stack *s, void* max, int (*compare)(const void* a, const void* b));

