#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "command.h"
#include <glib.h>

struct scommand_s {
    GQueue *args;     
    char *redir_in;   
    char *redir_out;  
};

scommand scommand_new(void){
<<<<<<< HEAD

    scommand new_scommand= malloc(sizeof(struct scommand_s)); 
    new_scommand -> redir_in = NULL;
    new_scommand -> redir_out = NULL;
    return new_scommand;
=======
   scommand new = malloc(sizeof(struct scommand_s));
   new->args = g_queue_new();
   new->redir_in = NULL;
   new->redir_out = NULL;

   return new;
>>>>>>> 7f0c0ec (Scommand_new y struct)
}

scommand scommand_destroy(scommand self){
    return NULL;
}

void scommand_push_back(scommand self, char * argument){

}

void scommand_pop_front(scommand self){
    
}

void scommand_set_redir_in(scommand self, char * filename){

}
void scommand_set_redir_out(scommand self, char * filename){

}

bool scommand_is_empty(const scommand self){
    return true;
}

unsigned int scommand_length(const scommand self){
    return 0;
}

char * scommand_front(const scommand self){
    return NULL;
}

char * scommand_get_redir_in(const scommand self){
    return NULL;
}
char * scommand_get_redir_out(const scommand self){
    return NULL;
}

char * scommand_to_string(const scommand self){
    return NULL;
}

pipeline pipeline_new(void){
    return NULL;
}

pipeline pipeline_destroy(pipeline self){
    return NULL;
}

void pipeline_push_back(pipeline self, scommand sc){
    
}

void pipeline_pop_front(pipeline self){
   
}

void pipeline_set_wait(pipeline self, const bool w){
    
}

bool pipeline_is_empty(const pipeline self){
    return true;
}

unsigned int pipeline_length(const pipeline self){
    return 0;
}

scommand pipeline_front(const pipeline self){
    return NULL;
}

bool pipeline_get_wait(const pipeline self){
    return true;
}

char * pipeline_to_string(const pipeline self){
    return NULL;
}
