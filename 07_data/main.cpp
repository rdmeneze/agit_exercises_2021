#include <iostream>
#include "data.h"


using namespace std;


int main()
{
    Data dt1;

    dt1.altera(20, 12, 2021);
    if ( dt1.bissexto())
    {
        cout << "ano " << dt1.ano() << " eh bissexto" << endl;
    }
    dt1.imprime();

    dt1.altera(29, 02, 2020);
    if ( dt1.bissexto())
    {
        cout << "ano " << dt1.ano() << " eh bissexto" << endl;
    }
    dt1.imprime();

    dt1.altera(15, 07, 2020);


    for ( int i = 0; i <30; i++)
    {
        dt1++;
        dt1.imprime();
    }

    dt1++;
    dt1.imprime();

    dt1.altera(31, 12, 2021);
    if ( dt1.bissexto())
    {
        cout << "ano " << dt1.ano() << " eh bissexto" << endl;
    }
    dt1.imprime();
    dt1++;
    dt1.imprime();


    Data dt2;
    dt2.altera( 1,12,2022 );
    dt1.altera(31, 12, 2021);

    if ( dt2 == dt1 )
        cout << "dt1 == dt2" << endl;
    else if ( dt1 > dt2 )
        cout << "dt1 > dt2" << endl;
    else
        cout << "dt1 < dt2" << endl;


    // teste fail
    dt1.altera( 31, 4, 2020 );
    dt1.imprime();
}
