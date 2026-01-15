#include <stdio.h>

int determine(int a, int b, int c) {
    // Store all three numbers in an array for easy iteration
    int arr[3] = {a, b, c};
    
    // Initialize largest with the first element
    int largest = arr[0];

    // Loop through remaining elements and find the maximum
    for(int i = 1; i < 3; i++) {
        if(arr[i] > largest) {
            largest = arr[i];
        }
    }
    
    return largest;
}

int main() {
    int a_input, b_input, c_input;
    
    // Read three space-separated integers
    scanf("%d %d %d", &a_input, &b_input, &c_input);
    
    // Call function to determine largest value
    int value = determine(a_input, b_input, c_input);
    
    // Print result with exact formatting (note the space before colon)
    printf("The largest number is : %d", value);

    return 0;
}
