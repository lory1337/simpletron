#include <stdio.h>

//language contraints
#define SENTINEL -99999
#define MAXWORDVALUE 9999
#define MINWORDVALUE -9999 //a word can represent 14 bit but not 15 bit or above
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
void zerofillmemory(int []);
void load(int [], int *);
void execute(int [], int *, int *, int *, int *, int *);
void dump(int [], int *, int *, int *, int *, int *);

int main(int argc, char * argv[]){
  int memory[MEMORYSIZE];
  int accumulator = 0; //accumulator register
  int instructionCounter = 0; //instruction pointer
  int instructionRegister = 0;
  int operationCode = 0;
  int operand = 0;
  startupmsg();
  zerofillmemory(memory);
  load(memory, &instructionCounter);
  execute(memory, &accumulator, &instructionCounter, &instructionRegister, &operationCode, &operand);
  dump(memory, &accumulator, &instructionCounter, &instructionRegister, &operationCode, &operand);
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

void zerofillmemory(int memory[]){
  for(int i=0; i<MEMORYSIZE; i++)
    memory[i] = 0;
}

void load(int memory[], int * instructionCounterPtr){ //load code in memory
  int readInstruction;
  printf("%02d ? ", (*instructionCounterPtr));
  scanf("%d", &readInstruction);
  while(readInstruction!=SENTINEL){
    memory[*instructionCounterPtr] = readInstruction;
    ++(*instructionCounterPtr);
    printf("%02d ? ", (*instructionCounterPtr));
    scanf("%d", &readInstruction);
  }
  (*instructionCounterPtr) = 0;
  printf("*** Program loading completed ***\n");
}

void execute(int memory[], int *accumulatorPtr, int *instructionCounterPtr, int *instructionRegisterPtr, int *operationCodePtr, int *operandPtr){ //execute the loaded code in memory
  int tempInstructionCounter;
  printf("*** Program execution begins  ***\n");
  *instructionRegisterPtr = memory[*instructionCounterPtr];
  while(*instructionCounterPtr<MEMORYSIZE){
    *operationCodePtr = *instructionRegisterPtr / 100;
    *operandPtr = *instructionRegisterPtr % 100;
    switch(*operationCodePtr){
      case READ:{
        //not implemented yet
        break;
      }case WRITE:{
        //not implemented yet
        break;
      }case LOAD:{
        //not implemented yet
        break;
      }case STORE:{
        //not implemented yet
        break;
      }case ADD:{
        //not implemented yet
        break;
      }case SUBTRACT:{
        //not implemented yet
        break;
      }case DIVIDE:{
        //not implemented yet
        break;
      }case MULTIPLY:{
        //not implemented yet
        break;
      }case BRANCH:{
        //not implemented yet
        break;
      }case BRANCHNEG:{
        //not implemented yet
        break;
      }case BRANCHZERO:{
        //not implemented yet
        break;
      }case HALT:{
        printf("*** Simpletron execution terminated ***\n");
        tempInstructionCounter = *instructionCounterPtr;
        *instructionCounterPtr = MEMORYSIZE;
        break;
      }default:{
        printf("*** ERROR: invalid opcode! ***\n");
        tempInstructionCounter = *instructionCounterPtr;
        *instructionCounterPtr = MEMORYSIZE;
        break;
      }
    }
  }
  *instructionCounterPtr = tempInstructionCounter;
}

void dump(int memory[], int *accumulatorPtr, int *instructionCounterPtr, int *instructionRegisterPtr, int *operationCodePtr, int *operandPtr){ //dump memory and registers
  printf("REGISTERS\n");
  printf("accumulator                      %+05d\n", *accumulatorPtr);
  printf("instructionCounter                  %02d\n", *instructionCounterPtr);
  printf("instructionRegister              %+05d\n", *instructionRegisterPtr);
  printf("operationCode                       %02d\n", *operationCodePtr);
  printf("operand                             %02d\n\n", *operandPtr);
  printf("MEMORY (175 Bytes)\n");
  printf("    ");
  for(int i=0; i<10-1; i++){
    printf("%5d  ", i);
  }
  printf("%5d", 9);
  printf("\n");
  for(int i=0; i<MEMORYSIZE/10; i++){ //memory from line of 100 to matrix 10x10
    printf("%2d  ", i*10);
    for(int j=0; j<MEMORYSIZE/10-1; j++){
      printf("%+05d  ", memory[i*10+j]);
    }
    printf("%+05d\n", memory[i*10+9]);
  }
}
