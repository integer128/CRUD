#pragma once

#include <memory>

#include "selector.h"
#include "manipulator.h"

namespace CRUD
{
class ProcessorPrivate
{
public:
    Manipulator manipulator;
    Selector selector;
};

class Processor
{
public:
    Processor();
    ~Processor();

    std::pair<RESULT, std::vector<QVariantList>> requestTableData(TABLES table);

    template <typename ... Args>
    std::pair<RESULT, std::vector<QVariantList>> getColumns(const QString &tableName, const Args& ... args)
    {
        return m_processorPrivate->selector.getColumns(tableName, args...);
//        std::vector<QVariantList> result;
//        RESULT resultState;
//        std::tie(resultState, result) = m_processorPrivate->selector.getColumns(tableName, args...);

//        return std::make_pair(resultState, std::move(result));
    }

    template <typename ... Args>
    std::pair<RESULT, int> setColumns(const QString &tableName,
                                                            const std::vector<QVariantList> &data,
                                                            const Args& ... args)
    {
        return m_processorPrivate->manipulator.setColumns(tableName, data, args...);
    }

private:
    std::unique_ptr<ProcessorPrivate> m_processorPrivate;
};
}
