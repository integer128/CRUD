#include <iostream>
#include <QString>
#include <QVariantList>
#include <tuple>

#include "src/processor.h"

int main()
{
    CRUD::Processor* dbProcessor {new CRUD::Processor()};

//    auto [result, resultVector] = dbProcessor->getColumns("Student_Data", "Login_", "Password_", "Points_");

//    for (auto i : resultVector)
//    {
//        for (auto j : i)
//        {
//            std::cout << j.toString().toStdString() << " ";
//        }
//        std::cout << std::endl;
//    }

    std::vector<QVariantList> vector {{"Test11", "Test12", "Test13"},
                                      {"Test21", "Test22", "Test23"},
                                      {"Test31", "Test32", "Test33"}};
    dbProcessor->setColumns("Student_Data", vector, "Login_", "Password_", "Points_");

    return 0;
}
