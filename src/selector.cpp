#include "selector.h"

#include <QSqlRecord>
#include <QVariant>

namespace CRUD
{
std::pair<RESULT, std::vector<QVariantList> > Selector::selectAll(const QString &tableName)
{
    QString query { generateQuery(tableName) };
    std::vector<QVariantList> returnData;
    RESULT result;
    QSqlQuery resultQuery;
    std::tie(result, resultQuery) = m_executor.execute(query);

    if (result == RESULT::SUCCESS)
    {
        while (resultQuery.next())
        {
            const QSqlRecord &resultRecord = resultQuery.record();
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

QString Selector::generateQuery(const QString &tableName) const
{
    return QString("SELECT rowid, * FROM " + tableName );
}

}
