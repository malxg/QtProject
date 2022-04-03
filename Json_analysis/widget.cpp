//#include "widget.h"
//#include <QDebug>


//#include <qapplication.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include "dlog.h"
//void customMessageHandler(QtMsgType type, const char *msg)
//{
//    QString txtMessage;

//    switch (type)
//    {
//        case QtDebugMsg:    //调试信息提示
//            txtMessage = QString("Debug: %1").arg(msg);
//            break;

//        case QtWarningMsg:    //一般的warning提示
//            txtMessage = QString("Warning: %1").arg(msg);
//            break;

//        case QtCriticalMsg:    //严重错误提示
//            txtMessage = QString("Critical: %1").arg(msg);
//            break;

//        case QtFatalMsg:    //致命错误提示
//            txtMessage = QString("Fatal: %1").arg(msg);
//            abort();
//    }

//    //保存输出相关信息到指定文件
//    QFile outputFile("customMessageLog.txt");
//    outputFile.open(QIODevice::WriteOnly | QIODevice::Append);
//    QTextStream textStream(&outputFile);
//    textStream << txtMessage << endl;
//}

//Widget::Widget(QWidget *parent)
//    : QWidget(parent)
//{
//    createView();
//}

//void Widget::createView()
//{
//    //logSysInit("illuminance.txt");
//    /*解析json文件*/
//   /* QFile file("json_file.txt");
//    file.open(QIODevice::ReadOnly | QIODevice::Text);
//    QString value = file.readAll();
//    file.close();

//    QJsonParseError parseJsonErr;
//    while(!file.atEnd())
//    {
//        //QJsonDocument document = QJsonDocument::fromJson(value.toUtf8(),&parseJsonErr);
//        QJsonDocument document = QJsonDocument::fromJson(file.readLine(),&parseJsonErr);
//        if(!(parseJsonErr.error == QJsonParseError::NoError))
//        {
//            qDebug()<<tr("解析json文件错误！");
//            return;
//        }

//        QJsonObject jsonObject = document.object();
//        qDebug()<<"actioncode=="<<jsonObject["actioncode"].toString();
//        qDebug()<<"GUID=="<<jsonObject["GUID"].toString();

//        if(jsonObject.contains(QStringLiteral("postdata")))
//        {
//            QJsonValue jsonValueList = jsonObject.value(QStringLiteral("postdata"));
//            QJsonObject item = jsonValueList.toObject();
//            QJsonValue t;
//            t=(item["links"].toArray())[0];
//            qDebug()<<"bs=="<<item["bs"].toString();
//            qDebug()<<"links=="<<t.toString();
//            qDebug()<<"devsn=="<<item["devsn"].toString();

//            qDebug()<<"groupID=="<<item["groupID"].toString();
//            qDebug()<<"sensorDevID=="<<item["sensorDevID"].toString();
//            qDebug()<<"sensorID=="<<item["sensorID"].toString();
//            qDebug()<<"moisture=="<<item["moisture"].toDouble();

//            qDebug()<<"temperature=="<<item["temperature"].toDouble();
//            qDebug()<<"voletage=="<<item["voletage"].toDouble();
//            qDebug()<<"timestamp=="<<item["timestamp"].toString();

//        }

//        if(jsonObject.contains(QStringLiteral("recoveryPrimaryNode")))
//        {
//            QJsonValue arrayValue = jsonObject.value(QStringLiteral("recoveryPrimaryNode"));
//            if(arrayValue.isArray())
//            {
//                QJsonArray array = arrayValue.toArray();
//                for(int i=0;i<array.size();i++)
//                {
//                    QJsonValue iconArray = array.at(i);
//                    QJsonObject icon = iconArray.toObject();
//                    QString id = icon["id"].toString();
//                    QString iconTxt = icon["iconTxt"].toString();
//                    QString iconName = icon["iconName"].toString();
//                    qDebug()<<"id="<<id<<"iconTxt="<<iconTxt<<"iconName="<<iconName;
//                }
//            }
//        }
//    }*/

//}
