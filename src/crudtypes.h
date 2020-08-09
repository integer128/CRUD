#pragma once

namespace CRUD
{
constexpr short ID = 1;
enum class RESULT
{
    SUCCESS,
    FAIL
};

enum class TABLES
{

};

enum class STATE
{
    OK,
    ERROR_NO_DRIVER,
    ERROR_WORKSPACE,
    ERROR_TABLES,
    ERROR_OPENING,
    ERROR_ROW
};
}
