#include <iostream>
#include <QString>
#include <QVariantList>
#include <QDebug>
#include <tuple>

#include "src/processor.h"

int main()
{
    CRUD::Processor* dbProcessor {new CRUD::Processor()};

    auto [result, resultVector] = dbProcessor->getColumns("Student_Data", "Login_", "Password_", "Points_");

    for (auto i : resultVector)
    {
        for (auto j : i)
        {
            std::cout << j.toString().toStdString() << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
