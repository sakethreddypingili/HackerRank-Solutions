#include <stdio.h>

/**
 * Stream Subjects Finder
 * Handles university curriculum lookup using exclusively Switch-Case logic.
 */
int main() {
    int year, internship;
    char branch;

    // Initial read for all scenarios
    if (scanf("%d %c", &year, &branch) != 2) {
        return 0;
    }

    switch (year) {
        case 1:
            // Year 1 has common subjects
            printf("Physics\nChemistry\nMaths");
            break;

        case 2:
            switch (branch) {
                case 'C': printf("C Programming\nComputer Organization & Architecture\nWeb Development"); break;
                case 'E': printf("Signal Processing\nLogic Design\nNetwork Analysis"); break;
                case 'M': printf("Thermodynamics\nSolid Mechanics\nHeat Transfer"); break;
                default: printf("-1");
            }
            break;

        case 3:
            switch (branch) {
                case 'C': printf("Object-oriented Programming\nDBMS\nData Structures & Algorithms"); break;
                case 'E': printf("Analog Electronics\nEmbedded Systems\nMicrocontrollers"); break;
                case 'M': printf("Applied Mechanics\nKinematics\nMechatronics"); break;
                default: printf("-1");
            }
            break;

        case 4:
            // Reading internship status only when Year is 4
            if (scanf("%d", &internship) != 1) return 0;
            switch (internship) {
                case 1:
                    printf("Enrolled into Internship Program");
                    break;
                case 0:
                    switch (branch) {
                        case 'C': printf("Operating Systems\nComputer Networks\nCompiler Design"); break;
                        case 'E': printf("VLSI Design\nFiber-optic Communication\nDigital Electronics"); break;
                        case 'M': printf("Mechanism of Materials (MOM)\nStrength of Materials (SOM)\nMachine Design"); break;
                        default: printf("-1");
                    }
                    break;
                default: printf("-1");
            }
            break;

        default:
            printf("-1");
    }

    return 0;
}
