#include <stddef.h>

typedef struct customer {
    char *name;
    char *email;
    char *phone;
} customer;

typedef struct database {
    size_t userid;
    size_t database;
    size_t contents;
    customer *database_contents;
} database;

database *database_table(size_t userid);

int add(database *db, char *name, char *email, char *phone); {

}

int lookup(database *db, char *email);

int delete(database *db, char *email);

int list(database *db, char *email);

int save(database *db, char file[]);

int quit(database* db);
