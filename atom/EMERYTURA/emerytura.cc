#include <iostream>
//#include <windows.h>
using namespace std;

int main(){

  double sum = 10000;
  int years = 45;
  int monthSave = 600;
  double interest = 0.018;
  //-------------------------------
  int months = 12;
  double rawsum = sum;
  double percent = 0.0;


  for(int i=0; i<months*years; i++){

    sum += monthSave;
    rawsum += monthSave; 
    percent = sum*(interest/months);
    sum += percent;

  }
  
  cout <<"# lat oszczedzania:\t"<< years<< endl;
  cout <<"miesiecznie odkladane:\t"<< monthSave <<endl;
  cout <<"oprocentowanie:\t\t"<< interest*100<<"%"<<endl;
  cout <<"Uzbierana suma:\t\t"<< sum << endl;
  cout <<"Z oprocentowaniem 0:\t"<< rawsum << endl;
  cout <<"Zysk:\t\t\t"<< sum-rawsum << endl;
  cout <<"+1000zl do pensji przez:\t" <<(sum/1000)/months <<" lat"<< endl;

//  Sleep(100000);
  return 0;
}
