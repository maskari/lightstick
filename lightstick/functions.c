//
//  functions.c
//  lightstick
//
//  Created by Abdullah Maskari on 17/06/2014.
//
//

#include <stdio.h>
#include "functions.h"
#include <stdlib.h>

struct Pixel* pixels = NULL ;
//counting number of lines (and hence number of pixels that need to be sent)
unsigned long linecount;

//structure to hold all the parsed data from the txt file
struct Pixel
{
    int x; // x axis of pixel location
    int y; // y axis of pixel location
    int r; //red
    int g; //green
    int b; //blue
    
};

// number of pixels in x coordinate
int xvalue();


int xvalue(){
    int i = 0;
    while (pixels[i].y == 0)
    {
        i++;
    }
    return i;
}




/*************************************************** Main program *****************************************/


// parent program function used to run all other functions below
int main(int argc, char *argv[])
//int parse()
{
    
    
     fileName = argv[1]; /* should check that argc > 1 */
    //fileName = argv[1]; /* should check that argc > 1 */
    file = fopen(fileName, "r"); /* should check the result */
    
    Count(file);
    
    printf("malloc");
    pixels = malloc( sizeof( struct Pixel ) * linecount );
    if (pixels == NULL)
        printf("malloc failed");
    
    file = fopen(fileName, "r"); /* should check the result */
    Parser(file);
    
    sender(NULL);
    
    
    
    
    
    
    
    fclose(file);
    free(pixels);
    
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}




// find number of lines in a file
void Count(FILE* file) {
    
    // FILE *fp = fopen(file_patch, "r");
    unsigned long line_count = 0;
    int c;
    if(file == NULL){
        // fclose(file);
       // return 0;
    }
    
    /* count the newline characters */
    while ( (c=fgetc(file)) != EOF ) {
        if ( c == '\n' )
            line_count++;
    }
    
    
    //account for header in line 0
    linecount=line_count-1;
    printf("%lu newline characters\n", linecount);
   // return 0;
    
}



// read .txt file and store its data in a useful format in the struct pixels
void Parser(FILE* file)
{
    // file = fopen(fileName, "r"); /* should check the result *
    // struct Pixel pixels[linecount] =calloc(sizeof(linecount), sizeof(struct Pixel));
    // struct Pixel pixels[linecount] = malloc(sizeof(struct Pixel)*linecount);
    // fscanf(file, "");
    
    
    // struct Pixel pixels[linecount];
   // if( !pixels )    //function scope
  //  printf("malloc");
    //    pixels = malloc( sizeof( struct Pixel ) * linecount ) ;
    //printf("malloc");
    //array to hold all pixel data
    int valuex;
    valuex = RetXvalue();
    int pixeldata[valuex][LEDS];

    
    // skipping header line
    fscanf(file, "%*[^\n]\n", NULL);
    
    for(int i=0; i<linecount; i++)
    {
        fscanf(file, "%i,%i: (%i,%i,%i", &pixels[i].x, &pixels[i].y,&pixels[i].r,&pixels[i].g,&pixels[i].b);
        // fscanf(file, "%i %i %i %i %i", &pixels[i].x, &pixels[i].y,&pixels[i].r,&pixels[i].g,&pixels[i].b);
        
        
        //skip to end of line
        fscanf(file, "%*[^\n]\n", NULL);
        
        //print result to console output
        printf("data read: x:%i\t, y:%i\t, R %i\t, G %i\t, B %i\t\n", pixels[i].x, pixels[i].y,pixels[i].r,pixels[i].g, pixels[i].b);
        
        
        
        
        
        
        /*
         
         int t[200][5] = {0};
         fscanf(file, "%i,%i: (%i,%i,%i",t[i][0] , t[i][1],t[i][2],t[i][3],t[i][4]);
         fscanf(file, "%*[^\n]\n", NULL);
         printf("data read: x:%i\t, y:%i\t, R %i\t, G %i\t, B %i\t\n", t[i][0] , t[i][1],t[i][2],t[i][3],t[i][4]);
         */
        
    }
    
    //return 0;
}

  int RetXvalue(){
    int i = 0;
    while (pixels[i].y == 0)
    {
        i++;
    }
    return i;
}

//write image data to serial port and interact with arduino

void sender(){
    
    // function variables
    
    int returnedX = RetXvalue();
    int counter;
    int buffsize = returnedX*3;
    //int buffsize = (LEDS+1)*3;
    char buffer[buffsize];
    init_buf(buffer, buffsize);
   // while(counter <= linecount){
    char *bufpointer=buffer;
        for (int x=0; x<=returnedX; x++)
        {
           // inner for loop for adding all the numbers to the string "buffer"
            for (int y=0; y<=LEDS; y++)
            {
                snprintf(bufpointer+=strlen(bufpointer), buffsize, "%d%d%d", pixels[counter].r,pixels[counter].g, pixels[counter].b );
                printf("buffer contents: %s\n",buffer);
            }
            
           
            printf(buffer);
                
                
           /*     if(selector == 0)
                {};
            
            //send next even number
            
            else
                if (selector == 1)
                //send odd number
                {};
                    
            else
                printf("error, no valid response detected from remote arduino");
        
                
                counter++;
            
            
        
    }
  
        }
            
         */
    }
   // return 0;
}



void init_buf(char *buf, size_t size){
    int i;
    for(i=0; i<size; i++){
        buf[i] = '0'; // int to char conversion
    }
}


