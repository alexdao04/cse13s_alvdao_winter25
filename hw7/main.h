#include <stddef.h>

typedef struct customer {
    char name[100];
    char email[100];
    char food[100];
} customer;

typedef struct database {
    int userid;
    char database;
    char contents;
    customer *database_storage;
} database;

database *database_table(size_t userid);

int add(database *dbase, char *name, char *email, char *food, int userid) {

}

int lookup(database *dbase, char *email);

int delete(database *dbase, char *email);

int list(database *dbase, char *email);

int save(database *dbase, char file[]);

int quit(database* dbase);
