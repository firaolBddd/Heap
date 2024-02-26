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


void print(int* table);
void print(int* table){//Print the array
  for(int i = 0; i < 100; i++){
    cout << table[i] <<  endl;
  }
}






void doublecheck(int* table, int curr);
void doublecheck(int* table, int curr) {
if(table[right(Curr)-1] >= table[left(curr)-1] && table[right(curr)-1] > table[curr-1]){
int temp = table[curr-1];
table[curr-1] = table[right(curr)-1];
table[right(curr)-1] = temp;
doublecheck(table, right(curr));
return;
}
 if(table[left(curr)-1] > table[right(curr)-1] && table[left(curr)-1] > table[curr-1]){//If left is greater than the parent and right
    //Switch and call check on the new child
    int temp = table[curr-1];
    table[curr-1] = table[left(curr)-1];
    table[left(curr)-1] = temp;
    doublecheck(table, left(curr));
    return;
  }
}

void remove(int* table, int size);
void remove(int* table, int size){//Use iteration to print all the values
  while(size != 0){//While there is numbers in the array
    cout << table[0] << " ";//Print the root of the tree
    table[0] = table[size - 1];//Switch the root with the last number in the array
    table[size - 1] = -1;
    rcheck(table, 1);//Check if the new root needs to be switched
    size = size - 1;
  }
}

void youadd(int* table, int &curr);
void youadd(int* table, int &curr){
cout<< "what number you wanna add from 1 - 1000" << endl;
int input;
cin >> input;
cin.clear();
table[curr] = input;
check(table, curr);
curr++;
}

int main(){
 srand(time(0));
  bool quit = false;//bool to check when user wants to quit
  int* table = new int[100];//Create intial table
  int curr = 0;//Create original index
  for(int i = 0; i < 100; i++){//Set all values to -1
    table[i] = -1;
  }
while(!quit){
cout<< "type one of the commands - youadd, print, remove, doublecheck, add" << endl;
char input[
