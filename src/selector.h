#pragma once

#include "crudtypes.h"
#include "executor.h"

namespace CRUD
{
class Selector
{
public:
    std::pair<RESULT, std::vector<QVariantList> > selectAll(const QString &tableName);

private:
    Executor m_executor;

    QString generateQuery(const QString &tableName) const;
};
}
