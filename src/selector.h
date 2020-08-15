#pragma once

#include "crudtypes.h"
#include "executor.h"

#include <QSqlRecord>
#include <QVariant>

namespace CRUD
{
class Selector
{
public:
    std::pair<RESULT, std::vector<QVariantList> > selectAll(const QString &tableName);

    template<typename ... Args>
    std::pair<RESULT, std::vector<QVariantList> > getColumns(const QString &tableName, const Args& ... args)
    {
        QString columnNames {unpackArgs_toStringList(args...).join(",")};   // "ColumnName1, ColumnName2, ... "
        QString query {"SELECT " + columnNames + " FROM " + tableName};
        std::vector<QVariantList> returnData;
        RESULT result;
        QSqlQuery resultQuery;
        std::tie(result, resultQuery) = m_executor.execute(query);

        if (result == RESULT::SUCCESS)
        {
            while (resultQuery.next())
            {
                const QSqlRecord &resultRecord {resultQuery.record()};
                QVariantList result;

                for (int i = 0; i < resultRecord.count(); ++i)
                {
                    result.push_back(resultRecord.value(i));
                }
                returnData.push_back(std::move(result));
            }
        }
        return { result, returnData };
    }

private:
    Executor m_executor;

    QString generateQuery(const QString &tableName) const;        
};

template<typename T, typename ... Args>
QStringList unpackArgs_toStringList(const T& first, const Args& ... args)
{
    QStringList sl;
    sl.append(first);
    sl.append(unpackArgs_toStringList(args...));

    return sl;
}

QStringList unpackArgs_toStringList()
{
    return {};
}

}
