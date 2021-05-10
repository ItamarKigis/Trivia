#include "SqliteDatabase.h"

bool SqliteDatabase::doesUserExists(std::string)
{
    return false;
}

bool SqliteDatabase::doesPasswordMatch(std::string, std::string)
{
    return false;
}

void SqliteDatabase::addNewUser(std::string, std::string, std::string)
{

}
