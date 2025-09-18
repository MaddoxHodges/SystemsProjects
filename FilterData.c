#include <fcntl.h>
#include <sys/stat.h> 
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

int main() {

double Accelarr[9];


int Dataf = open("data.dat", O_RDONLY);
int Afile = open ("accl.dat", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
int Nfile = open ("angl.dat", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
int Rfile = open ("rota.dat", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);




ssize_t n;
while (( n = read(Dataf,Accelarr, sizeof(Accelarr))) == sizeof(Accelarr)){
    for (int i = 0; i<9; i++) {
    if (i == 0||i == 1||i ==2) {//goes through the whole array then writes it to the appropriate file based on it's location in the array
    if (write(Afile, &Accelarr[i], sizeof(double)) < 0) {
            perror("write accl.dat");
    }
}

    if (i == 3 || i == 4 || i == 5) {
    if (write(Rfile, &Accelarr[i], sizeof(double)) < 0) {
            perror("write rota.dat");
    } 
    
}

    if (i == 6 || i == 7 || i == 8) {
        if (write(Nfile, &Accelarr[i], sizeof(double)) < 0) {
        perror("write angl.dat");
    } 
    }
}
}//clo
printf("Data filtered successfully\n");
close(Dataf);
close(Afile);
close(Rfile);
close(Nfile);



}