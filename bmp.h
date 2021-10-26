/*
Daniela Esparza Espinosa
Definición de las funciones y macros para el manejo de imagenes BMP
*/
#ifndef BMP_H_
#define BMP_H_
#define PIXELSIZE sizeof(PIXEL)
#pragma pack(1)

typedef struct //Pixel with rgb values
{
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} PIXEL;

typedef struct
{
    unsigned int size; //BMP file size
    unsigned short resv1; //Reserved space
    unsigned short resv2; //Reserved space
    unsigned int offset; //Image's offset
} BMPFILEHEADER;

typedef struct
{
    unsigned int headerSize;
    unsigned int width;
    unsigned int height;
    unsigned short planes; //Color planes (Will always be 1)
    unsigned short bpp; //Bits per pixel
    unsigned int compress;
    unsigned int imgSize; //Image data size
    unsigned int bpmX; //Bits per meter x resolution
    unsigned int bpmY; //Bits per meter y resolution
    unsigned int colors; //Colors used in the color palette
    unsigned int imptColors; //Important colors, (if all of them are important = 0)
} BMPINFOHEADER;

//Functions
PIXEL *bmpLoad(char *fileName, BMPFILEHEADER *header, BMPINFOHEADER *bInfoHeader);
void bmpSave(char *fileName, BMPFILEHEADER *header, BMPINFOHEADER *bInfoHeader, PIXEL *imgData);
void bmpConvertBW(PIXEL *ptr, unsigned int imgSize);

#endif /*BMP_H_*/