#ifndef MODELEX_H
#define MODELEX_H

#include<QMainWindow>
#include<QObject>
#include<QWidget>
#include<QAbstractTableModel>
#include<QMap>
#include<QVector>
#include<QStringList>

#include <QtDebug>
#include <QFile>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <stdio.h>
#include <string>
using namespace std;

class modelex : public QAbstractTableModel
{
public:
    explicit modelex(QObject *parent=0);
    virtual int rowCount(const QModelIndex &parent=QModelIndex()) const;
    virtual int columnCount(const QModelIndex &parent=QModelIndex()) const;
    QVariant data(const QModelIndex &index,int role) const;
    QVariant headerData(int section,Qt::Orientation orientation,int role) const;
signals:
public slots:
private:
    QVector<short> army;
    QVector<short> weaponType;
    QVector<short> dataType;

    QMap<short,QString> armyMap;
    QMap<short,QString> weaponTypeMap;
    QMap<short,QString> data_all;

    QStringList weapon;
    QStringList time;
    QStringList SensorId;
    QStringList data1;
    QStringList data2;

    QStringList header;

    void populateModel();
};

#endif // MODELEX_H
