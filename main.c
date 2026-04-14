#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned int id;
    char nama[100];
    char merek[100];
    char model[100];
    unsigned int tahun;
    unsigned int jumlah;
} AlatLab;

typedef struct {
    char username[50];
    unsigned int id_alat;
} Peminjaman;

int login(char *username, char *password, char *role);
void menuAdmin();
void menuUser(char *username);

int main(int argc, char *argv[]) {
    printf("  sistem pinjam laboratoruim\n");
    
    if (argc != 3) {
        printf(" %s <username> <password>\n", argv[0]);
        printf(" %s admin admin123\n", argv[0]);
        return 1;
    }
    
    char *username = argv[1];
    char *password = argv[2];
    char role[10];
    
    if (login(username, password, role) == 1) {
        printf("\n login berhasil!\n");
        printf("Selamat datang, %s!\n", username);
        printf("Role: %s\n", role);
        
        
        if (strcmp(role, "admin") == 0) {
            menuAdmin();
        } else {
            menuUser(username);
        }
    } else {
        printf("\n login gagal!\n");
        printf("Username atau password salah!\n");
        return 1;
    }
    
    return 0;
}
