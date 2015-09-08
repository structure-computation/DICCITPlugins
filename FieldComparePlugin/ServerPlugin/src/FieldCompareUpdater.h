#ifndef FIELDCOMPAREUPDATER_H
#define FIELDCOMPAREUPDATER_H

#include <Soca/Updater.h>
class SodaClient;
class QDataStream;

/**
*/
class FieldCompareUpdater : public Updater {
protected:
    bool run( MP mp );
    virtual QString type() const { return "FieldCompareUpdater"; }
    
public:
    SodaClient *sc;
};

#endif // FIELDCOMPAREUPDATER_H
