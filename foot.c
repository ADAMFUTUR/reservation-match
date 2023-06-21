#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MATCHES 100
#define MAX_NAME_LENGTH 20
typedef struct date {
      int j,m,a;
      int hour;
} date ;
struct Match {
    char name[MAX_NAME_LENGTH];
    int capacity;
    int availableSeats;
    int price;   // price = 0 10dh price = 1 20 dh
    char place[30];
};

void displayMatch(struct Match match) {
    printf("Match: %s\n", match.name);
    printf("Capacité: %d\n", match.capacity);
    printf("Places disponibles: %d\n", match.availableSeats);
    printf("\n");
}

int main() {
    struct Match matches[MAX_MATCHES];
    int matchCount = 0;

    int choice;
    char searchName[MAX_NAME_LENGTH];

    do {
        printf("=== Réservation de matchs en ligne ===\n\n");
        printf("1. Ajouter un match\n");
        printf("2. Afficher tous les matchs\n");
        printf("3. Rechercher un match par nom\n");
        printf("4. Réserver une place\n");
        printf("5. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (matchCount < MAX_MATCHES) {
                    printf("Entrez le nom du match : ");
                    scanf(" %[^\n]s", matches[matchCount].name);
                    printf("Entrez la capacité du match : ");
                    scanf("%d", &matches[matchCount].capacity);
                    matches[matchCount].availableSeats = matches[matchCount].capacity;

                    matchCount++;
                    printf("Match ajouté avec succès.\n\n");
                } else {
                    printf("Nombre maximum de matchs atteint.\n\n");
                }
                break;
            case 2:
                if (matchCount > 0) {
                    printf("=== Liste des matchs ===\n\n");
                    for (int i = 0; i < matchCount; i++) {
                        displayMatch(matches[i]);
                    }
                } else {
                    printf("Aucun match disponible.\n\n");
                }
                break;
            case 3:
                if (matchCount > 0) {
                    printf("Entrez le nom du match à rechercher : ");
                    scanf(" %[^\n]s", searchName);

                    int found = 0;
                    for (int i = 0; i < matchCount; i++) {
                        if (strcmp(matches[i].name, searchName) == 0) {
                            printf("=== Match trouvé ===\n\n");
                            displayMatch(matches[i]);
                            found = 1;
                            break;
                        }
                    }

                    if (!found) {
                        printf("Match non trouvé.\n\n");
                    }
                } else {
                    printf("Aucun match disponible.\n\n");
                }
                break;
            case 4:
                if (matchCount > 0) {
                    printf("Entrez le nom du match à réserver : ");
                    scanf(" %[^\n]s", searchName);

                    int found = 0;
                    for (int i = 0; i < matchCount; i++) {
                        if (strcmp(matches[i].name, searchName) == 0) {
                            if (matches[i].availableSeats > 0) {
                                matches[i].availableSeats--;
                                printf("Place réservée avec succès.\n\n");
                            } else {
                                printf("Plus de places disponibles pour ce match.\n\n");
                            }
                            found = 1;
                            break;
                        }
                    }

                    if (!found) {
                        printf("Match non trouvé.\n\n");
                    }
                } else {
                    printf("Aucun match disponible.\n\n");
                }
                break;
            case 5:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide.\n\n");
        }
    } while (choice != 5);

    return 0;
}

