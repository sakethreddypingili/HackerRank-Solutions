#include <stdio.h>

/**
 * A branching adventure game using nested conditionals.
 * Each path leads to unique challenges and a final reward room.
 */

void final_room() {
    int chest;
    if (scanf("%d", &chest) == 1) {
        if (chest == 1) {
            printf("All that glitters is not gold, Game Over!\n");
        } else if (chest == 2) {
            printf("All your efforts were for nothing, Game Over!\n");
        } else if (chest == 3) {
            printf("Congratulations!! You won the treasure.\n");
        }
    }
}

int main() {
    int path;
    if (scanf("%d", &path) != 1) return 0;

    if (path == 1) {
        printf("Player chooses the Left path.\n");
        int swamp;
        scanf("%d", &swamp);
        if (swamp == 1) {
            printf("Poor choice, Game Over!\n");
        } else if (swamp == 2) {
            printf("Player found a bridge.\n");
            int bridge;
            scanf("%d", &bridge);
            if (bridge == 1) {
                printf("Player crosses the bridge safely.\n");
                final_room();
            } else {
                printf("Poor luck, Game Over!\n");
            }
        }
    } 
    else if (path == 2) {
        printf("Player chooses the Middle path.\n");
        int puzzle;
        scanf("%d", &puzzle);
        if (puzzle == 582) {
            printf("Player solved the puzzle.\n");
            final_room();
        } else {
            printf("Foolish player, Game Over!\n");
        }
    } 
    else if (path == 3) {
        printf("Player chooses the Right path.\n");
        int sequence;
        scanf("%d", &sequence);
        if (sequence == 30) {
            printf("Player solved the puzzle.\n");
            final_room();
        } else {
            printf("Foolish player, Game Over!\n");
        }
    }

    return 0;
}
