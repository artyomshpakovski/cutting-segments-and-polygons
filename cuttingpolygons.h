#ifndef CUTTINGPOLYGONS_H
#define CUTTINGPOLYGONS_H

#include <QWidget>
#include "qcustomplot.h"
QT_BEGIN_NAMESPACE
namespace Ui { class CuttingPolygons; }
QT_END_NAMESPACE

class CuttingPolygons : public QWidget
{
    Q_OBJECT

public:
    CuttingPolygons(QWidget *parent = nullptr);
    ~CuttingPolygons();

private:
    int currentGraph;
    QVector<QPointF> polygon;

    QVector<int> xCoord;
    QVector<int> yCoord;

    Ui::CuttingPolygons *ui;
    QCustomPlot *wgt;

    QHBoxLayout *mainLayout;
    QGroupBox *algorithms;
    QGroupBox *data;

    QRadioButton *midpointRadBt;
    QRadioButton *convexRadBt;

    QLabel *mainAlgorithmLbl;
    QLabel *mainDataLbl;
    double Xmin;
    double Xmax;
    double Ymin;
    double Ymax;
    QVector<QPointF> cutPolygon(QVector<QPointF>);
    int getCode(QPointF);
    QPointF intersectionPoint(QPointF P1, QPointF P2, int border = -1);

    QPushButton *dataBt;
    int getCode(double x, double y, double Xmin, double Ymin, double Xmax, double Ymax);
private slots:
    bool intersection(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
    void drawPlot();
    void midpointAlgorithm(double x1, double y1, double x2, double y2, double xmin, double ymin, double xmax, double ymax);

};
#endif // CUTTINGPOLYGONS_H
