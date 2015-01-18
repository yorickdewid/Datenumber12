#include <string>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <sstream>
#include <sys/time.h>

#include "Bagger.h"

Bagger::Bagger()
{
    generateRandom();
}

Bagger::Bagger(int nDay, int nSec, int nNanoSec) :
    m_nDay(nDay),
    m_nSec(nSec),
    m_nNano(nNanoSec)
{
    generate();
}

void Bagger::generateRandom()
{
    getCurrentTime();
    generate();
}

void Bagger::generate()
{
    this->m_StrdateNumber = cycle<int>(this->m_nDay,
                                           this->m_nSec,
                                           this->m_nNano);
}

Bagger::~Bagger()
{
}

std::string Bagger::toString() const {
    return this->m_StrdateNumber;
}

template<typename T>
std::string Bagger::cycle(T nDay, T nSec, T nNanoSec)
{
    double dTime;
    ldiv_t sDiv;
	unsigned int i;
	std::stringstream ss;
	char timeName[12];

	dTime = nSec * 1E9 + nNanoSec;
	dTime = (dTime * (2821109907456)) / 86400E9;
	dTime = floor(dTime + 0.5);
	for(i=11; i>=4; i--) {
		auto auTime = floor(dTime / 36.0);
		int rem = (int)(floor(dTime - (auTime * 36.0)));
		timeName[i] = rem < 10 ? '0' + rem : 'a' + rem - 10;
		dTime = auTime;
	}

	sDiv.quot = nDay + this->m_cnDays45_70 + this->m_cnNanoTime;
	for(i=4; i--;) {
		sDiv = ldiv(sDiv.quot, 36);
		timeName[i] = sDiv.rem < 10 ? '0' + (char)sDiv.rem : 'a' + (char)sDiv.rem - 10;
	}
    ss << timeName;
	return ss.str();
}

void Bagger::getCurrentTime()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	this->m_nDay = tv.tv_sec / 86400;
	this->m_nSec = tv.tv_sec % 86400;
	this->m_nNano = tv.tv_usec * 1000;
}

std::ostream& operator<<(std::ostream& out, Bagger& cBagger)
{
    out << cBagger.m_StrdateNumber;
    return out;
}
