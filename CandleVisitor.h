#ifndef CANDLEVISITOR_H
#define CANDLEVISITOR_H

class SimpleCandle;
class SimpleTick;

class CandleVisitor {
public:
    virtual void visit(SimpleCandle *) = 0;
    virtual void visit(SimpleTick *) = 0;
};

#endif // CANDLEVISITOR_H
