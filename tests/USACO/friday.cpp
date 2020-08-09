#include "calendar.hpp"

int main(){
	std::ifstream fin("friday.in");
	std::ofstream fout("friday.out");

    int years;
    fin >> years;

    cal::Day day(MONDAY);
    int answer[] = {0, 0, 0, 0, 0, 0, 0};

    for(int year=1900; year<1900+years; ++year){
        for(int month = 1; month <= 12; ++month){
            answer[(day+12)%7]++;
            day += cal::calGetDaysInMonth(month, year);
        }
    }

    fout << answer[6];
    for(int i=0;i<6;++i){
        fout << " " << answer[i];
    }
    fout << std::endl;

    fout.close();
}