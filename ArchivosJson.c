

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

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

#define FILE_HANDLER json_output

int main()
{
   Grupo g03 =
   {
      .profesor = "Fco",
      .grupo = 3,
      .semestre = "2022-2",
      .anio = 2022,
      .finalizado = false,
      .alumnos[0] = { .nombre = "Bart", .semestre = 3, .promedio = 6.1 },
      .alumnos[1] = { .nombre = "Liza", .semestre = 2, .promedio = 10.0 },
      .alumnos[2] = { .nombre = "Milhouse", .semestre = 3, .promedio = 9.5 },
   };

    FILE* json_output = fopen( "g03.json", "w" ); 
    if( !json_output ){
        printf( "Error abriendo el archivo\n" );
        exit( 1 ); 
        
    }
    
    fprintf( json_output, "{\n" );
    
    fprintf( json_output, "\"semestre\": \"%s\",\n", g03.semestre );
    fprintf( json_output, "\"grupo\": \"%d\",\n", g03.grupo );
    fprintf( json_output, "\"profesor\": \"%s\",\n", g03.profesor );
    
    fprintf( json_output, "\"finalizado\": \"%s\",\n", g03.finalizado ? "true" : "false" );
    
    fprintf( json_output, "\"alumnos\": [\n" ); 
    for( size_t i = 0; i < MAX_ALUMS; ++i ){
        
        if( i > 0 ) fprintf( json_output, ",\n" );
        
        fprintf( json_output, "{ " );
        
        fprintf( json_output, "\"nombre\": \"%s\", \"semestre\": %d, \"promedio\": %0.2f",
                    g03.alumnos[ i ].nombre,
                    g03.alumnos[ i ].semestre,
                    g03.alumnos[ i ].promedio );
        fprintf( json_output, " }" );
        // la ',' separadora de registros se inserta al principio del ciclo; 
        // la ',' separadora NO se inserta en el último registro
    }
    
    fprintf( json_output, "\n]" );
    //fprintf( json_output, ",\n" );
    // descomentar cuando este arreglo NO sea el último elemento
       
    fprintf( json_output, "\n}" );
    fclose( json_output );

}
