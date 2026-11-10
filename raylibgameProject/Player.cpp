#include "Player.h"

Player::Player() {
    currentframe = 0;
    animRow = 1;
    animspeed = 0.20f;
    timer = 0.0f;
    speed = 1.0f;
    scale = 2.0f;
    position.x = 0.0f;
    position.y = 0.0f;
}

Player::~Player() {
    UnloadTexture(imageplayer);
}

void Player::Initiattack() {
    imageplayer = LoadTexture("VOTRE PATH (FRAMES IMAGES)");
    framewide = 6;
    frametall = 2;

    framewidth = (float)imageplayer.width / framewide;//k n9smo kol itar o k n3rfo ch7al fih mn fps(k n9smo 3la 4)
    frameHeight = (float)imageplayer.height / frametall;//k n9smo tol dyal itar (k n9smo 3la 2)

    sourceRec = { 0.0f, 0.0f, framewidth, frameHeight };//sourceRec{(float)currentframe * framewidith,(float)animRow * frameHeight ,framewidith,frameHeight};
    //(float)currentframe * framewidith k nbdaw n9t3o mn current frame li howa f lisr l framewidith li howa l3ard li jbdna 9bl dyal kol itar
    //(float)animRow * frameHeight anime row howa mnin a ybda t9at3 wach mn star lfo9ani ola star li t7to o frameHeight howa ch7al a t9t3 o bitab3 7na khas n9t3o 3la 7sab chakhsiya 
    //framewidith k t3ni l3ard li radi n9t3Oh 
    //frameHeight k t3ni l irtifa3 li a n9t3oh


     destRec = {//fin brit chakhsiya tban w b ayi 7ajm
       position.x,//getScreenwidith k tjib lik l3ard dyal chacha 600 li dyrin f initWindow
        position.y, //getscreenHeight k tjib lik tol dyal chacha 1000 li dyrin f initWindow
        //framewidith *scale /2.0f howa li ki khali chakhsiya tji lwst
       //7ta frameHeight li ltAèt bjoj khas ydrbo f scale 3la 7sab nta chakhsiya ch7al britiha tban kbira o 9smha 3la joj
        framewidth * scale,//chdina chakhsiya o drbnaha f scale 3la 7sab ch7al brina nkbroha mn mara f l3ord
        frameHeight * scale//ch7al brina nkbroha mn mara f tol
         
    };
    
     
}

void Player::Initidle2() {
    imageplayer = LoadTexture("VOTRE PATH (FRAMES IMAGE)");
    framewide = 4;
    frametall = 2;

    framewidth = (float)imageplayer.width / framewide;//k n9smo kol itar o k n3rfo ch7al fih mn fps(k n9smo 3la 4)
    frameHeight = (float)imageplayer.height / frametall;//k n9smo tol dyal itar (k n9smo 3la 2)

    sourceRec = { 0.0f, 0.0f, framewidth, frameHeight };//sourceRec{(float)currentframe * framewidith,(float)animRow * frameHeight ,framewidith,frameHeight};
    //(float)currentframe * framewidith k nbdaw n9t3o mn current frame li howa f lisr l framewidith li howa l3ard li jbdna 9bl dyal kol itar
    //(float)animRow * frameHeight anime row howa mnin a ybda t9at3 wach mn star lfo9ani ola star li t7to o frameHeight howa ch7al a t9t3 o bitab3 7na khas n9t3o 3la 7sab chakhsiya 
    //framewidith k t3ni l3ard li radi n9t3Oh 
    //frameHeight k t3ni l irtifa3 li a n9t3oh


    destRec = {//fin brit chakhsiya tban w b ayi 7ajm
        GetScreenWidth() / 2.0f -(framewidth * scale) / 2.0f,//getScreenwidith k tjib lik l3ard dyal chacha 600 li dyrin f initWindow
        GetScreenHeight() / 2.0f - (frameHeight * scale) / 2.0f, //getscreenHeight k tjib lik tol dyal chacha 1000 li dyrin f initWindow
        //framewidith *scale /2.0f howa li ki khali chakhsiya tji lwst
       //7ta frameHeight li ltAèt bjoj khas ydrbo f scale 3la 7sab nta chakhsiya ch7al britiha tban kbira o 9smha 3la joj
        framewidth * scale,//chdina chakhsiya o drbnaha f scale 3la 7sab ch7al brina nkbroha mn mara f l3ord
        frameHeight * scale//ch7al brina nkbroha mn mara f tol
    };
}

void Player::Animate() {

    timer += GetFrameTime();//k nakhdo lwa9t li ki yakhdo rasm dyal kola frame o k nzidoh 3La time li 3adna 
    if (timer >= animspeed) {//o k nchofo wach ftna animespeed sor3a li brina animation dar biha ya3ni wach wsl lwa9t l itar jay
        timer = 0.0f;//ila ftnaha a nrj3o timer l 0
        currentframe++;//k nta9lo l itar jay
        if (currentframe >= framewide ) {//ila ftna l7ajm dyal itarat li 3adna f tswira 
            animRow++;
            currentframe = 0;
            if (animRow > frametall) {
                currentframe = 0;//k nrj3o l itar lwl
                animRow = 0;
            }
            
            if (isattacking) {
                isattacking = false;
                animRow = 0;
                framewide = 0;
                this->Initidle2();


            }
            
        }
      
  
    }
    
    sourceRec.x = (float)currentframe * framewidth;//hna k nb9aw nbdlo current frame ama f init bdinah b 0 ghi initializina
    sourceRec.y = (float)animRow * frameHeight;//nfs l7aja hna
}


void Player::move()
{
  
    
    
    if (IsKeyDown(KEY_RIGHT)) {
        position.x += speed; 
       
        
    }
    
    if (IsKeyDown(KEY_LEFT)) {
        position.x -= speed; 
        ismoving = true;
    }
    
    if (IsKeyDown(KEY_UP)) {
        position.y -= speed; 
        
    }
    
    if (IsKeyDown(KEY_DOWN)) {
        position.y += speed; 
        
    }
   


    destRec.x = position.x;
    destRec.y = position.y;
    if (position.x < 0) position.x = 0;
    if (position.y < 0) position.y = 0;
   
}

void Player::Draw() {
    DrawTexturePro(imageplayer, sourceRec, destRec, { 0.0f, 0.0f }, 0.0f, WHITE);
    //drna image player 7it chno a nrsmo 
    //drna sourceRec 7it variable mn naw3 RECTANGLE (x,y,widith,height) li 7adadnah f animation()
    //destRec fin a Nrsmo chakhsiya o b ayi 7ajm
    //{0.0f,0.0f}
    //ki kon float had lkhana o k ndiro fiha zawiyat dawaran 7it brina chakhsiya tw9f m9ada o machi mayla b 90 daraja aw chi zawiya okhera
    //white ki 3ni rsm chakhsiya b alwanha l79i9IYA 
}

Player::Player(const Player& Player2)
{
    this->currentframe = Player2.currentframe;
    this->animRow = 1;
    this->animspeed = Player2.animspeed;
    this->timer = Player2.timer;
    this->speed = Player2.speed;
    this->scale = Player2.scale;
    this->position = Player2.position;
    this->destRec = Player2.destRec;
    this->frametall = 4;
    this->frameHeight = Player2.frameHeight;
    this->framewide = 4;
    this->framewidth = Player2.framewidth;
    this->imageplayer = LoadTexture("C:/Users/zeko_/OneDrive/Bureau/ILSI/player2");
    this->sourceRec=Player2.sourceRec;
}
