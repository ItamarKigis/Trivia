#include "SqliteDatabase.h"
#include "sqlite3.h"
#include <iostream>

SqliteDatabase::SqliteDatabase(const std::string dbName) : _dbName(dbName), IDataBase()
{
    open();
}

SqliteDatabase::~SqliteDatabase()
{
    close();
}

bool SqliteDatabase::doesUserExists(std::string name)
{
    return false;
}

bool SqliteDatabase::doesPasswordMatch(std::string name, std::string pass)
{
    std::string sqlStatment = "SELECT PASSWORD FROM USERS WHERE NAME = '" + name + "';";
    std::string passFromDB = "";
    char* errMsg = nullptr;
    sqlite3_exec(_db, sqlStatment.c_str(), SqliteDatabase::getPasswordCallback, &passFromDB, &errMsg);
    return pass == passFromDB;
}

void SqliteDatabase::addNewUser(std::string name, std::string pass, std::string email)
{
    std::string sqlStatment = "INSERT INTO USERS (NAME,PASSWORD,EMAIL) VALUES ('" + name + "','" + pass + "','" + email + "');";
    char* errMsg = nullptr;
    sqlite3_exec(_db, sqlStatment.c_str(), nullptr, nullptr, &errMsg);
}

int SqliteDatabase::getPasswordCallback(void* data, int argc, char** argv, char** azColName)
{
    std::string* pass = (std::string*)data;
    *pass += argv[0];
    return 0;
}

void SqliteDatabase::open()
{
    int res = sqlite3_open(_dbName.c_str(), &_db);
    if (res != SQLITE_OK) {
        _db = nullptr;
        std::cout << "Failed to open DB" << std::endl;
    }
}

void SqliteDatabase::close()
{
    sqlite3_close(_db);
}
