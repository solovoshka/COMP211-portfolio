/* COMP 211 Homework 10:  Dictionaries.
 *
 * N. Danner
 */

#include <stdbool.h>


struct dict_entry; 

/* The type of a dictionary from strings to integers.
 */
struct dict ;


/* dict_create() = ∅
 */
struct dict* dict_create() ;

int calculate_hash(const char* key, int capacity);

/* dict_size(s) = the number of key-value pairs in d.
 */
unsigned int dict_size(struct dict*) ;

/* dict_contains(d, s) = true,  s a key in d
 *                       false, o/w.
 */
bool dict_contains(struct dict*, char*) ;

/* dict_add(d, s, n):
 * Pre-condition:  d' = d
 * Post-condition: d = d' ∪ {(s, n)}.
 *
 * I.e., add (s, n) to d.  If there is a key value pair in d with key s, 
 * replace it.
 */
void dict_add(struct dict*, char*, int n) ;

/* dict_get(d, s) = v, where (s, v) is a key-value pair in d.
 *
 * Pre-condition:  dict_contains(d, s) = true.
 */
int dict_get(struct dict*, char*) ;

/* dict_delete(d, s):
 * Pre-condition:  d' = d
 * Post-condition: d = d' - {(s, n)}, if (s, n) is in d'
 *                     d',            otherwise.
 *
 * I.e., remove the key-value pair with key s from d.  Notice that if s is not
 * a key in d, calling dict_delete(d, s) has no effect.
 */
void dict_delete(struct dict*, char*) ;

/* to_array(d, ks):  fill ks with the keys of d.
 * Pre-condition:  ks has size at least dict_size(d).
 * Post-condition: the set of keys of d = {ks[i] : 0 <= i < dict_size(d)}.
 *
 * Note:  for 0 <= i < dict_size(d), ks[i] will have been dynamically
 * allocated.  It is up to the caller to free this space.
 */
void dict_keys_to_array(struct dict*, char*[]) ;

/* dict_free(d):  free all resources associated to d.
 */
void dict_free(struct dict*) ;

/* dict_print(d):  print information about s.
 *
 * There are no constraints on this function.  I suggest you implement it in a
 * way that prints out the values of everything used to represent your dict.
 */
void dict_print(struct dict*) ;

