#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define bufferSize 16

typedef struct ListNode {
    int value;
    struct ListNode *next;
} ListNodeS, *ListNodeP;

struct SIntStack {
    ListNodeP list;
    int maxSize;
    int size;
    char *str;
};

IntStack IntStack_create(int size) {
    IntStack ret = (IntStack) malloc(sizeof (struct SIntStack));

    ret->maxSize = size;
    ret->size = 0;
    ret->list = NULL;
    ret->str = NULL;

    return ret;
}

int IntStack_getSize(IntStack _this) {
    return _this->maxSize;
}

int IntStack_getElementCount(IntStack _this) {
    return _this->size;
}

bool IntStack_isFull(IntStack _this) {
    if (_this->maxSize == -1) return false;
    return _this->size == _this->maxSize;
}

bool IntStack_isEmpty(IntStack _this) {
    return _this->size == 0;
}

void IntStack_push(IntStack _this, int value) {
    if (_this->maxSize!= -1 && _this->size == _this->maxSize) {
        printf("Error: Cannot push to full stack.\n");
        return;
    }

    _this->size += 1;

    ListNodeP next = _this->list;
    _this->list = (ListNodeP) malloc(sizeof (ListNodeS));

    _this->list->value = value;
    _this->list->next = next;
}

int IntStack_pop(IntStack _this) {
    if (_this->size == 0) {
        printf("Error: Cannot pop off empty stack.\n");
        return -1;
    }

    int value = _this->list->value;
    ListNodeP toDelete = _this->list;

    _this->list = _this->list->next;
    _this->size -= 1;

    free(toDelete);

    return value;
}

int IntStack_peek(IntStack _this) {
    return _this->list->value;
}

char *IntStack_toString(IntStack _this) {
    if (_this->str == NULL) {
        _this->str = (char *) malloc(sizeof (char));
        _this->str[0] = '\0';
    }

    ListNodeP runningP = _this->list;
    for (int i = 0; i < _this->size; i++) {
        char tempStr[bufferSize];
        sprintf(tempStr, "%d; ", runningP->value);

        _this->str = (char *) realloc(_this->str, strlen(_this->str) + strlen(tempStr) + 1);
        i == 0 ? strcpy(_this->str, tempStr) : strcat(_this->str, tempStr);
        runningP = runningP->next;
    }

    return _this->size == 0 ? NULL : _this->str;
}

void IntStack_delete(IntStack _this) {
    for (int i = 0; i < _this->size; i++) {
        ListNodeP temp = _this->list;
        _this->list = _this->list->next;

        free(temp);
    }
    free(_this->str);

    free(_this);
}