#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    
    int total_packets = 5;      // Total packets to send
    int current_packet = 1;     // Current packet number
    int last_received = 0;      // Last packet received successfully
    
    while (current_packet <= total_packets) {
        // Sender sends packet
        printf("SENDER: sent packet with seq NO:%d\n", current_packet);
        
        // Check if packet is received (90% chance)
        if (rand() % 100 < 90) {
            // Check if this is a duplicate packet
            if (current_packet == last_received) {
                printf("RECEIVER: Duplicated packet with seq %d\n", current_packet);
            } else {
                printf("RECEIVER: Received packet with seq %d\n", current_packet);
                last_received = current_packet;
            }
            
            // Try to send ACK (90% chance)
            if (rand() % 100 < 90) {
                printf("SENDER: Received ACK for packet %d", current_packet);
                current_packet++;  // Move to next packet
                if (current_packet <= total_packets) {
                    printf("\n");  // Add newline only if not the last packet
                }
                printf("\n");
            } else {
                printf("Error While sending ACK\n\n");
            }
        }
    }
    
    return 0;
}
 
 
       
