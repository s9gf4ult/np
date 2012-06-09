#ifndef COMMONSYSTEM_H
#define COMMONSYSTEM_H

#include "Candle.h"
#include "Period.h"
#include <QDateTime>
#include <QList>
#include <QObject>
#include <QString>

/**Common interface to trading system, all implementations must be inherited
 * from this class.
 *
 * Instance of successor must be translated to \ref CommonBot successor
 */
class CommonSystem : QObject {
  Q_OBJECT
 public:
  /**Virtual destructor can be overwritten
   */
  virtual ~CommonSystem() {}
  
  
};
  

#endif
