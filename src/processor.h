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

    std::pair<RESULT, std::vector<QVariantList> > requestTableData(TABLES table);

private:
    std::unique_ptr<ProcessorPrivate> m_processorPrivate;
};
}
