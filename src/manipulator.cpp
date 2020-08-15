#include "manipulator.h"
#include "crudmapper.h"

#include <QVariant>

#include <sstream>

namespace CRUD
{

std::pair<RESULT, int> Manipulator::insertRow(const QString &tableName, const QVariantList &rowData)
{
    const QString& query = generateInsertQuery(tableName, rowData.size());
    const std::pair<RESULT, QSqlQuery> &result = m_executor.execute(query, rowData);
    return { result.first, result.second.lastInsertId().toInt() };
}

QString Manipulator::generateBindString(size_t paramCount) const
{
    std::ostringstream bindings;
    std::fill_n(std::ostream_iterator<std::string>(bindings), paramCount, "?,");
    std::string bindString = bindings.str();
    bindString.pop_back(); // - ","
    return QString::fromStdString(bindString);
}

QString Manipulator::generateInsertQuery(const QString &tableName, size_t paramCount) const
{
    QString query
    {
        "INSERT INTO " + tableName +
        " (" +
        tablesMapping.at(tableName) +
        ")" +
        " VALUES ("
    };
    query += generateBindString(paramCount);
    query += ")";
    return query;
}

}
