#ifndef DATA_H
#define DATA_H

#include <stdint.h>
#include <iostream>

class Data
{
public:
    Data() = default;

    explicit Data(const short int aMin, const short int aMax);
    explicit Data( const Data &dt );


    void altera( const uint8_t dia, const uint8_t mes, const short int ano );

    void imprime() const;

    bool bissexto() const;

    inline int dia() const { return mDia; }
    inline int mes() const { return mMes; }
    inline int ano() const { return mAno; }
    inline bool isOk() const { return mbOK; }

    inline int ultimoDiaMes() const { return calcUltimoDiaMes(mes(), ano()); }

    Data& operator++();
    Data& operator++(int);

    Data& operator= (const Data &dt);

    bool operator== (const Data &dt) const { return compara( dt ) == 0;  }
    bool operator!= (const Data &dt) const { return compara( dt ) != 0;  }
    bool operator<  (const Data &dt) const { return compara( dt ) < 0;   }
    bool operator<= (const Data &dt) const { return compara( dt ) <= 0;  }
    bool operator>  (const Data &dt) const { return compara( dt ) > 0;   }
    bool operator>= (const Data &dt) const { return compara( dt ) >= 0;  }

    friend std::ostream& operator<<(std::ostream& os, const Data& dt);

private:
    uint8_t mDia = 0;
    uint8_t mMes = 0;
    short int mAno = 0;

private:
    short int mAnoMax = 9999;
    short int mAnoMin = 0;
    bool mbOK = false;

    bool validaData( const uint8_t dia, const uint8_t mes, const short int ano ) const;
    bool isBissexto( const short int ano ) const;

    int calcUltimoDiaMes( const uint8_t mes, const short int ano ) const;

    bool validaAno(const short int ano) const;
    bool validaMes(const uint8_t mes) const;
    int compara( const Data &dt ) const;
};

#endif // DATA_H
