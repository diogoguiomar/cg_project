using namespace std;

struct BitMapFile
{
   int sizeX;
   int sizeY;
   unsigned char *data;
};

BitMapFile *getBMPData(string filename);

void loadExternalTextures();
