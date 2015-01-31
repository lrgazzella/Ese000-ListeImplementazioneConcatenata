#include <stdlib.h>
#include ".\linkedList.h"

/*
 * Inserts the new key at the beginning of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLInsertAtBeginning(LLElement * first, int key) {
    LLElement * nuovo;
    nuovo = (LLElement *)malloc(sizeof(LLElement));
    
    if(nuovo != NULL){
        nuovo->next = first;
        nuovo->key = key;
        first = nuovo; 
    }
    
    return first;
} //-1

/*
 * Inserts the new key at the end of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLInsertAtEnd(LLElement * first, int key) {
    LLElement * nuovo;
    nuovo = (LLElement *)malloc(sizeof(LLElement));
    
    LLElement **scorri;
    scorri = &first;
    if(nuovo != NULL){

        while((*scorri) != NULL){
            scorri = &((*scorri)->next);
        }
        nuovo->next = NULL;
        nuovo->key = key;
        *scorri = nuovo;
    }
    
    return first;
} // -1

/*
 * Inserts the new key at the specified positon of the list.
 * Position is zero-based, meaning that the first element is at position 0,
 * analogous to what happens in arrays.
 * 
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLInsertAtPosition(LLElement * first, int key, int position) {
    
    LLElement * nuovo;
    nuovo = (LLElement *)malloc(sizeof(LLElement));
    
    LLElement ** scorri;
    scorri = &first;
    int i;
    
    if(nuovo != NULL){
        for(i=0; i<position ; i++){
            scorri = &((*scorri)->next);
        }
        nuovo->next = *scorri;
        nuovo->key = key;
        *scorri = nuovo; 
    }
    return first;
} //-1

/*
 * Returns the size of the list.
 */
int LLSize(LLElement * first) {
    int size = 0;
       
    while(first != NULL){
        size++;
        first = first->next;
    }
    
    return size;
}   //-1

/*
 * Returns the key at the specified position.
 */ 
int LLGetKey(LLElement * first, int position) {
    int i;

    for(i=0; i<position ; i++){
        first = first->next;
    }
    
    return first->key;
} //-1

/*
 * Returns the position of the first element, starting from startPosition, that
 * has the specified key.
 * Returns -1 if not found. 
 */ 
int LLFindKey(LLElement * first, int key, int startPosition) {    
    int i;
    
    for(i=0; i<startPosition; i++){
        first = first->next;
    }
    
    while(first != NULL){
        if(first->key == key){
            return i;
        }else{
            first = first->next;
            i++;
        }
    }
    
    return -1;
} //-1

/*
 * Remove the first element of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLRemoveFirst(LLElement * first) {
    LLElement * ultimo = NULL;
    
    if(first != NULL){
        ultimo = first;
        first = first->next;
        free(ultimo);
    }else{
        printf("La lista Ã¨ vuota \n");
    }
    
    return first;
} //-1

/*
 * Remove the last element of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLRemoveLast(LLElement * first) {
        
    LLElement **scorri;
    
    if(first != NULL){
        scorri = &first;
        while((*scorri)->next != NULL){
            scorri = &((*scorri)->next);
        }
        free(*scorri);
        *scorri = NULL;
    }
    
    return first;
} //-1

/*
 * Remove the element at the specified position.
 * Position is zero-based, meaning that the first element is at position 0,
 * analogous to what happens in arrays.
 * 
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLRemoveAtPosition(LLElement * first, int position) {
    
    LLElement ** scorri;
    LLElement * elimina;
    
    int i;
    
    if(first != NULL){
        scorri = &first;
        for(i=0; i<position && *scorri!=NULL; i++){
            scorri = &((*scorri)->next);
        }
        
        if(*scorri != NULL){
            elimina = *scorri;
            *scorri = (*scorri)->next;
        }
        
        free( elimina );
    }
    return first;
} //-1
        
/* Empties the list */
LLElement * LLEmptyList(LLElement *first) {
    LLElement *elimina;
    while(first != NULL) {
        elimina = first;
        first = first->next;
        free(elimina);
    }
    first = NULL;
    return first;
} //-1