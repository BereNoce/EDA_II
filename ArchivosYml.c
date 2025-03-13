

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define INDENT_SPACES 2
#define MAX_ALUMS 3

typedef struct
{
   char  nombre[32];
   int   semestre;
   float promedio;
} Alumno;

typedef struct
{
   char   profesor[32];
   int    grupo;
   char   semestre[8];
   int    anio;
   bool   finalizado;
   Alumno alumnos[ 10 ];
} Grupo;

#define FILE_HANDLER stderr

int main()
{
   Grupo g03 =
   {
      .profesor = "Fco",
      .grupo = 3,
      .semestre = "2022-1",
      .anio = 2021,
      .finalizado = false,
      .alumnos[0] = { .nombre = "Bart", .semestre = 3, .promedio = 6.1 },
      .alumnos[1] = { .nombre = "Liza", .semestre = 2, .promedio = 10.0 },
      .alumnos[2] = { .nombre = "Milhouse", .semestre = 3, .promedio = 9.5 },
   };

    FILE* yaml_output = fopen( "g03.yml", "w" ); 
    if( !yaml_output ){
        printf( "Error abriendo el archivo\n" ); 
        exit( 1 );
    }
    
    fprintf( yaml_output, "---\n" );
    fprintf( yaml_output, "profesor: %s\n", g03.profesor );
    
    // inserta el resto de la información a este mismo nivel: grupo, semestre, anio y finalizado
    int depth = 0;
    
    ++depth;
    // agregamos un nivel cada que entremos a un nuevo registro/lista
    
    fprintf( yaml_output, "alumnos:\n" ); 
    for( size_t i = 0; i < MAX_ALUMS; ++i ) {
        // inserta los espacios necesarios:
        
        for( size_t indent = 0; indent < (depth*2); ++indent ) {
            fprintf( yaml_output, " " );
        }
        
        fprintf( yaml_output, "- " );
        fprintf( yaml_output, "semestre: %d\n", g03.alumnos[ i ].semestre );
        
        for( size_t indent = 0; indent < (depth*2)+INDENT_SPACES; ++indent ) {
            fprintf( yaml_output, " " );
        }
        
        fprintf( yaml_output, "nombre: %s\n", g03.alumnos[ i ].nombre );
        
        for( size_t indent = 0; indent < (depth*2)+INDENT_SPACES; ++indent ) {
            fprintf( yaml_output, " " );
        }
            
        fprintf( yaml_output, "promedio: %0.2f\n", g03.alumnos[ i ].promedio );
         
    }
    
    fprintf( yaml_output, "\n..." );
    fclose( yaml_output );
}
