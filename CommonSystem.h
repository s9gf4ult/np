#ifndef COMMONSYSTEM_H
#define COMMONSYSTEM_H

#include <QObject>
#include <QList>
#include <QString>
#include <QDateTime>
#include "Candle.h"

/**Common interface to trading system, all implementations must be inherited
 * from this class.
 *
 * Instance of successor must be translated to \ref CommonBot successor
 */
class CommonSystem : QObject {
  Q_OBJECT
  public:
  /**Return list of tickets.
   * Each ticket is just a name as QString.
   *
   * \note
   * QList must be destroyed by caller
   */
  virtual QList<QString> & getTicketsList() = 0;
  
  /**Return list of candles
   *
   * \param ticket The name of ticket
   * \param period The Period description
   * \param begin The datetime of the begining of the range of candles to return
   * \param end The datetime of the end of range
   * \note
   * returned QList must be destroyed by caller
   */
  virtual QList<Candle> & getCandles(const QString &ticket, const TimePeriod &period, const QDateTime &begin, const QDateTime &end) = 0;

  /**Subscribe to changes of concrete ticket
   */
  virtual void subscribe(const QString &) = 0;

  /**Unsubscribe to changes of the ticket
   */
  virtual void unsubscribe(const QString &) = 0;

  /**Get list of subscipted tickets
   *
   * \note
   * QList must be destroyed by caller
   */
  virtual QList<QString> & getSubscripted() = 0;
};
  

#endif
