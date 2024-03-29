#ifndef ABSTRACTHISTORYSOURCE_H
#define ABSTRACTHISTORYSOURCE_H

#include <QList>
#include <QString>
#include "Candle.h"
#include "Period.h"
#include "SharedPeriod.h"

/**
 * @brief The AbstractHistorySource class
 *
 * history source interface
 */
class AbstractHistorySource {
public:
    /**
     * @brief listTickers
     * @return QList<QString> - list of names of tickets presented in the history
     */
    virtual QList<QString> listTickers() const = 0;

    /**
     * @brief listSource list candles from primary data
     * @param ticket - ticket name
     * @param begin - earliest QDateTime period
     * @param end - latest QDateTime period
     * @return list of candles with source type
     * @note The list and it's contents must be freed by the caller
     */
    virtual QList<Candle> listSource(const QString ticket,
                                     const QDateTime begin,
                                     const QDateTime end) const = 0;
    /**
     * @brief listCandles list candles of given time period
     * @param ticket - QString, name of the ticket
     * @param period - Period instance
     * @param begin -  earliest QDateTime of period
     * @param end - latest QDateTime of period
     * @return pointer to list of pointers to \ref Candle
     * @note returned pointer and it's contents must be freed by the caller
     */
    virtual QList<Candle> listCandles(const QString ticket,
                                      const Period period,
                                      const QDateTime begin,
                                      const QDateTime end) const = 0;

};

#endif // ABSTRACTHISTORYSOURCE_H
