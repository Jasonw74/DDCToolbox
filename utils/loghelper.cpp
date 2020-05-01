#include "loghelper.h"

void LogHelper::debug(const QString &log){
    write(QString("[D] %1").arg(log));
}

void LogHelper::information(const QString &log){
    write(QString("[I] %1").arg(log));
}

void LogHelper::warning(const QString &log){
    write(QString("[W] %1").arg(log));
}

void LogHelper::error(const QString &log){
    write(QString("[E] %1").arg(log));
}

void LogHelper::write(const QString& log, LoggingMode mode){
    QFile file("ui.log");
    QString formattedLog(QString("[%1] %2").arg(QTime::currentTime().toString()).arg(log));

    if(mode == LM_ALL || mode == LM_FILE){
        if (file.open(QIODevice::WriteOnly | QIODevice::Append))
            file.write(QString("%1\n").arg(formattedLog).toUtf8().constData());
        file.close();
    }
    if(mode == LM_ALL || mode == LM_STDOUT)
        qDebug().noquote().nospace() << formattedLog.toUtf8().constData();
}

void LogHelper::clear(){
    QFile file ("ui.log");
    if(file.exists())
        file.remove();
}
