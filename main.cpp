#include <iostream>
using namespace std;
#include <cmath>

bool valid(int array[], int c) {

  for(int i = 0; i < c; i++){
    if(array[i] == array[c] || abs(c-i) == abs(array[c] - array[i]))
    return false;

  }
  return true;
}

void print(int array[]) {
  static int numOfSolutions = 0;
  cout << "SolutionNOGOTO #" << ++numOfSolutions << ": ";

  for(int i = 0; i < 8; i++){
      cout << array[i];
      }

   cout << "\n" << endl;
}

void backTrack(int array[], int &c){
  c--;
  if(c == -1){
    exit(0);
    array[c]++;
  }
}

void solve1dNoGoto(){
  int array[8] = {0};
  int c = 0;

  while (c >= 0){
    c++;
    if(c == 8){
      print(array);
      backTrack(array, c);

    }else{
      array[c] = -1;
    }

    while(c >= 0){
      array[c]++;
      if(array[c] ==8){
        backTrack(array,c);
      }else{
        if(valid(array,c))
        break;
      } 
    }
  }
  return;
}

void Solve1d(){
  int array[8];
  int c  =0;
  int i;
  int x = 0;
  array[0] = 0;
      
One: // NC
      c++;
      if (c == 8) goto print;
      array[c] = -1 ;
      
Two: //NR
      array[c]++;
      if (array[c] == 8) goto backtrack;
      for (i = 0; i < c; i++){
        if ( array[i] == array[c] || (c-i) == abs(array[c] - array[i] )) goto Two;
      }
      goto One;

backtrack: 
      c--;
      if (c == -1) return;
      goto Two;

print:
    x++;
    cout<< endl << "SolutionWITHGOTO #" << x << " "; 
     
    for (int i = 0; i < 8; i++){
    cout << array[i];
    }
    cout << endl;
    goto backtrack; 

  }

int main() {
  Solve1d();
  solve1dNoGoto();
}
