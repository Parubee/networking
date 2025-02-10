#include<stdio.h>
#include<unistd.h>

int main() {
    int incoming, outgoing, buck_size, n, store = 0;
    
    printf("Enter bucket size, outgoing rate, and number of inputs: ");
    scanf("%d %d %d", &buck_size, &outgoing, &n);

    while (n != 0) {
        printf("Enter the incoming packet size: ");
        scanf("%d", &incoming);
        printf("Incoming packet size: %d\n", incoming);

        // If the buffer has space for the incoming packets
        if (incoming <= (buck_size - store)) {
            store += incoming;
            printf("Bucket buffer size: %d out of %d\n", store, buck_size);
        } else {
            // If the buffer overflows, drop excess packets
            int dropped = incoming - (buck_size - store);
            printf("Dropped %d packets\n", dropped);
            store = buck_size;  // Fill the bucket to capacity
            printf("Bucket buffer size: %d out of %d\n", store, buck_size);
        }

        // Handle outgoing packets
        if (store >= outgoing) {
            store -= outgoing; // Reduce the buffer size by the outgoing rate
        } else {
            store = 0;  // If less than the outgoing rate, all packets are sent out
        }

        // Display buffer status after outgoing packets
        printf("After outgoing, there are %d out of %d packets left in the buffer\n", store, buck_size);
        n--;
    }

    return 0;
}

