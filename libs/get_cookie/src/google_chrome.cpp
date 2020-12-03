//
// Created by Pip Grylls on 03/12/2020.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <sqlite3.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    int i;
    for(i = 0; i<argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int get_cookie(const char *data) {
    const char *cookie_location = "~/Library/Application Support/Google/Chrome/Default/Cookies";
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    std::string sql;

    rc = sqlite3_open(cookie_location, &db);
    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(1);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }
    std::string strHost = ".adventofcode.com";
    std::string strField = "";
    sql = "SELECT value FROM cookies WHERE host_key LIKE '%" +
                      strHost + "%' AND name LIKE '%" + strField + "%';";

    rc = sqlite3_exec(db, sql.c_str(), callback, (void *) data, &zErrMsg);

    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Operation done successfully\n");
    }
    sqlite3_close(db);
    return 0;
}




