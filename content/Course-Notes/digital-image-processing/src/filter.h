class BmpFile;

class Filter{
private:
    int num;
    int division;
    int* templateMatrix;

public:
    Filter(int num, int div, int* matrix);
    int filterAround(BmpFile* file, int x, int y);
    void filter(BmpFile* sBmp, BmpFile*& dBmp);
};