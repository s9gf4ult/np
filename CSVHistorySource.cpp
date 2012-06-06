#include "CSVHistorySource.h"
#include <QList>
#include <QString>

CSVHistorySource::CSVHistorySource()
{
}

QList<QString> CSVHistorySource::listTickers() const
{
    return QList<QString>();
}

QList<QString> CSVHistorySource::listTickers(const QString &search) const
{
    return QList<QString>();
}

QList<AbstractCandle *> CSVHistorySource::listSource(const QString &ticket, const QDateTime &begin, const QDateTime &end) const
{
    return QList<AbstractCandle *>();
}

QList<SimpleCandle *> CSVHistorySource::listCandles(const QString &ticket, TimePeriod *period, const QDateTime &begin, const QDateTime &end) const
{
    return QList<SimpleCandle *>();
}

CSVHistorySource &CSVHistorySource::setFilename(const QString &filename)
{
    return *this;
}

const QString CSVHistorySource::getFilename() const
{
    return QString();
}

