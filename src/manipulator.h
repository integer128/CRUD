#pragma once

#include "executor.h"
#include "crudtypes.h"

#include <QVariant>

namespace CRUD
{
class Manipulator
{
public:
    std::pair<RESULT, int> insertRow(const QString &tableName, const QVariantList &rowData);

    template <typename ... Args>
    std::pair<RESULT, int> setColumns(const QString &tableName, const std::vector<QVariantList> &data, const Args& ... args)
    {
        const QString columnNames {Executor::unpackArgs_toStringList(args...).join(",")};   // "ColumnName1, ColumnName2, ... "
        const int columnCount {sizeof... (args)};
        QString query
        {
            "INSERT INTO " + tableName +
            " (" + columnNames + ") VALUES (" +
            generateBindString(columnCount) + ")"
        };

        int rowsInserted {0};
        RESULT result;

        for (auto row : data)
        {
            result = m_executor.execute(query, row).first;
            rowsInserted++;
        }

        return { result, rowsInserted };
    }

private:
    QString generateBindString(const size_t &paramCount) const;
    QString generateInsertQuery(const QString &tableName, const size_t &paramCount) const;

    Executor m_executor;
};
}
