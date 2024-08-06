#include<stdio.h>
#include<math.h>
#include <stdbool.h>

/*
Proszę napisać funkcję, która wczytuje z klawiatury trzy liczby całkowite, które oznaczają
dzień, miesiąc i rok, a następnie sprawdza czy to jest poprawna data. Proszę uwzględnić ilość
dni w poszczególnych miesiącach (1…31 w styczniu, 1…28 w lutym w roku zwykłym, 1…29
w lutym w roku przestępnym, 1…31 w marcu, 1…30 w kwietniu itd.)
Uwzględnić lata przestępne. Przyjąć, że rok nie jest przestępny (rok zwykły) jeśli:
 - nie dzieli się przez 4
 - lub dzieli się przez 100, ale nie dzieli się przez 400.
 (np. lata zwykłe: 1700, 1800, 2100; lata przestępne: 4, 1600, 1996, 2000, 2400).
W szczególności data 29-02-1800 r. nie jest datą poprawną. 
*/

bool is_year_leap(int year){
    if(year%4 != 0 || (year%100 == 0 && year%400 != 0)){
        return false;
    }
    else return true;
}

bool is_date_correct(int day, int month, int year){
    if((month == 1 || month ==3 || month ==5 || month ==7 || month ==8 || month ==10 || month ==12) && day > 31){
        return false;
    }
    else if((month == 4 || month ==6 || month ==9 || month ==11 ) && day > 30){
    return false;
    }
    else if (month ==2 && is_year_leap(year) && day > 29){
        return false;
    }
    else if (month ==2 && day > 28)
    {
        return false;
    }
    else return true;    
}

int main(void)
{
    unsigned int d,m,y;

    printf("Podaj dzien:");
    scanf("%d", &d);
    printf("Podaj miesiac:");
    scanf("%d", &m);
    printf("Podaj rok:");
    scanf("%d", &y);

    printf("Podana data: %d:%d:%d\n ",d,m,y);

    if(is_date_correct(d,m,y)){
        printf("Data poprawna\n");
    }
    else{
        printf("Data niepoprawna\n");
    }
    return 0;
}
