#include <stdio.h>

/**
 * Calculate discounted price using percentage discount
 * @param price Original price of item
 * @param percent Discount percentage (0-100)
 * @return Final price after discount
 */
float discounted(float price, float percent) {
    float discountAmount = (price * percent) / 100;
    return price - discountAmount;
}

int main() {
    float price, percent;
    
    // Read input values
    scanf("%f %f", &price, &percent);
    
    // Calculate and display final price
    float finalPrice = discounted(price, percent);
    printf("The final price is: %f", finalPrice);
    
    return 0;
}
