
#include "student_code.h"
#include "string.h"
#include "stdlib.h"
#include "ctype.h"


/***********
 * Strings *
 ***********/

/**
 * This function takes in a c-string and returns it's length.  It **does not** use the strlen(...) function in string.h
 * @param str The string that we will be finding the length of.  It will be null terminated
 * @return The lenght of the inpurt string
 */
int get_str_length(char* str) {
  // Note: You cannot use any functions in string.h for this function!  Doing so will result in a score of 0
  // Question: How do we know that we've gotten to the end of a c-string?
  int l = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    l++;
  }
  //Use below for troubleshooting:
  //printf("string length is %d\n", l);
  return l;
  //return -1;
}

/**
 * Returns a pointer to a copy of the original string.  It **does not** use strcpy or any related function (but may use strlen)
 * @param str An input string that is null terminated
 * @return a new char* that copies the input string str
 */
char* copy_str(char* str) {
  // Note: You cannot use any functions in string.h for this function!  Doing so will result in a score of 0
  char* str_cpy = malloc(get_str_length(str)); 
  for (int i = 0; str[i] != '\0'; i++) {
	  str_cpy[i] = str[i];
  }
  return str_cpy;
}

/**
 * Truncates a string to a the given length, not including the null terminator.  If the given length is longer than the original string the original string is returned unchanged.
 * @param str A null-terminated input string
 * @param new_length The length of the output string.
 */
void truncate_string(char* str, int new_length) {
  // Note: You cannot use any functions in string.h for this function!  Doing so will result in a score of 0
  //printf("Here is the string: ");
  //printf(str);
  //printf(" string length is %d and new length is %d\n", get_str_length(str), new_length);
  if(get_str_length(str) > new_length) {
  str[new_length] = '\0';
  }
  //printf("New string length is %d\n", get_str_length(str));
}

/**
 * Converts a given string, str, to all uppercase letters
 * @param str A null-terminated input string
 */
void to_uppercase(char* str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      str[i] = str[i] - 32;
    }
  }
}

/**
 * Converts a given string, str, to all lowercase letters
 * @param str A null-terminated input string
 */
void to_lowercase(char* str) {
  for (int i=0; str[i] != '\0'; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      str[i] = str[i] + 32;
    }
  }
}

/**
 * Finds the index of the first usage of a target character, starting from 0.  If it doesn't exist return -1
 * @param str A null-terminated input string
 * @param target A character to find in string
 * @return The index of the first usage of the target character in the string
 */
int find_first_index(char* str, char target) {
  // Note: You cannot use any functions in string.h for this function!  Doing so will result in a score of 0
  char* str_cpy = copy_str(str);
  to_uppercase(str_cpy);
  int index = -1;
  
  if(target >= 'a' && target <= 'z') {
    target -= 32;
  }
  for (int i=0; str_cpy[i] != '\0'; i++) {
    if (target == str_cpy[i]) {
      index = i;
      break;
    }
  }
  return index;
}

/**
 * Finds the index of the last usage of a target character, starting from 0.  If it doesn't exist return -1
 * @param str A null-terminated input string
 * @param target A character to find in string
 * @return The index of the last usage of the target character in the string
 */
int find_last_index(char* str, char target) {
  // Note: You cannot use any functions in string.h for this function!  Doing so will result in a score of 0
  char* str_cpy = copy_str(str);
  to_uppercase(str_cpy);
  if(target >= 'a' && target <= 'z') {
      target -= 32;
  }
  int index = -1; 
  int i = get_str_length(str_cpy);
  
  for (; i >= 0 ; i--) {
    if (target == str_cpy[i]) {
      index = i;
      break;
    }
  }
  return index;
}


/**************
 * Structures *
 **************/
/**
 * Create a new person object and return the object
 * @param first_name The first name of the new person as a null-terminated string
 * @param last_name The last name of the new person as a null-terminated string
 * @param age The age of the person as an int
 * @return A Person struct containing the new person
 */
Person person_make_new(char* first_name, char* last_name, int age) {
  Person p;
  //todo: check if string length should be defined by constant
  if(get_str_length(first_name) > 50 || get_str_length(last_name) > 50) {
    return p;
  }
  strcpy(p.first_name, first_name);
  strcpy(p.last_name, last_name);
  p.age = age;
  return p;

}
/**
 * Return a string containing the full name and age of the person in the format "First Last (age)"
 * @param person The person to get the relevant string for
 * @return A string containing the name of the person
 */
char* person_to_string(Person person) {
  // hint: sprintf
  char* buffer = malloc(sizeof(person));
  int j = 0;
  //printf("size of the person is %d\n", sizeof(person));
  j = sprintf(buffer, "%s", person.first_name);
  j += sprintf(buffer + j, " %s", person.last_name);
  j += sprintf(buffer + j, " (%d)", person.age);
  //printf("%s", buffer);
  return buffer;
}

/**
 * A function to create a new empty group
 * @param group_name A null-terminuated string to name the new group
 * @return A new Group struct
 */
Group group_make_new(char* group_name) {
  Group g;
  if(get_str_length(group_name) > 50) {
    return g;
  }
  strcpy(g.group_name, group_name);
  g.num_members = 0;
  return g;
}

/**
 * A function to find the total number of people in the group
 * @param group A Group struct that contains some number of people
 * @return The number of users in the group
 */
int num_people_in_group(Group group) {
  return group.num_members;
}
/**
 * Get the number of free spaces remaining in the group
 * @param group A Group struct that contains some number of people
 * @return The number of free spaces in the group
 */
int free_spaces_in_group(Group group) {
  return GROUP_MAX_SIZE - group.num_members;
}

/**
 * Add a person to the group if possible and return the total number of free space in the group. Otherwise return -1.
 * @param group A group struct that contains some number of people
 * @param person_to_add The person to add to the group
 * @return The number of free spaces after add the new person, -1 if the group was already full
 */
int add_person(Group* group, Person* person_to_add) {
  // Question: Say we have already added a person to the group and try to add them again.  What should be we do?  Where can we check what the expected behavior is?
  if(free_spaces_in_group(*group) > 0) {
    for(int i = 0; i < group->num_members; i++) {
      if(person_to_add == group->group_members[i]) {
        return -1;
      }
    }
    group->group_members[group->num_members] = person_to_add;
    group->num_members++;
    return free_spaces_in_group(*group);
  } else {
    return -1;
  }
}

/**
 * Remove a person from the group if they are in the group, otherwise return -1
 * @param group A Group struct that contains some number of people
 * @param person_to_remove A person to remove from the group
 * @return The number of people remaining in the group, -1 if the person was not in the group
 */
int remove_person(Group* group, Person* person_to_remove) {
  for(int i = 0; i < group->num_members; i++) {
    if(person_to_remove == group->group_members[i]) {
      for(int j = i; j < group->num_members; j++) {
        group->group_members[j] = group->group_members[j+1];
      }
      group->num_members--;
      return group->num_members;
    }
  }
  return -1;
}



/*
 * Caesar Cipher
 */
/**
 * Shift a character 'left' by the shift amount by subtracting the shift size.
 *  e.g. 'a' with a shift_size = 1 will become 'z'
 * @param input_char
 * @param shift_size
 * @return
 */
char shift_left(char input_char, int shift_size) {
  if(input_char >= 'A' && input_char <= 'Z') {
        input_char += 32;
  }
  if(input_char >= 'a' && input_char <= 'z') {
    return 'a' + (input_char - 'a' - shift_size + 26) % 26;
  }
  return input_char;
}

/**
 * Shift a character 'right' by the shift amount by subtracting the shift size.
 *  e.g. 'z' with a shift_size = 1 will become 'a'
 * @param input_char
 * @param shift_size
 * @return
 */
char shift_right(char input_char, int shift_size) {
  if(input_char >= 'A' && input_char <= 'Z') {
          input_char += 32;
  }
  if(input_char >= 'a' && input_char <= 'z') {
    return 'a' + (input_char - 'a' + shift_size) % 26;
  }
  return input_char;
}

/**
 * Encrypts a string using a given shift.  Note: All characters should be converted to lowercase
 * @param input_str
 * @param shift_size
 * @return
 */
char* encrypt_caesar(char* input_str, int shift_size) {
  char* str_cpy = malloc(get_str_length(input_str));
  for (int i=0; input_str[i] != '\0'; i++) {
    str_cpy[i] = shift_left(tolower(input_str[i]), shift_size);
  }
  return str_cpy;
}

/**
 * Decrypts a string using a given shift.  Note: All characters should be converted to lowercase
 * @param input_str
 * @param shift_size
 * @return
 */
char* decrypt_caesar(char* input_str, int shift_size) {
  char* str_cpy = malloc(get_str_length(input_str));
  for (int i=0; input_str[i] != '\0'; i++) {
    str_cpy[i] = shift_right(tolower(input_str[i]), shift_size);
  }
  return str_cpy;
}

/*
 * General substitution Cipher
 */

/**
 * Returns true if a given encryption key has a valid decryption key.
 * @param encryption_key
 * @return
 */
bool is_reversible(int* encryption_key) {
  for (int i=0; i < 26; i++) {
    if(encryption_key[i] < 0 || encryption_key[i] > 25) {
      return false;
    }
    for (int j=0; j < 26; j++) {
      if(encryption_key[i] == encryption_key[j] && i != j) {
        return false;
      }
    }
  }
  return true;
}

/**
 * Generates a decryption key based on the encryption key, if one exists.  Otherwise returns NULL
 * @param encryption_key
 * @return
 */
int* get_decryption_key(int* encryption_key) {
  int* decryption_key = malloc(26 * sizeof(int));
  printf("size %lu\n", sizeof(int*));
  if (is_reversible(encryption_key) == 1) {
    for (int i = 0; i < 26; i++) {
      decryption_key[encryption_key[i]] = encryption_key[i];
      printf("%d ", encryption_key[i]);
    }
    printf("\n");
    for (int i = 0; i < 26; i++) {
      printf("%d ", decryption_key[i]);
    }
    printf("\n");
    return decryption_key;
  }
  else {
    return NULL;
  }
}

/**
 * Takes the input string and the encryption key and encrypts the input string in place
 * @param input_str
 * @param encryption_key
 */
void encrypt_substitution(char* input_str, int* encryption_key) {
  for(int i = 0; i < 26; i++) {
    printf("%d ", encryption_key[i]);
  }
  for(int i = 0; i < get_str_length(input_str); i++) {
    for(int j = 0; j < 26; j++) {
      if(input_str[i] == j + 97) {
        input_str[i] = encryption_key[j] + 97;
        break;
      }
    }
  }
  return;
}

/**
 * Takes an encrypted input string and a decryption key and decrypts a string in place
 * @param input_str
 * @param decryption_key
 */
void decrypt_substitution(char* input_str, int* decryption_key) {
  for(int i = 0; i < get_str_length(input_str); i++) {
      for(int j = 0; j < 26; j++) {
        if(input_str[i] == j + 97) {
          input_str[i] = decryption_key[j] + 97;
          break;
        }
      }
    }
  return;
}




