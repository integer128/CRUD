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
    Executor m_executor;
    QString generateBindString(size_t paramCount) const;
    QString generateInsertQuery(const QString &tableName, size_t paramCount) const;
};
}
