#include "src/student_code.h"
#include <stdlib.h>

int main() {
    int encryption_key[26] = {0,11,22,7,18,3,14,25,10,21,6,17,2,13,24,9,20,5,16,1,12,23,8,19,4,15};

    int* decryption_key = malloc(26 * sizeof(int));
    for(int i = 0; i < 26; i++) {
        decryption_key[i] = 0;
    }
    if (is_reversible(encryption_key) == 1) {
      for (int i = 0; i < 26; i++) {
        decryption_key[encryption_key[i]] = i;
        /*for (int j = 0; j < 26; j++) {
          if (encryption_key[i] == j) {
            decryption_key[j] = i;
          }
        }*/
      }
      for (int i = 0; i < 26; i++) {
        printf("%d ", decryption_key[i]);
      }
      printf("\n");
    }

    return 0;
}
