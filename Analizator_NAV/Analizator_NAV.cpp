#include <cstdlib>
#include "Analizator.h"

using namespace std;
int wybor;

int main(int argc, char* argv[])
{
    printf("Program do analizy portalu - ver 1.0- Copright A. Sie...\n");
    printf("1. Sumowanie linii z portalu ( Analizuje plik Portal.txt) \n");
    printf("2. Analizowanie portalu wraz z systemem Navision (Analizuje plik Navision.txt) \n");
    printf("Wybor:");
    scanf("%i", &wybor);
    if (wybor == 1)
    {
        Sumuj_Portal();
        printf("Sumowanie zakonczone..\n");
    };
    if (wybor == 2)
    {
        Zrob_w_chuj();
        printf("Analizowanie zakonczone..\n");

    };

    system("PAUSE");
    return EXIT_SUCCESS;
}
