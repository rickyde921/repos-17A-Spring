/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: ricardodeleon
 *
 * Created on March 2, 2016, 3:39 AM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

/*
 * 
 */


void problem1();
void problem2();
void problem3();
void problem4();
float celsius(float);
void problem5();
void problem6();
void howMany(char a[][30], int Col, int start, int end, int &c, int &s, int &r);
void swap(string names[], int start, int end);
void problem7();
void sort(string names[], int size);
int binarySearch(string names[], int size, string value);
void truthTable();
void output(bool, bool);
int main(int argc, char** argv) {

    int problem;

    bool finished = false;
    do{
        cout<<"What problem would you like to see?"<<endl;
         cout<<"Enter"<<endl
        <<"1 for problem 3.12"<<endl
        <<"2 for problem 3.13"<<endl
        <<"3 for problem 4.10"<<endl
        <<"4 for problem 5.11"<<endl
        <<"5 for problem 6.7"<<endl
        <<"6 for problem 7.6"<<endl
        <<"7 for problem 8.7"<<endl
        <<"8 for the truth table"<<endl
        <<"Anythig else to terminate the program"<<endl;
         cin>>problem;
         
         switch(problem){
                 case 1: problem1();
                 break;
                 case 2: problem2();
                 break;
                 case 3: problem3();
                 break;
                 case 4: problem4();
                 break;
                 case 5: problem5();
                 break;
                 case 6: problem6();
                 break;
                 case 7: problem7();
                 break;
                case 8: truthTable();
                break;
                 default : finished = true;
                 break;
         }
                
    } while (finished == false);
   
    return 0;
}
void problem1(){
    float far, cel;
    cout<<"Enter the degrees in Celsius"<<endl;
    cin>>cel;
    far = ((9.0/5.0)*cel) + 32;
    cout<<cel<<" celsius = "<<far<<" fahrenhiet"<<endl;
}
void problem2(){
    const float YEN_PER_DOLLAR  = 114.06;
    const float EUROS_PER_DOLLAR = 0.92;
    float dollars;
    cout<<"Enter the amount of dollars you would like to convert"<<endl;
    cin>>dollars;
    float yen, euro;
    yen = dollars * YEN_PER_DOLLAR;
    euro = dollars * EUROS_PER_DOLLAR;
    cout<<dollars<<" dollars is equivalent to "<<yen<<" yen and "<<euro<<" euros"<<endl;
}
void problem3(){
    int month, year;
    bool proper = false;
    do {
      cout<<"Please enter a month"<<endl;
      cin>>month;
      if(month > 0 && month < 13)proper = true;
      else cout<<"Improper month entered "<<endl;
    } while (proper == false);
    proper = false;
    do {
      cout<<"Please enter a year"<<endl;
      cin>>year;
      if(year > 0 )proper = true;
      else cout<<"Improper year entered "<<endl;
    } while (proper == false);
    
    bool isLeapYear;
    
    if(year % 100 == 0){
        if(year % 400 == 0)isLeapYear = true;
        else isLeapYear = false;
    }
    else if (year % 4 == 0)isLeapYear = true;
    else isLeapYear = false;
    
    int days;
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
        days = 31;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)days = 30;
    else if (month == 2){
        if(isLeapYear)days = 29;
        else days = 28;
    }
    else cout<<"error"<<endl;
    
    cout<<"Your month has "<<days<<" days"<<endl;
}

void problem4(){
    
    bool proper;
    int population;
    float rate;
    int days;
    int startPop;
    do {
        cout<<"Please enter your starting size population"<<endl;
        cin>>population;
        if(population < 2)cout<<"Please enter a number bigger than 1"<<endl;
        else proper = true;
    } while (proper == false);
        
    proper = false;
    do {
        cout<<"Please enter the averge daily increase (as a percentage)"<<endl;
        cin>>rate;
        if(population < 0)cout<<"Please enter a number bigger than 1"<<endl;
        else proper = true;
    } while (proper == false);
    proper = false;
        do {
        cout<<"Please enter the number of days they will grow for"<<endl;
        cin>>days;
        if(population < 1)cout<<"Please enter a number bigger than 0"<<endl;
        else proper = true;
    } while (proper == false);
    
    //calculate population
    float newPop;
    startPop = population;
    for (int i = 0; i<days; i++){
        newPop = population * rate;
        population = newPop;
    }
    
    cout<<"Your "<<startPop<<" organisms have multiplied into "<<population<<" after "<<days<<" days"<<endl;
}

float celsius(float far){
    float celc = 5.0/9.0;
    celc *= (far - 32);
    return celc;
    
}
void problem5(){
    int far = 0;
    for (int i = 0; i<21; i++){
        cout<<"Fahrenheit: "<<i<<"   =   "<<"Celsius: "<<celsius(far)<<endl;
        far++;
    }
}
void problem6(){
    int COL = 30;   //for 30 days
    char array[3][30];
    fstream openFile;
    string name = "RainOrShine.txt";
    openFile.open(name, ios::in);
    char read;
    for (int i = 0; i<3; i++){
        for (int j = 0; j<COL; j++){
            openFile>>read;
            array[i][j] = read;
        }
    }
    openFile.close();
    
    int rain=0, sun=0, cloud=0;
    //determine stats for the month of June
    howMany(array, COL, 0, 0, cloud, sun, rain);
    cout<<"The month of June had "<<cloud<<" cloudy days, "<<sun<<" sunny days, and "<<rain<<" rainy days"<<endl;
    //determine stats for the month of July
    cloud = 0;
    rain = 0;
    sun = 0;
    howMany(array, COL, 1, 1, cloud, sun, rain);
    cout<<"The month of July had "<<cloud<<" cloudy days, "<<sun<<" sunny days, and "<<rain<<" rainy days"<<endl;        
     //determine stats for the month of August
    cloud = 0;
    rain = 0;
    sun = 0;
    howMany(array, COL, 2, 2, cloud, sun, rain);
    cout<<"The month of August had "<<cloud<<" cloudy days, "<<sun<<" sunny days, and "<<rain<<" rainy days"<<endl;    
    
    //determine totals
    cloud = 0;
    rain = 0;
    sun = 0;
    howMany(array, COL, 0, 2, cloud, sun, rain);
   cout<<"All three months combined had "<<cloud<<" cloudy days, "<<sun<<" sunny days, and "<<rain<<" rainy days"<<endl;   
}
void howMany(char a[][30], int Col, int start, int end, int &c, int &s, int &r){
    if(start == end){   //if only one row will be read
        for (int i = 0; i<Col; i++){
            if(a[start][i] == 'c')c++;
            if(a[start][i] == 'r')r++;
            if(a[start][i] == 's')s++;
        }
    }
    else {  //if all array must be read
        for (int i = 0; i<3; i++){
            for (int j = 0; j<Col; j++){
            if(a[i][j] == 'c')c++;
            if(a[i][j] == 'r')r++;
            if(a[i][j] == 's')s++;
            }
        }
    }
}
void problem7(){
    const int NUM_NAMES = 20;
string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
"Griffin, Jim", "Stamey, Marty", "Rose, Geri", "Taylor, Terri", "Johnson, Jill",
"Allison, Jeff", "Looney, Joe", "Wolfe, Bill", "James, Jean", "Weaver, Jim", "Pore, Bob", "Rutherford, Greg", "Javens, Renee", "Harrison, Rose", "Setzer, Cathy",
"Pike, Gordon", "Holland, Beth" };

sort(names, NUM_NAMES);
cout<<"Enter a name you would like to look for"<<endl;
string name;
cin.ignore();
getline(cin, name);
int foundPos = -1;
foundPos = binarySearch(names, NUM_NAMES, name);
if(foundPos == -1)cout<<name<<" was not found within the array"<<endl;
else cout<<name<<" was found in the "<<foundPos<<" position of the sorted array"<<endl;
}
void sort(string names[], int size){
    int sortedPos = 0;
    string bestOne;
    int bestPos = -1;
    for(int i = 0; i<size; i++){
        bestOne = "zzzzzz";
        for (int j = sortedPos; j<size; j++){
            if(names[j] < bestOne){
                bestOne = names[j];
                bestPos = j;
                
            }
        }
        swap(names, sortedPos, bestPos);
        sortedPos++;
    }
    for (int i = 0; i<size; i++){
        cout<<names[i]<<endl;
    }
}
void swap(string names[], int start, int end){
    string temp = names[start];
    names[start] = names[end];
    names[end] = temp;
}

int binarySearch(string names[], int size, string value){
   
    int first = 0;
    int last = size -1;
    int middle;
    int position = -1;
    bool found = false;
    while(!found && first <= last){
        middle = (first + last) / 2;
        if(names[middle] == value){
            found = true;
            position = middle; 
           
        }
        else if (names[middle] > value){
            last = middle -1;
        }
        else first = middle + 1;
    }
    return position;
}
void truthTable(){
    bool x,y;
    
    x = true;
    y = true;
    output(x, y);
    
    x = true;
    y = false;
    output(x, y);
    
    x = false;
    y = true;
    output(x, y);
    
    x = false;
    y = false;
    output(x, y);
    
          
}
void output(bool x, bool y){
 cout<<" X =";
    if(x)cout<<"T";
    else cout<<"F";
    cout<<" Y =";
    if(y)cout<<"T";
    else cout<<"F";
    cout<<" !X =";
    if(!x)cout<<"T";
    else cout<<"F";
    cout<<" !Y =";
    if(!y)cout<<"T";
    else cout<<"F";
    cout<<" X&&Y =";
    if(x && y)cout<<"T";
    else cout<<"F";
    cout<<" X||Y =";
    if(x || y)cout<<"T";
    else cout<<"F";
    cout<<" X^Y =";
    if(x & y)cout<<"T";
    else cout<<"F";
    cout<<" X^Y^Y =";
    if(x & y & y)cout<<"T";
    else cout<<"F";
    cout<<" X^Y^X =";
    if(x & y & x)cout<<"T";
    else cout<<"F";
    cout<<" !(x||y) =";
    if(!(x || y))cout<<"T";
    else cout<<"F";
    cout<<" !X&&!Y =";
    if(!x && !y)cout<<"T";
    else cout<<"F";
    cout<<" !(X&&Y) =";
    if(!(x && y))cout<<"T";
    else cout<<"F";
    cout<<" !X||!Y=";
    if(!x || !y)cout<<"T";
    else cout<<"F";
    cout<<endl;

}