#include<iostream>
using namespace std;
class CWH{
    protected:
    string title;
    float rating;
    public:
    CWH(string s,float r)
    {
        title = s;
        rating = r;
    }
    virtual void display(){}
};
class CWHvideo : public CWH{
    float video_Length;
    public:
    CWHvideo(string s,float r,float vl):CWH(s,r){
        video_Length = vl;
    }
    void display(){
        cout << "this is an amazing function decribing video of code with harry " << "\n";
        cout <<"Ratng of the video is : " << rating << "out of five stars" << endl;
        cout << "Length of the video is : " << video_Length << endl;
    }

};
class CWHText : public CWH{
    int words;
    public:
    CWHText(string s,float r,int wc) : CWH(s,r){
        words = wc;
    }
    void display(){
        cout << "This is an amazing text tutorial with an amazing text title" << title << endl;
        cout << "Rating of this text tutorial is : " << rating << "out of five star" << endl;
        cout << "no of words of text tutorial is " << words << "words" << endl;

    }
};
int main(){
    string title;
    float rating , vlen;
    int words;
    // code with harry video
    title  = "Django tutorial";
    vlen = 4.56;
    rating = 4.89;
    CWHvideo djVideo(title, rating, vlen);
    // for Code With Harry Text
    title = "Django tutorial Text";
    words = 433;
    rating = 4.19;
    CWHText djText(title, rating, words);
    CWH* tuts[2];
    tuts[0] = &djVideo;
    tuts[1] = &djText;
    tuts[0]->display();
    tuts[1]->display();

    return 0;
}