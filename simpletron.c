#include <stdio.h>

//language contraints
#define MAXWORDVALUE 9999
#define MINWORDVALUE -9999
#define MEMORYSIZE 100

//opcodes
//input - output
#define READ 10 //read from input and store in operand location
#define WRITE 11 //read from operand location and write in output
//loading/store memory
#define LOAD 20 //copy word from operand location to accumulator
#define STORE 21 //copy word from accumulator to operand location
//arithmetic operation
#define ADD 30 //add word from operand location to accumulator
#define SUBTRACT 31 //subtract word from operand location to accumulator
#define DIVIDE 32 //divide word from operand location to accumulator
#define MULTIPLY 33 //multiply word from operand location to accumulator
//control flow
#define BRANCH 40 //jump to instruction pointed by operand
#define BRANCHNEG 41 //if accumulator is negative then jump to instruction pointed by operand
#define BRANCHZERO 42 //if accumulator is zero then jump to instruction pointed by operand
#define HALT 43 //exit signal

void startupmsg();
void load();
void execute();
void dump();
void initmemory(int []);

int main(int argc, char * argv[]){
  int memory[MEMORYSIZE];
  int accumulator = 0; //accumulator register
  int instructionCounter = 0; //instruction pointer
  int instructionRegister = 0;
  int operationCode = 0;
  int operand = 0;
  startupmsg();
  initmemory(memory);
  instructionRegister = memory[instructionCounter];
  load();
  execute();
  dump();
  return 0;
}

void startupmsg(){
   printf("*** Welcome to Simpletron! ***\n");
   printf("*** Please enter your program one instruction ***\n");
   printf("*** (or data word) at a time. I will type the ***\n");
   printf("*** location number and a question mark (?).  ***\n");
   printf("*** You then type the word for that location. ***\n");
   printf("*** Type the sentinel -99999 to stop entering ***\n");
   printf("*** your program. ***\n");
}

void initmemory(int memory[]){
  for(int i=0; i<MEMORYSIZE;i++){
    memory[i] = 0;
  }
}

void load(){
  //load code in memory
}

void execute(){
  //execute the loaded code in memory
}

void dump(){
  //dump memory and registers
}
