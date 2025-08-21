#include <stdbool.h> 
#include <stdbool.h> 


typedef struct scommand_s * scommand{
    return NULL;

}

scommand scommand_new(void){
    return NULL;
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

typedef struct pipeline_s * pipeline{
    return NULL;
}

pipeline pipeline_new(void){

}

pipeline pipeline_destroy(pipeline self){

}

void pipeline_push_back(pipeline self, scommand sc){

}

void pipeline_pop_front(pipeline self){

}

void pipeline_set_wait(pipeline self, const bool w){

}

bool pipeline_is_empty(const pipeline self){

}

unsigned int pipeline_length(const pipeline self){

}

scommand pipeline_front(const pipeline self){

}

bool pipeline_get_wait(const pipeline self){

}

char * pipeline_to_string(const pipeline self){

}
