#include <QCoreApplication>
#include <string>
#include "parser.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);  
    auto z = parser::parse("q1[a]2[b]1[c]");
    return a.exec();
}


