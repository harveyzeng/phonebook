#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include <ctype.h>

#include "phonebook_opt.h"
int strcasecmp(const char*, const char*);
char *strcpy(char* , const char*);
/* original version */
entry *findName(char lastname[], entry *pHead)
{
    if (pHead != NULL) {
        do {
            if (strcasecmp(lastname, pHead->lastName) != 0)
                pHead = pHead->pNext;
            else return pHead;
        } while (pHead != NULL);
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    /* allocate memory for the new entry and put lastName */
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;


    return e;
}


int strcasecmp(const char *s1, const char *s2)
{
    int c1, c2;

    do {
        c1 = tolower(*s1++);
        c2 = tolower(*s2++);
    } while (c1 == c2 && c1 != 0);
    return c1 - c2;
}


char *strcpy(char *dest, const char *src)
{
    char *tmp = dest;

    do {} while ((*dest++ = *src++) != '\0');
    /* nothing */;
    return tmp;
}



