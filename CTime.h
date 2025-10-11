#include <iostream>
using namespace std;

class CTime {
private:
    int gio, phut, giay;

public:
    CTime();                         
    CTime(int, int, int);           
    CTime(const CTime&);             

    friend istream& operator>>(istream&, CTime&);
    friend ostream& operator<<(ostream&, CTime&);

    int getGio();
    int getPhut();
    int getGiay();

    void setGio(int);
    void setPhut(int);
    void setGiay(int);

    ~CTime();                        
};


