#ifndef COMMONBOT_H
#define COMMONBOT_H

#include <QObject>
#include "CommonSystem.h"

/**Common bot interface
 */
class CommonBot : public QObject {
  Q_OBJECT
  public:
  /**Initializing bot with concrete trading system.
   */
  virtual void initialize(CommonSystem *) = 0;
  /**Start the bot
   */
  virtual void start() = 0;
  /**Stop the bot
   */
  virtual void stop() = 0;
};

#endif
