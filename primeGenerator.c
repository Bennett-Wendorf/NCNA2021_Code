#include <stdio.h>
#include <stdlib.h>

void genPrimes(int numPrimes, long* primesArray);
void writeToFile(FILE* outputFile, int numPrimes, long* primesArray);

int main(int argc, char** argv){

    FILE* outputFile = fopen("./primes.out", "w");
    if(outputFile == NULL){
        perror("Could not open output file.");
        exit(-1);
    }

    int numPrimes = 0;
    long* primesArray;
    if(argc > 1){
        if(sscanf(argv[1], "%i", &numPrimes) != 1){
            perror("Input is not formatted correctly. Please try again with an integer greater than 0.");
            exit(-1);
        }
    } else {
        printf("Not enough arguments provided.");
        exit(-1);
    }

    primesArray = (long*) malloc(sizeof(long)*numPrimes);
    if(primesArray == NULL){
        perror("Could not alloc mem for the primes array.");
        exit(-1);
    }

    genPrimes(numPrimes, primesArray);
    writeToFile(outputFile, numPrimes, primesArray);

    if(fclose(outputFile) == EOF){
        perror("The output file could not be closed.");
        exit(-1);

    }
}

void genPrimes(int numPrimes, long* primesArray){
    int currPrimes = 0;
    int currNumber = 2;
    int i;
    while(currPrimes < numPrimes){
        printf("Checking %d\n", currNumber);
        for(i = 2; i < currNumber; i++){
            if(currNumber%i==0){
                break;
            }
        }
        if(i == currNumber){
            // Then we got through the entire loop, and currNumber is a prime
            primesArray[currPrimes] = currNumber;
            currPrimes++;
        }
        currNumber++;
    }
}

void writeToFile(FILE* outputFile, int numPrimes, long* primesArray){
    int i;
    for(i = 0; i < numPrimes; i++){
        fprintf(outputFile, "%ld\n", primesArray[i]);
    }
}