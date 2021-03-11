#pragma once
#include <stdbool.h>

typedef struct SIntStack* IntStack;

IntStack IntStack_create(int size);
int IntStack_getSize(IntStack _this);
int IntStack_getElementCount(IntStack _this);
bool IntStack_isFull(IntStack _this);
bool IntStack_isEmpty(IntStack _this);
void IntStack_push(IntStack _this, int value);
int IntStack_pop(IntStack _this);
int IntStack_peek(IntStack _this);
char *IntStack_toString(IntStack _this);
void IntStack_delete(IntStack _this);