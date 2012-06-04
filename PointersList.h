#ifndef POINTERSLIST_H
#define POINTERSLIST_H

template<class T>
class PointersList : public QList<T *> {
public:
    virtual ~PointersList() {
        for(typename PointersList<T>::const_iterator it = this->begin(); it != this->end(); ++it) {
            delete *it;
        }
    }
};

#endif // POINTERSLIST_H
