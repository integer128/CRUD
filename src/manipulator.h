#pragma once

#include "executor.h"
#include "crudtypes.h"

namespace CRUD
{
class Manipulator
{
public:
    std::pair<RESULT, int> insertRow(const QString &tableName, const QVariantList &rowData);

private:
    QString generateBindString(const size_t &paramCount) const;
    QString generateInsertQuery(const QString &tableName, const size_t &paramCount) const;

    Executor m_executor;
};
}
