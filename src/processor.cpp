#include "processor.h"
#include "crudmapper.h"

namespace CRUD
{
Processor::Processor()
    : m_processorPrivate(new ProcessorPrivate())
{ }

Processor::~Processor()
{

}

std::pair<RESULT, std::vector<QVariantList> > Processor::requestTableData(TABLES table)
{
    std::vector<QVariantList> result;
    RESULT resultState;
    std::tie(resultState, result) = m_processorPrivate->selector.selectAll(tableMapper.at(table));

    return { resultState, std::move(result) };
}

}
