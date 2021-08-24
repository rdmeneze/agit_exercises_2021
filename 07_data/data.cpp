#include "data.h"
#include <iostream>
#include <iomanip>

using namespace std;

Data::Data(const short int aMin, const short int aMax) : Data()
{
    mAnoMin = aMin;
    mAnoMax = aMax;
}

Data::Data(const Data &dt)
{
    if (this != &dt)
    {
        *this = dt;
    }
}

void Data::altera( const uint8_t dia, const uint8_t mes, const short int ano )
{
    mbOK = validaData(dia, mes, ano);

    if ( mbOK )
    {
        mDia = dia;
        mMes = mes;
        mAno = ano;
    }
}

bool Data::validaData(const uint8_t dia, const uint8_t mes , const short ano) const
{
    return ( (dia) && (dia <= calcUltimoDiaMes(mes, ano)) ) ? true : false;
}

bool Data::isBissexto( const short int ano ) const
{
    return (( (ano % 4 == 0) && (ano % 100 != 0) ) || ( ano % 400 == 0 ) ) ? true : false;
}

int Data::calcUltimoDiaMes(const uint8_t mes, const short ano) const
{
    if ( validaMes(mes) && validaAno(ano) )
    {
        if ( mes == 2 )
            return 28 + (int)isBissexto(ano);

        if ( mes <= 7 )
            return 30 + (int)(mes & 1);

        if ( mes >= 8 )
            return 31 - (int)(mes & 1);
    }

    return 0;
}

bool Data::validaAno(const short ano) const
{
    return ( ano >= mAnoMin && ano <= mAnoMax ) ? true : false;
}

bool Data::validaMes(const uint8_t mes) const
{
    return (mes >= 1 && mes <= 12 ) ? true : false;
}

void Data::imprime() const
{
    if ( mbOK )
    {
        cout << setw(2) << setfill('0')<< dia() << "/" << setw(2) << mes()  << "/" << ano() << endl;
    }
    else
    {
        cout << "00/00/0000" << endl;
    }
}

bool Data::bissexto() const
{
    return isBissexto( mAno );
}

Data& Data::operator++(int)
{
    const int ultimoDia = calcUltimoDiaMes( mMes, mAno );
    if ( ultimoDia )
    {
        mDia++;

        if ( mDia > ultimoDia )
        {
            mDia = 1;

            mMes++;

            if ( mMes > 12 )
            {
                mMes = 1;

                if ( mAno <= mAnoMax )
                {
                    mAno++;
                }
            }
        }
    }

    return *this;
}

Data& Data::operator=(const Data &dt)
{
    if (this != &dt)
    {
        this->mAno = dt.ano();
        this->mMes = dt.mes();
        this->mDia = dt.dia();
        this->mAnoMax = dt.mAnoMax;
        this->mAnoMin = dt.mAnoMin;
        this->mbOK = dt.mbOK;
    }

    return *this;
}

int Data::compara(const Data &dt) const
{
    if (this->ano() != dt.ano())
        return this->ano() - dt.ano();

    if ( this->mes()  != dt.mes() )
        return this->mes() - dt.mes();

    return this->dia() - dt.dia();
}


std::ostream& operator<<(std::ostream& os, const Data& dt)
{
    if (dt.isOk())
    {
        os << setw(2) << setfill('0') <<
            dt.dia() << "/" <<
            dt.mes() << "/" <<
            setw(4) << dt.ano();
    }
    else
    {
        os << "00/00/0000";
    }
    return os;
}
