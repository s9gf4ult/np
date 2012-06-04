#ifndef CANDLEVISITOR_H
#define CANDLEVISITOR_H

class Candle;
class Tick;

class CandleVisitor {
public:
    virtual void visit(Candle *) = 0;
    virtual void visit(Tick *) = 0;
};

#endif // CANDLEVISITOR_H
