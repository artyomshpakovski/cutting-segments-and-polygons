#include "cuttingpolygons.h"

CuttingPolygons::CuttingPolygons(QWidget *parent)
    : QWidget(parent)
{
    qApp->setStyle(QStyleFactory::create("Fusion"));
    setWindowTitle("Cutting Polygons Algorithms");
    setMinimumSize(600, 430);

    currentGraph = -1;


    wgt = new QCustomPlot;
    wgt->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    wgt->setInteraction(QCP::iRangeDrag,true);
    wgt->setInteraction(QCP::iRangeZoom,true);

    QFont font;
    font.setBold(true);

    mainAlgorithmLbl = new QLabel("ALGORITHMS");
    mainAlgorithmLbl->setAlignment(Qt::AlignCenter);
    mainAlgorithmLbl->setFont(font);
    mainDataLbl = new QLabel("DATA");
    mainDataLbl->setAlignment(Qt::AlignCenter);
    mainDataLbl->setFont(font);
    dataBt = new QPushButton("Get data");

    QGridLayout *dataLay = new QGridLayout;
    dataLay->addWidget(mainDataLbl, 0, 0, 1, 3);
    dataLay->addWidget(dataBt, 1, 0,1,3);

    midpointRadBt = new QRadioButton("The midpoint algorithm");
    midpointRadBt->setFont(font);
    convexRadBt = new QRadioButton("Cutting off a convex polygon");
    convexRadBt->setFont(font);

    QVBoxLayout *algorithmsLay = new QVBoxLayout;
    algorithmsLay->addWidget(mainAlgorithmLbl);
    algorithmsLay->addWidget(midpointRadBt);
    algorithmsLay->addWidget(convexRadBt);

    algorithms = new QGroupBox;
    algorithms->setLayout(algorithmsLay);
    data = new QGroupBox;
    data->setLayout(dataLay);
    data->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    QVBoxLayout *leftPart = new QVBoxLayout();
    leftPart->addWidget(algorithms);
    leftPart->addWidget(data);
    leftPart->addStretch(1);
    QVBoxLayout *rightPart = new QVBoxLayout;
    rightPart->addWidget(wgt);
    mainLayout = new QHBoxLayout(this);
    mainLayout->addLayout(leftPart);
    mainLayout->addLayout(rightPart);
    connect(dataBt, &QPushButton::clicked, this, &CuttingPolygons::drawPlot);
    midpointRadBt->setChecked(true);
}

CuttingPolygons::~CuttingPolygons()
{
}

void CuttingPolygons::drawPlot()
{
    wgt->clearGraphs();
    currentGraph = -1;
    QFileDialog *files = new QFileDialog;
    files->setWindowTitle("Откройте файл");
    QUrl file = files->getOpenFileUrl();
    QFile fileIn(file.path());
    double x1, y1, x2, y2;
    int n;
    std::vector<double> Xs;
    std::vector<double> Ys;
    fileIn.open(QIODevice::ReadOnly);
    QTextStream readStream(&fileIn);
    readStream>>n;
    if (midpointRadBt->isChecked()) {
        for(int i = 0; i < n; i++) {
            currentGraph++;
            wgt->addGraph();
            readStream>>x1>>y1>>x2>>y2;
            Xs.push_back(x1);
            Ys.push_back(y1);
            Xs.push_back(x2);
            Ys.push_back(y2);
            wgt->graph(currentGraph)->addData(x1,y1);
            wgt->graph(currentGraph)->addData(x2, y2);
        }
        readStream>>x1>>y1>>x2>>y2;
        currentGraph++;
        wgt->addGraph();
        wgt->graph(currentGraph)->setPen(QPen(Qt::red));
        wgt->graph(currentGraph)->addData(x1,y1);
        wgt->graph(currentGraph)->addData(x2,y1);
        currentGraph++;
        wgt->addGraph();
        wgt->graph(currentGraph)->setPen(QPen(Qt::red));
        wgt->graph(currentGraph)->addData(x2,y1);
        wgt->graph(currentGraph)->addData(x2,y2);
        currentGraph++;
        wgt->addGraph();
        wgt->graph(currentGraph)->setPen(QPen(Qt::red));
        wgt->graph(currentGraph)->addData(x2,y2);
        wgt->graph(currentGraph)->addData(x1,y2);
        currentGraph++;
        wgt->addGraph();
        wgt->graph(currentGraph)->setPen(QPen(Qt::red));
        wgt->graph(currentGraph)->addData(x1,y1);
        wgt->graph(currentGraph)->addData(x1,y2);
    for(int i = 0; i < 2 * n; i+=2) {
        midpointAlgorithm(Xs[i], Ys[i], Xs[i+1], Ys[i+1], x1,y1,x2,y2);
    }
    }
    else {
        for(int i = 0; i < n; i++) {
            readStream>>x1>>y1>>x2>>y2;
            Xs.push_back(x1);
            Ys.push_back(y1);
            Xs.push_back(x2);
            Ys.push_back(y2);
            wgt->addGraph();
            currentGraph++;
            wgt->graph(currentGraph)->addData(x1,y1);
            wgt->graph(currentGraph)->addData(x2, y2);
            polygon.push_back(QPointF(x1,y1));
            polygon.push_back(QPointF(x2, y2));
        }
        readStream>>x1>>y1>>x2>>y2;
        Xmin = x1;
        Ymin = y1;
        Xmax = x2;
        Ymax = y2;
        currentGraph++;
        wgt->addGraph();
        wgt->graph(currentGraph)->setPen(QPen(Qt::red));
        wgt->graph(currentGraph)->addData(x1,y1);
        wgt->graph(currentGraph)->addData(x2,y1);
        currentGraph++;
        wgt->addGraph();
        wgt->graph(currentGraph)->setPen(QPen(Qt::red));
        wgt->graph(currentGraph)->addData(x2,y1);
        wgt->graph(currentGraph)->addData(x2,y2);
        currentGraph++;
        wgt->addGraph();
        wgt->graph(currentGraph)->setPen(QPen(Qt::red));
        wgt->graph(currentGraph)->addData(x2,y2);
        wgt->graph(currentGraph)->addData(x1,y2);
        currentGraph++;
        wgt->addGraph();
        wgt->graph(currentGraph)->setPen(QPen(Qt::red));
        wgt->graph(currentGraph)->addData(x1,y1);
        wgt->graph(currentGraph)->addData(x1,y2);
        QVector<QPointF> clipPolygon = cutPolygon(polygon);
        for(int i = 0; i < clipPolygon.size() - 1; i++) {
            currentGraph++;
            wgt->addGraph();
            wgt->graph(currentGraph)->setPen(QPen(Qt::green));
            wgt->graph(currentGraph)->addData(clipPolygon[i].x(), clipPolygon[i].y());
            wgt->graph(currentGraph)->addData(clipPolygon[i+1].x(), clipPolygon[i+1].y());
        }
    }


}

void CuttingPolygons::midpointAlgorithm(double x1, double y1, double x2, double y2, double xmin, double ymin, double xmax, double ymax) {
    if (abs(x1 - x2) + abs(y1 - y2) <= pow(10, -7)) {
        return;
    }

    if (x1 <= xmax && x1 >= xmin && y1 <= ymax && y1 >= ymin && x2 <= xmax && x2 >= xmin && y2 <= ymax && y2 >= ymin) {
        currentGraph++;
        wgt->addGraph();
        wgt->graph(currentGraph)->setPen(QPen(Qt::green));
        wgt->graph(currentGraph)->addData(x1, y1);
        wgt->graph(currentGraph)->addData(x2, y2);
        qDebug()<<"здесь должна быть рисовашка";
        return;
    }

    bool temp1 = intersection(xmin, ymin, xmax, ymin, x1, y1, x2, y2);
    bool temp2 = intersection(xmax, ymin, xmax, ymax, x1, y1, x2, y2);
    bool temp3 = intersection(xmax, ymax, xmin, ymax, x1, y1, x2, y2);
    bool temp4 = intersection(xmin, ymax, xmin, ymin, x1, y1, x2, y2);

    if (!(temp1 || temp2 || temp3 || temp4)) {
        return;
    }

    midpointAlgorithm(x1,y1, (x1 + x2)/2, (y1 + y2) / 2, xmin, ymin, xmax, ymax);
    midpointAlgorithm((x1+x2)/2, (y1+y2)/2, x2,y2, xmin, ymin, xmax, ymax);
}



bool CuttingPolygons::intersection(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
    double denominator=(y4-y3)*(x1-x2)-(x4-x3)*(y1-y2);
    double numerator_a;
    double numerator_b;
    double Ua;
    double Ub;
        if (denominator == 0){
            if ( (x1*y2-x2*y1)*(x4-x3) - (x3*y4-x4*y3)*(x2-x1) == 0 && (x1*y2-x2*y1)*(y4-y3) - (x3*y4-x4*y3)*(y2-y1) == 0)
                return true;
            else false;
        }
        else{
            numerator_a=(x4-x2)*(y4-y3)-(x4-x3)*(y4-y2);
            numerator_b=(x1-x2)*(y4-y2)-(x4-x2)*(y1-y2);
            Ua=numerator_a/denominator;
            Ub=numerator_b/denominator;
            return (Ua >=0 && Ua <=1 && Ub >=0 && Ub <=1 ? true : false);
        }
}


int CuttingPolygons::getCode(QPointF point)
{
    double x = point.x();
    double y = point.y();
    int code = 0;
    if(x < Xmin)
        code += 1;
    if(x>Xmax)
        code +=2;
    if(y<Ymin)
        code +=4;
    if(y>Ymax)
        code +=8;
    return code;
}

QVector<QPointF> CuttingPolygons::cutPolygon(QVector<QPointF> polygon){
    QVector<QPointF> outputList = polygon;

    int borders[]  = {1,2,4,8};

    for(int i = 0; i<4;i++)
    {
        QVector<QPointF> inputList = outputList;
        inputList.push_back(inputList[0]);
        outputList.clear();

        for(int j = 1;j < inputList.size();j++)
        {
            QPointF currentPoint = inputList[j];
            QPointF prevPoint = inputList[j-1];

            int PrevP_code = getCode(prevPoint), curP_code = getCode(currentPoint);
            if(!(curP_code & borders[i]))
            {
                if(PrevP_code & borders[i])
                    outputList.push_back(intersectionPoint(prevPoint,currentPoint,borders[i]));
                outputList.push_back(currentPoint);
            }
            else if(!(PrevP_code & borders[i]))
                outputList.push_back(intersectionPoint(currentPoint,prevPoint,borders[i]));
        }

    }
    outputList.push_back(outputList[0]);
    return outputList;


}

QPointF CuttingPolygons::intersectionPoint(QPointF P1, QPointF P2, int border){

    int P1_code = getCode(P1);

    QPointF intersectionPoint;
    if ((border ==  8) || ( border == -1 && (P1_code & 8)))
        intersectionPoint = QPointF(P1.x() + (P2.x()- P1.x()) * (Ymax - P1.y()) / (P2.y() - P1.y()),Ymax);
    else if ((border ==  4) || ( border == -1 && (P1_code & 4)))
        intersectionPoint = QPointF(P1.x() + (P2.x()- P1.x()) * (Ymin - P1.y()) / (P2.y() - P1.y()),Ymin);
    else if ((border ==  2) || ( border == -1 && (P1_code & 2)))
        intersectionPoint = QPointF(Xmax,P1.y() + (P2.y()- P1.y()) * (Xmax - P1.x()) / (P2.x() - P1.x()));
    else if ((border ==  1) || ( border == -1 && (P1_code & 1)))
        intersectionPoint = QPointF(Xmin,P1.y() + (P2.y()- P1.y()) * (Xmin - P1.x()) / (P2.x() - P1.x()));
    return intersectionPoint;
}



