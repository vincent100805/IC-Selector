#include <stdio.h>
#include <string.h>

struct IC {
    char name[10];
    char type[20];
    char subtype[20];
    char logicFamily[10];
    float vcc;
};

int main() {
    struct IC icList[] = {
        {"74LS74", "FlipFlop", "D", "TTL", 5.0},
        {"74HC74", "FlipFlop", "D", "CMOS", 5.0},
        {"74HC00", "Gate", "NAND", "CMOS", 5.0},
        {"74LS138", "Decoder", "3-to-8", "TTL", 5.0},
        {"74HC161", "Counter", "Binary", "CMOS", 5.0}
    };
    int n = 5;

    char desiredType[20], desiredSubtype[20], desiredLogic[10];
    printf("Enter circuit type (e.g., FlipFlop, Gate, Decoder, Counter): ");
    scanf("%s", desiredType);
    printf("Enter subtype (e.g., D, NAND, 3-to-8, Binary): ");
    scanf("%s", desiredSubtype);
    printf("Enter logic family (TTL or CMOS): ");
    scanf("%s", desiredLogic);

    printf("\nRecommended ICs:\n");
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcasecmp(icList[i].type, desiredType) == 0 &&
            strcasecmp(icList[i].subtype, desiredSubtype) == 0 &&
            strcasecmp(icList[i].logicFamily, desiredLogic) == 0) {
            printf(" - %s\n", icList[i].name);
            found = 1;
            }
    }

    if (!found) printf("No matching ICs found.\n");

    return 0;
}
