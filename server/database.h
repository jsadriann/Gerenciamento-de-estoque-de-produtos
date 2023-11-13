#ifndef DATABASE_H
#define DATABASE_H
#include <stdlib.h>
#include "postgresql/libpq-fe.h"
#include <string>

using namespace std;

PGconn* connectDB();
void closeDB(PGconn *);
void clearDB(PGresult *);
ConnStatusType statusDB(PGconn *);
PGresult* consultDB(PGconn *, const char * );
char* getValueDB(PGresult *,int, const char *);
int countTupleDB(PGresult *);

#endif