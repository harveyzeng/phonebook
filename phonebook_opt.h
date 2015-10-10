#ifndef _PHONEBOOK_H_opt
#define _PHONEBOOK_H_opt

#define MAX_LAST_NAME_SIZE 16

/* original version */
typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    struct info *info;
    struct __PHONE_BOOK_ENTRY *pNext;
} entry;

typedef struct info {
    char lastName[MAX_LAST_NAME_SIZE];
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];

} info;
entry *findName(char lastname[], entry *pHead);
entry *append(char lastName[], entry *e);

#endif
