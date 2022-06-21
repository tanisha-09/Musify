#include<iostream>
#include<windows.h>
#include<mmsystem.h>
using namespace std;

int main()
{
    PlaySound(TEXT("Hii.wav"),NULL,SND_SYNC);
    //PlaySound("Hii.wav", NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);
    cout << "Hello world!" << endl;
    return 0;
}
