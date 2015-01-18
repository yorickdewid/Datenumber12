#ifndef BAGGER_H
#define BAGGER_H

#include <string>
#include <ostream>

class Bagger
{
public:
    Bagger();
    Bagger(int nDay, int nSec, int nNanoSec);
    virtual ~Bagger();
    template<typename T> std::string cycle(T nDay, T nSec, T nNanoSec);
    friend std::ostream& operator<<(std::ostream& out, Bagger& cBagger);
    void generate();
    void generateRandom();
    std::string toString() const;

private:
    void getCurrentTime();
    std::string m_StrdateNumber;
    static const int m_cnDays45_70 = (25 * 365 + 6);
    static const int m_cnDays1601_1970 = 134774;
    static const int m_cnNanoTime = 1446336;
    int m_nDay;
    int m_nSec;
    int m_nNano;
};

#endif // BAGGER_H
