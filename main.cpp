#include <iostream>
#include "PentaShape.h"
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
    //TO DO Watch in pentashape wiki or google
    //Другими словами я ввел массив всех типов фигур пентамино,каждый из которых расположен в массиве 5x5 (под номерами 0...24)
    int array1 [5]={1,5,6,7,11}; //<<"X "<<"I "<<"U "<<"L "<<"Y "<<"P "<<"F "<<"V "<<"Z "<<"W "<<"T "<<"N ";
    int array2 [5]={0,1,2,3,4};
    int array3 [5]={0,5,6,7,2};
    int array4 [5]={0,1,2,3,8};
    int array5 [5]={0,1,2,3,7};
    int array6 [5]={5,10,11,6,1};
    int array7 [5]={1,5,6,7,10};
    int array8 [5]={0,1,2,7,12};
    int array9 [5]={0,1,6,16,12};
    int array10 [5]={0,1,6,7,12};
    int array11 [5]={0,1,2,6,11};
    int array12 [5]={0,5,10,11,16};

    basePantaShape BaseShape1(array1,5);
    PentaShape s1(BaseShape1,0);

    basePantaShape BaseShape2(array2,5);
    PentaShape s2(BaseShape2,1);

    basePantaShape BaseShape3(array3,5);
    PentaShape s3(BaseShape3,2);

    basePantaShape BaseShape4(array4,5);
    PentaShape s4(BaseShape4,3);

    basePantaShape BaseShape5(array5,5);
    PentaShape s5(BaseShape5,4);

    basePantaShape BaseShape6(array6,5);
    PentaShape s6(BaseShape6,5);

    basePantaShape BaseShape7(array7,5);
    PentaShape s7(BaseShape7,6);

    basePantaShape BaseShape8(array8,5);
    PentaShape s8(BaseShape8,7);

    basePantaShape BaseShape9(array9,5);
    PentaShape s9(BaseShape9,8);

    basePantaShape BaseShape10(array10,5);
    PentaShape s10(BaseShape10,9);

    basePantaShape BaseShape11(array11,5);
    PentaShape s11(BaseShape11,10);

    basePantaShape BaseShape12(array12,5);
    PentaShape s12(BaseShape12,11);

    ofstream q ("input.txt");
//Первый этап подготовки файла.72-количество столбов -12 из них- типы фигур
    int n=72;
    q<<n;
    q<<"\n";
    q<<"X "<<"I "<<"U "<<"L "<<"Y "<<"P "<<"F "<<"V "<<"Z "<<"W "<<"T "<<"N ";

    q<<"0 1 2 3 4 5 6 7 8 9 ";
    q<<"10 11 12 13 14 15 16 17 18 19 ";
    q<<"20 21 22 23 24 25 26 27 28 29 ";
    q<<"30 31 32 33 34 35 36 37 38 39 ";
    q<<"40 41 42 43 44 45 46 47 48 49 ";
    q<<"50 51 52 53 54 55 56 57 58 59 ";
    q<<"\n";

    ///*
    s1.countVariant(q,6,10);
    s2.countVariant(q,6,10);
    s3.countVariant(q,6,10);
    s4.countVariant(q,6,10);
    s5.countVariant(q,6,10);
    s6.countVariant(q,6,10);
    s7.countVariant(q,6,10);
    s8.countVariant(q,6,10);
    s9.countVariant(q,6,10);
    s10.countVariant(q,6,10);
    s11.countVariant(q,6,10);
    s12.countVariant(q,6,10);





    cout<<"The end"<<endl;
    return 0;
}
//*/

// cout<<"D" <<s1.getD()<<endl;
//cout<<"H"<<s1.getH()<<endl;
//s1.countVariant(q,6,10);
/*
     cout<<"0"<<endl;
     s7.show();
     cout<<"1"<<endl;
   //s6.replaceInCorner();
   s7.show();
    cout<<"2"<<endl;
    s7.reverseShapeHorizontal();
    s7.replaceInCorner();
    s7.show();
     cout<<"3"<<endl;
     s7.reverseShapeVertical();
     s7.replaceInCorner();
     s7.show();
      cout<<"4"<<endl;
      s7.reverseShapeHorizontal();
      s7.replaceInCorner();
      s7.show();
      // cout<<"5"<<endl;

      //  cout<<"6"<<endl;
      //   cout<<"7"<<endl;
      //    cout<<"8"<<endl;
*/
/*
 cout<<"5"<<endl;

 s7.turnRight();
 s7.replaceInCorner();
s7.show();
cout<<"6"<<endl;
s7.reverseShapeHorizontal();
s7.replaceInCorner();
s7.show();
cout<<"7"<<endl;
s7.reverseShapeVertical();
s7.replaceInCorner();
s7.show();
cout<<"8"<<endl;
s7.reverseShapeHorizontal();
s7.replaceInCorner();
s7.show();
//*/
//  s6.show();
//s7.countVariant(q,6,10);

/*
 s1.show();
 s2.show();
 s3.show();
 s4.show();
 s5.show();
 s6.show();
 s7.show();
 s8.show();
 s9.show();
 s10.show();
 s11.show();
 s12.show();

*/
