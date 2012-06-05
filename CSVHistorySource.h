#ifndef CSVHISTORYSOURCE_H
#define CSVHISTORYSOURCE_H

#include "AbstractHistorySource.h"
#include <QString>
#include <QList>

class CSVHistorySource : public AbstractHistorySource
{
public:
    CSVHistorySource();

    virtual QList<QString> *listTickers() const;
    virtual QList<QString> *listTickers(const QSTring &search) const;
    virtual QList<AbstractCandle *> *listSource(const QString &ticket, const QDateTime &begin, const QDateTime &end) const;
    virtual QList<Candle *> *listCandles(const QString &ticket, TimePeriod *period, const QDateTime &begin, const QDateTime &end) const;
    virtual CSVHistorySource &setFilename(const QString &filename);
    virtual const QString &getFilename() const;
protected:
    QString Filename;
};

#endif // CSVHISTORYSOURCE_H
