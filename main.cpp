#include <iostream>
#include <fstream>
#include <cstring>
#include <math.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;



int right(int curr) {
return curr * 2 +1; 
}
int left(int curr){
  return curr * 2;
}
int parent(int curr){
  return (int) floor((curr+1)/2) - 1;
}

void show (int index, int* table, int depth, int size);
void show (int index, int* table, int depth, int size) {
 if(right(index) <= size && right(index) != -1) {



show(right(index), table, depth + 1, size);


}for(int i= 0; i< depth; i++) {
cout<< "\t";
}
cout<<table[index-1]<< endl;
if(left(index) <= size && left(index) != -1) {
show(left(index), table, depth + 1, size);
	}
}


void add(int* table, int &curr);
void add(int* table, int &curr){//If user wants to add using the file
  cout << "How many numbers do you want to add?" << endl;
  int ninput;
  cin >> ninput;
  cin.clear();
  for(int i = 0; i < ninput; i ++){//Create how many numbers the user wants
    fstream file("nums.txt");//Import the number file
    char input[100];
    int count = 0;
    int num = (rand() % 50) + 1;
    int n;
    char temp[100];
    //Get random number and add it to the array
    while (file.getline(input, 100, ' ')) {
      if (count == num) {
	strcpy(temp,input);
	count++;
      }
      count++;
    }
    n = atoi(temp);
    table[curr] = n;
    check(table, curr);//Check if there is a child larger than its parent
    curr++;
  }
}

void cheker(int* table, int curr);
void cheker(int* table, int curr){//Check if there is a child larger than its parent
  if(curr != 0 && table[parent(curr)] < table[curr]){//If child is greater than its parent
    //Switch values
    int temp = table[parent(curr)];
    table[parent(curr)] = table[curr];
    table[curr] = temp;
    //Call check on the new parent
    cheker(table, parent(curr));
  }
    return;
}



