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
        return; 
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
    return (self == NULL) || g_queue_is_empty(self->args);
}


unsigned int scommand_length(const scommand self){
    if (self == NULL) return 0;
    return g_queue_get_length(self->args);
}

char * scommand_front(const scommand self){
        if (self == NULL || g_queue_is_empty(self->args)){
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
   if (self == NULL ) return NULL;
    GString * str = g_string_new ((char *)self->args->head->data);
    for (GList *iter = self->args->head; iter != NULL; iter = iter->next) {
        g_string_append_printf(str, "%s", (char *)iter->data);
    };
    if (self->redir_in != NULL) {
        g_string_append_printf(str, "< %s", self->redir_in);
    }
    if (self->redir_out != NULL) {
        g_string_append_printf(str, "> %s", self->redir_out);
    }
    char *result = g_string_free(str, FALSE); 
    return result;
}

struct pipeline_s {
    GQueue *commands;
    bool wait;
};

pipeline pipeline_new(void){
    pipeline result = malloc(sizeof(struct pipeline_s));
    if (result == NULL){
        return NULL;
    }
    result -> commands = g_queue_new();
    result -> wait = true;
    return result;
}

pipeline pipeline_destroy(pipeline self) {
    if (self == NULL) {
        return NULL;
    }
    while (!g_queue_is_empty(self->commands)) {
        scommand p = g_queue_pop_head(self->commands);
        scommand_destroy(p);
    }
    g_queue_free(self->commands);
    free(self);

    return NULL;
}

void pipeline_push_back(pipeline self, scommand sc){
    if (self == NULL || sc == NULL) {
        return;
    }
    g_queue_push_tail(self->commands, sc);    
}

void pipeline_pop_front(pipeline self){
   if (self == NULL || pipeline_is_empty(self)) return;
    struct scommand_s *chead = g_queue_pop_head(self->commands);
    scommand_destroy(chead);
}


void pipeline_set_wait(pipeline self, const bool w){
    if (self != NULL){
        self -> wait = w;  
    }
}

bool pipeline_is_empty(const pipeline self) {
    if (self == NULL) {
        return true;
    }
    return g_queue_is_empty(self->commands);
}

unsigned int pipeline_length(const pipeline self) {
    if (self == NULL) {
        return 0;
    }
    return g_queue_get_length(self->commands);
}

scommand pipeline_front(const pipeline self) {
    if (self == NULL || g_queue_is_empty(self->commands)) {
        return NULL;
    }
    return (scommand) g_queue_peek_head(self->commands);
}

bool pipeline_get_wait(const pipeline self) {
    if (self == NULL) {
        return false;
    }
    return self->wait;
}

char * pipeline_to_string(const pipeline self){
    if (self == NULL){
        return NULL;
    }
    Gstring *result = g_string_new(NULL);

    int n = g_queue_get_length(self->commands);
    
    for (int i = 0; i < n; i++){
        char *cmd = g_queue_peek_nth(self->commands, i);
        g_string_append(result,cmd);

        if (i < n-1) {
            g_string_append(result, " | ");
        }
    } 
    if (!self -> wait){
        g_string_append(result, " & ");
    }
    char *out = g_strdup(result->str);
    g_string_free(result, TRUE);
    return out;
}
