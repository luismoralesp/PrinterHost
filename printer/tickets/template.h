#include <QFile>
#include <QString>
#include <QJsonObject>
#include <QJsonArray>
#include <QHash>

#ifndef TEMPLATE_H
#define TEMPLATE_H

class Template {
    public:
        Template(QString file);

        void replace(QString key, QString value);
        void replace(QJsonObject json);
        void replace(QString tag, QString key, QString value);
        void replace(QString tag, QJsonObject json);
        void replace(QString tag, QJsonArray array);
        void replaceTag(QString tag, QString value);
        QString findInTemplate(QString tagName);
        static QString findInString(QString string, QString tagName);
        QHash<QString, QString> hashInString(QString string);
        QString getResultText();
        QString getText();

    private:
        QString text;
        QString resultText;
        QString adjust(QString text, int size);
        QString read_file(QString path);

};

#endif // TEMPLATE_H
