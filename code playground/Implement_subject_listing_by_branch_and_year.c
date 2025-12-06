#include <stdio.h>

int main(){   
    char ch;
    printf("Enter your branch(c, e, m): ");
    scanf("%c",&ch);
    
    int year;
    printf("Enter your year: ");
    scanf("%d",&year);
    
    switch ( year ) {
        case 1: printf("Your subjects are:\n physics\n chemistry\n maths");
                break;
                
        case 2: switch( ch ) {
            case 'c': printf("Your subjects are:\n c programing\n computer organisation and architecure\n web devlopment");
                        break;
            case 'e': printf("Your subjects are:\n signal processing\n logic design\n network analisis");
                        break;
            case 'm': printf("Your subjects are:\n termodynamics\n solid mechanics\n heat transfer");
                        break;
            }
            break;
            
        case 3: switch ( ch ) {
            case 'c': printf("Your subjects are:\n object orianted programing\n dbms\n dats structures and algorithms");
                        break;
            case 'e': printf("Your subjects are:\n analog eloctronics\n embeded systems\n microcontrollers");
                        break;
            case 'm': printf("Your subjects are:\n applied mechanics\n kinematics\n mecatronics");
                        break;
            }
            break;
            
        case 4: int internship_input;
                _Bool internship;
                printf("Are you enroled in any internship(1/0): ");
                scanf("%d",&internship_input);
                internship = (internship_input != 0);
                if ( internship == 1 ) {
                    printf("Your curently enroled in an intership program");
                }
                else {
                    switch ( ch ) {
                        case 'c': printf("Your subjects are:\n operating systems\n computer networks\n computer design\n");
                                    break;
                        case 'e': printf("Your subjects are:\n VLSI design\n fiber optics\n communications\n digital eloctronics");
                                    break;
                        case 'm': printf("Your subjects are:\n mechanism of materials (mom)\n strength of materials(som)\n machine design)");
                                    break;    
                    }
                }
            break;
    }
    
    return 0;
}
