#pragma once

#include <QSqlRecord>
#include <QVariant>

#include "crudtypes.h"
#include "executor.h"

namespace CRUD
{
class Selector
{
public:
    std::pair<RESULT, std::vector<QVariantList> > selectAll(const QString &tableName);

    template<typename ... Args>
    std::pair<RESULT, std::vector<QVariantList> > getColumns(const QString &tableName, const Args& ... args)
    {
        const QString columnNames {Executor::unpackArgs_toStringList(args...).join(",")};   // "ColumnName1, ColumnName2, ... "
        const QString query {"SELECT " + columnNames + " FROM " + tableName};
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

}
