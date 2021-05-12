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

bool SqliteDatabase::doesUserExists(const std::string name) const 
{
    std::string sqlStatment = "SELECT * FROM USERS WHERE NAME = '" + name + "';";
    bool exists = false;
    char* errMsg = nullptr;
    sqlite3_exec(_db, sqlStatment.c_str(), SqliteDatabase::userExistsCallback, &exists, &errMsg);
    return exists;
}

bool SqliteDatabase::doesPasswordMatch(const std::string name, const std::string pass) const
{
    std::string sqlStatment = "SELECT PASSWORD FROM USERS WHERE NAME = '" + name + "';";
    std::string passFromDB = "";
    char* errMsg = nullptr;
    sqlite3_exec(_db, sqlStatment.c_str(), SqliteDatabase::getPasswordCallback, &passFromDB, &errMsg);
    return pass == passFromDB;
}

void SqliteDatabase::addNewUser(const std::string name, const std::string pass, const std::string email) const
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

int SqliteDatabase::userExistsCallback(void* data, int argc, char** argv, char** azColName)
{
    bool* exists = (bool*)data;
    argc < 0 ? *exists = false : *exists = true;
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
