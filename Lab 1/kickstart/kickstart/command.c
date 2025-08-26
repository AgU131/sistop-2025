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
   scommand new = malloc(sizeof(struct scommand_s));
   new->args = g_queue_new();
   new->redir_in = NULL;
   new->redir_out = NULL;

   return new;
}

scommand scommand_destroy(scommand self){
    if (self == NULL){
        return NULL;
    }
    else{
        g_queue_free_full(self->args, free);
    }
    free(self->redir_in);
    free(self->redir_out);
    free(self);
    return NULL;
}

void scommand_push_back(scommand self, char * argument){
    if (self == NULL || argument == NULL){
        return void; 
    }
    g_queue_push_tail(self->args, argument);
}

void scommand_pop_front(scommand self){
    if (self == NULL) return;               
    if (g_queue_is_empty(self->args)) return;
    char *first = g_queue_pop_head(self->args);
    free(first);
}

void scommand_set_redir_in(scommand self, char *filename) {
    if (self == NULL) return;
    g_free(self->redir_in);
    self->redir_in = filename;
}
void scommand_set_redir_out(scommand self, char *filename) {
    if (self == NULL) return;
    g_free(self->redir_out);
    self->redir_out = filename;
}

bool scommand_is_empty(const scommand self){
    if(self == NULL) {
        return true;
    }
    if (g_queue_is_empty(self->args)){
    return true;
    }
}

unsigned int scommand_length(const scommand self){
    if (self == NULL) return 0;
    unsigned int i = g_queue_get_length(self->args);
    return i;
}

char * scommand_front(const scommand self){
        if (self == NULL){
        return NULL;
    }
    if (g_queue_is_empty(self->args)){
        return NULL;
    }
    return (char*) g_queue_peek_head(self->args);
}

char * scommand_get_redir_in(const scommand self){
    if (self == NULL){
        return NULL;
    }
    return self -> redir_in;
}
char * scommand_get_redir_out(const scommand self){
    if (self == NULL){
        return NULL;
    }
    return self -> redir_out;
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
