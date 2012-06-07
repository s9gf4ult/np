#ifndef ABSTRACTHISTORYSOURCE_H
#define ABSTRACTHISTORYSOURCE_H

#include <QList>
#include <QString>
#include "SimpleCandle.h"
#include "AbstractCandle.h"
#include "TimePeriod.h"

/**
 * @brief The AbstractHistorySource class
 *
 * history source interface
 */
class AbstractHistorySource {
public:
    /**
     * @brief listTickers
     * @return QList<QString> * - pointer which must be freed by the caller
     */
    virtual QList<QString> listTickers() const = 0;

    /**
     * @brief listTickers
     * @param search - string to search ticket name
     * @return QList<QString> * - pointer which must be freed by the caller
     */
    virtual QList<QString> listTickers(const QString &search) const = 0;

    /**
     * @brief listSource list candles from primary data
     * @param ticket - ticket name
     * @param begin - earliest QDateTime period
     * @param end - latest QDateTime period
     * @return pointer to list of pointers of \ref AbstractCandle
     * @note The list and it's contents must be freed by the caller
     */
    virtual QList<AbstractCandle *> listSource(const QString &ticket,
                                                const QDateTime& begin,
                                                const QDateTime& end) const = 0;
    /**
     * @brief listCandles list candles of given time period
     * @param ticket - QString, name of the ticket
     * @param period - TimePeriod instance
     * @param begin -  earliest QDateTime of period
     * @param end - latest QDateTime of period
     * @return pointer to list of pointers to \ref Candle
     * @note returned pointer and it's contents must be freed by the caller
     */
    virtual QList<SimpleCandle *> listCandles(const QString &ticket,
                                       TimePeriod *period,
                                       const QDateTime &begin,
                                       const QDateTime &end) const = 0;

};

#endif // ABSTRACTHISTORYSOURCE_H