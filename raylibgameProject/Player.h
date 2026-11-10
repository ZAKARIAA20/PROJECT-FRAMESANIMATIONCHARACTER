#pragma once
#include "raylib.h"

class Player {
private:
    // Les variables dyl l'objet wallyo private (Encapsulation)
    Texture2D imageplayer;
    int framewide;// ch7al mn itar f ligne 
    int frametall;// ch7al mn ligne f sora
    float framewidth;//3ard la3ib b float
    float frameHeight;//tol la3ib b float
    int currentframe;//ki 7fad l itar li khdamin fih wach movement 0 aw 1 (matalan star wa7d fih 4 dyal otor ki bda mn 0 l 3)
    int animRow;//ra9m dyal star f sora li k ndiro lih animation(ki bda b 0)
    float animspeed;//sor3a dyal animation li a ydoro fiha l itarat
    float timer;//lwa9t li ki 7SB ch7al ta3 lw9t bach doz l itar jay
    Vector2 position;//mkan wojod la3ib f chacha {x,y}
    double speed;//sor3a li a yt7ark biha l3ib f l itijahat

    Rectangle sourceRec;//howa lmoraba3 li k ndkhlo fih l itar li khdamin fih (hna fin k n9t3o l itarat) 
    Rectangle destRec;//ki 7adad fin bari t7ot chakhsiya f chacha w ch7al dyal L7ajm a ykon fiha {x,y,widith,height}
    
    float scale;//mo3amil takbir

public:
    Player();  // Constructor
    ~Player(); // Destructor
    bool isattacking = false;
    bool ismoving = false;
    void Initidle2();//hiya lmaseola 3la ta7mil sowar o k t3ti initiaalisation l9iyam li kynin f private
    void Initiattack();
    void Animate();//maseola 3an    animation 
    void move();
  
    void Draw();//hiya lmaseola 3la rasm chakhsiya f chacha bstikhdam DrawTexturePro
    
}; 
