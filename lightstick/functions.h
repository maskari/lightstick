//
//  functions.h
//  lightstick
//
//  Created by Abdullah Maskari on 12/06/2014.
//
//

#ifndef lightstick_functions_h
#define lightstick_functions_h

#define LEDS 230




//variables



//selector for odd or even line to send
uint selector=0;
// text file with image data
FILE* file;
extern int pixeldata;
// file name gets copied from commandline argument to here
char const* fileName;


void Count(FILE* file);
void Parser(FILE* file);
int parse();
//extern struct Pixel pixels[];
extern struct Pixel* pixels;


void init_buf(char *buf, size_t size);
void print_buf(char *buf);
void sender();


//
////read file and sort required numbers in array
//int Parse(FILE* file)
//{
//  
//        char line[256];
//    while (fgets(line, sizeof(line), file)) {
//        /* note that fgets don't strip the terminating \n, checking its
//         presence would allow to handle lines longer that sizeof(line) */
//        printf("%s\n", line);
//    }
//    /* may check feof here to make a difference between eof and io failure -- network
//     timeout for instance */
//    
//    
//    
//    return 0;
//}
//
//
//
//char *readFile(char *fileName, FILE* file)
//{
// //   FILE *file = fopen(fileName, "r");
//    char *code;
//    size_t n = 0;
//    int c;
//    
//    if (file == NULL)
//        return NULL; //could not open file
//    
//    code = malloc(1000);
//    
//    while ((c = fgetc(file)) != EOF)
//    {
//        while(
//        code[n++] = (char) c;
//    }
//    
//    // don't forget to terminate with the null character
//    code[n] = '\0';
//    
//    return code;
//}
//        
//        
        


#endif
