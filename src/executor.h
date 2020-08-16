#pragma once

#include <QSqlQuery>

#include "connectionmanager.h"

namespace CRUD
{
class Executor
{
public:
    Executor();
    Q_DISABLE_COPY(Executor)

    std::pair<RESULT, QSqlQuery> execute(const QString& queryText, const QVariantList &args = {});

    template<typename T, typename ... Args>
    static QStringList unpackArgs_toStringList(const T& first, const Args& ... args)
    {
        QStringList sl;
        sl.append(first);
        sl.append(unpackArgs_toStringList(args...));

        return sl;
    }

    static QStringList unpackArgs_toStringList()
    {
        return {};
    }

private:
    ConnectionManager& m_connectionManager;
};

}
