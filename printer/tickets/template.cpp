#include "template.h"
#include <iostream>
#include <QTextStream>
#include <QDebug>
#include <QRegExp>
#include <QDir>
#include "printer/constantes.h"

Template::Template(QString file){

    this->text = read_file(file);
    this->resultText = this->text;
}

QString Template::findInTemplate(QString tagName){
    QString exp = "\\[" + tagName + "\\](.+)\\[/" + tagName + "\\]";

    QRegExp regexp(exp);
    regexp.indexIn(this->resultText);
    return regexp.capturedTexts()[1];
}

QString Template::findInString(QString string, QString tagName){
    QString exp = "\\[" + tagName + "\\](.+)\\[/" + tagName + "\\]";
    QRegExp regexp(exp);
    regexp.indexIn(string);
    return regexp.capturedTexts()[1];
}

QHash<QString, QString> Template::hashInString(QString string){
    QString exp = "\\[\\w+\\](.+)\\[/\\w+\\]";
    QRegExp regexp(exp);
    regexp.indexIn(string);
    QStringList caps = regexp.capturedTexts();
    QHash<QString, QString> hash;
    /*for (int i = 1; i < caps.length(); i++){
        hash[];
    }
    return [1];*/
}

void Template::replace(QString key, QString value){
    QString rkey = "\\{(" + key + ") z=(\\d+)\\}";
    QRegExp regex(rkey);
    int pos = 0;
    while ((pos = regex.indexIn(this->resultText,pos)) !=-1){
        int s = regex.cap(2).toInt();
        if(s>0){
            value = this->adjust(value,s);
        }
        pos += regex.matchedLength();
    }
    this->resultText = this->resultText.replace(regex, value);
}

void Template::replace(QJsonObject json){
    QStringList keys = json.keys();

    for (QStringList::iterator it = keys.begin(); it != keys.end(); it++){
        QString current = *it;
        QString rkey = current;
        if (json[current].isString()) {
            QString value = json[current].toString();
            this->replace(rkey, value);
        } else if(json[current].isDouble()){
            QString value = QString::number(json[current].toDouble());
            this->replace(rkey, value);
        }else if(json[current].isArray()){
            this->replace(rkey,json[current].toArray());
        }
    }
}

void Template::replace(QString tag, QString key, QString value){
    QString text = this->findInTemplate(tag);
    QString rkey = "\\{(" + key + ") z=(\\d+)\\}";
    QRegExp regex(rkey);
    int pos = 0;
    while ((pos = regex.indexIn(text,pos)) !=-1){
        int s = regex.cap(2).toInt();
        if(s>0){
            value = this->adjust(value,s);
        }
        pos += regex.matchedLength();
    }
    text = text.replace(regex, value);
    text = "[" + tag + "]" + text + "[/" + tag + "]";
    QString exp = "\\[" + tag + "\\](.+)\\[/" + tag + "\\]";
    QRegExp regexp(exp);
    this->resultText = this->resultText.replace(regexp, text);
}

void Template::replace(QString tag, QJsonObject json){
    QStringList keys = json.keys();

    for (QStringList::iterator it = keys.begin(); it != keys.end(); it++){
        QString current = *it;
        QString rkey = current;
        if (json[current].isString()) {
            QString value = json[current].toString();
            this->replace(tag,rkey, value);
        } else if(json[current].isDouble()){
            QString value = QString::number(json[current].toDouble());
            this->replace(tag,rkey, value);
        }
    }
}

void Template::replace(QString tag, QJsonArray array){
    QString text = this->findInTemplate(tag);
    while(!array.isEmpty()){
        QJsonValue val = array.first();
        this->replace(tag,val.toObject());
        array.removeFirst();
        if(!array.isEmpty()){
            QString content = this->findInTemplate(tag);
            this->replaceTag(tag,content + text);
        }
    }
}

void Template::replaceTag(QString tag, QString value){
    QString text = "[" + tag + "]" + value + "[/" + tag + "]";
    QString exp = "\\[" + tag + "\\](.+)\\[/" + tag + "\\]";
    QRegExp regexp(exp);
    this->resultText = this->resultText.replace(regexp, text);
}

QString Template::adjust(QString text, int size){
    QString res = "";
    int l = text.length();
    if(l < size){
        res = text + QString(size - l,' ');
    }else if ((l == size) || (l <= 3)){
        res += text;
    }else{
        int dif = l - size;
        QStringList split = text.split(' ');
        QStringListIterator it(split);
        while (it.hasNext()){
            QString part = it.next();
            if(res != ""){
                res += " ";
            }
            if(part.length() < 3){
                res += part;
            }else if(part.length() - dif <3){
                res += part.mid(0,3);
                dif = dif - (part.length() - 3);
            }else{
                res += part.mid(0,part.length() - dif);
                dif = 0;
            }
        }
        res = res.mid(0,res.length() - dif);
    }
    return res;
}

QString Template::getResultText(){
    return this->resultText;
}

QString Template::getText(){
    return this->text;
}

QString Template::read_file(QString path){
    QFile * file = new QFile(QDir().absoluteFilePath(path));
    if (!file->exists()){
        file = new QFile(DEFAULT_DIR + path);
    }
    if(!file->open(QIODevice::ReadOnly)) {
        //QMessageBox::information(0, "error", file.errorString());
    }
    QTextStream in(file);
    QString content = "";
    while(!in.atEnd()) {

        QString line = in.readLine();
        content += line + "\n";

    }

    file->close();
    delete file;
    return content;
}
