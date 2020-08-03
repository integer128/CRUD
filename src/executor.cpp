#include "executor.h"

#include <QSqlError>
#include <QDebug>

namespace CRUD
{

Executor::Executor()
    : m_connectionManager(ConnectionManager::instance())
{

}

std::pair<RESULT, QSqlQuery> Executor::execute(const QString &queryText, const QVariantList &args)
{
    if(!m_connectionManager.isValid())
    {
        qCritical() << "Database isn't valid";
        return std::make_pair(RESULT::FAIL, QSqlQuery());
    }

    QSqlQuery query(queryText);

    for(int i = 0; i < args.size(); ++i)
    {
        query.bindValue(i, args[i]);
    }

    RESULT result = RESULT::SUCCESS;

    if(!query.exec() && query.lastError().isValid())
    {
        qCritical() << query.lastError().text() << " " << query.lastQuery();
        result = RESULT::FAIL;
    }
    return { result, query };
}
}
