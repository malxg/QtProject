#include "mainwindow.h"

#include <QApplication>
#include <QtDebug>
#include <QFile>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFile fileIn("data.txt");
    QFile fileOut("illuminance.txt");
    //打开输入文件，只读方式
    if(!fileIn.open(QIODevice::ReadOnly))
    {
        qDebug() << "文件打开失败！";
    }
    //打开输出文件，只写方式
    if(!fileOut.open(QIODevice::WriteOnly))
    {
        qDebug() << "文件打开失败！";
    }
    qDebug() << "文件打开成功！";
    QJsonParseError jsonParserError;
    while(!fileIn.atEnd())
    {
        QJsonDocument jsonDocument = QJsonDocument::fromJson(fileIn.readLine(), &jsonParserError);
        if (!jsonDocument.isNull() && jsonParserError.error == QJsonParseError::NoError )//error!=QJsonParseError::NoError判断文件是否完整
        {
            if(jsonDocument.isObject())
            {
                QJsonObject jsonObject = jsonDocument.object();
                if(jsonObject.contains("actioncode") && (jsonObject.value( "actioncode" ) == "illuminanceReturn"))
                {
                    //解析postdata的值，也是一个Json对象
                    QJsonValue postdataValue = jsonObject.value("postdata");
                    QJsonObject postdataObject = postdataValue.toObject();
                    //构建自定的Json数据
                    QJsonObject json;
                    json.insert("messageclass", "sensorData");

                    json.insert("actioncode", jsonObject.value("actioncode"));

                    json.insert("deviceID", postdataObject.value("sensorID"));
                    json.insert("typeID", postdataObject.value("groupID"));
                    json.insert("illuminance", postdataObject.value("illuminance"));
                    json.insert("voletage", postdataObject.value("voletage"));
                    json.insert("timestamp", postdataObject.value("timestamp"));
                    QJsonDocument outDocument;
                    outDocument.setObject(json);
                    //QJsonDocument::Compact //输出的Json文件为紧凑型
                    //QJsonDocument::Indented //输出的Json文件为松散型 （默认）
                    //fileOut.write(outDocument.toJson(QJsonDocument::Compact)); //输出的Json文件为紧凑型
                    fileOut.write(outDocument.toJson(QJsonDocument::Indented)); //输出的Json文件为松散型
                    fileOut.write("\n");
                }
            }
        }
    }

    fileOut.close();
    fileIn.close();
    return a.exec();
}
