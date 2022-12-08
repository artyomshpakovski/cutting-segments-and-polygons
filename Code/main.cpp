#include "cuttingpolygons.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CuttingPolygons w;
    w.show();
    return a.exec();
}
