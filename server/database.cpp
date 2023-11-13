#include "database.h"
const char *conninfo = "user=postgres password=adrianec@123 dbname=projeto";
PGconn* connectDB(){
    PGconn *database = PQconnectdb(conninfo);
    return database;
}
void closeDB(PGconn *database){
    PQfinish(database);
}
void clearDB(PGresult *result){
    PQclear(result);
}
ConnStatusType statusDB(PGconn *database){
    return PQstatus(database);
}
PGresult* consultDB(PGconn *database, const char *query ){
    return PQexec(database, query);
}
char* getValueDB(PGresult *result, int tuple,const char *column){
    return PQgetvalue(result, tuple, PQfnumber(result, column));
}
int countTupleDB(PGresult *result){
    return PQntuples(result);
}
