#include "SqliteDatabase.h"
#include <iostream>
#include <io.h>

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

void SqliteDatabase::addNewUser(const std::string name, const std::string pass, const std::string email) 
{
    std::string sqlStatment = "INSERT INTO USERS (NAME,PASSWORD,EMAIL) VALUES ('" + name + "','" + pass + "','" + email + "');";
    char* errMsg = nullptr;
    sqlite3_exec(_db, sqlStatment.c_str(), nullptr, nullptr, &errMsg);
}

std::list<Question> SqliteDatabase::getQuestions(const int num) const
{
    return std::list<Question>();
}

float SqliteDatabase::getPlayerAvgAnsTime(const std::string name) const
{
    return 0.0f;
}

int SqliteDatabase::getNumOfCorrectAnswers(const std::string username) const
{
    return 0;
}

int SqliteDatabase::getNumOfTotalAnswers(const std::string username) const
{
    return 0;
}

int SqliteDatabase::getNumOfPlayerGames(const std::string username) const
{
    return 0;
}

std::vector<std::string> SqliteDatabase::getHighScore() const
{
    return std::vector<std::string>();
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

void SqliteDatabase::createTable(const char* sql)
{
    const char* sqlStatement = sql;

    char* errMessage = nullptr;
    int res = sqlite3_exec(_db, sqlStatement, nullptr, nullptr, &errMessage);
    if (res != SQLITE_OK)
    {
        std::cout << res << std::endl;
    }
}

void SqliteDatabase::open()
{
    int doesDBExists = _access(_dbName.c_str(), 0);

    int res = sqlite3_open(_dbName.c_str(), &_db);
    if (res != SQLITE_OK) {
        _db = nullptr;
        std::cout << "Failed to open DB" << std::endl;
    }
    if (doesDBExists == 0) //doesnt exists
    {
        createTable("CREATE TABLE USERS (NAME TEXT PRIMARY KEY NOT NULL, PASSWORD TEXT NOT NULL, EMAIL TEXT NOT NULL);");
        createTable("CREATE TABLE STATISTICS (USERNAME TEXT NOT NULL, AVERAGE_ANS_TIME FLOAT, NUM_OF_CORRECT_ANSWERS INT, NUM_OF_TOTAL_ASNWERS INT, NUM_OF_GAMES INT,FOREIGN KEY (USERNAME) REFERENCES USERS(NAME));");
    }
}

void SqliteDatabase::close()
{
    sqlite3_close(_db);
}
