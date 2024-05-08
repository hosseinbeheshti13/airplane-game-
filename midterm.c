#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
void my_air(int y, int x);
void my_air2(int y, int x);
void create_win(WINDOW *win);
void create_win2(WINDOW *win2);
void create_win2(WINDOW *win3);
void login();
void start();
void start2();
void fly();
void fly2();
void lose_game();
void hurdle(int y , int x);
void remove_hurdle(int y , int x);
void hurdle2(int y , int x);
void remove_hurdle2(int y , int x);
void remove_my_air(int y, int x);
void remove_my_air2(int y, int x);
int random_hurdle();
int random_hurdle2();
int high_score=0;//use  glubal high score
char name[100];//use  glubal name
int main() {
    initscr(); 
    curs_set(0);
    int score = 0;
    login();
    endwin();
    getch();
    return 0;
}
void start(){
    
    WINDOW *win;
    win=newwin(24,20,0,0);
    create_win(win);
    WINDOW *win2;
    win2=newwin(10,10,30,20);
    create_win2(win2);
    fly();
  
}//function  and my air fly function for my second air
void start2(){
    
    WINDOW *win;
    win=newwin(24,20,0,0);
    create_win(win);
    WINDOW *win2;
    win2=newwin(10,10,30,20);
    create_win2(win2);
    fly2();
  
}//function  and my air fly function for my second air
void my_air(int y, int x){

    mvprintw(y  ,x, " ____/\\____");
    mvprintw(y+1,x, " \\$$$$$$$$/");
    mvprintw(y+2,x, "  \\$$$$$$/ ");
    mvprintw(y+3,x, "  /**$$**\\ ");
    mvprintw(y+4,x, " /**$$$$**\\");
    mvprintw(y+5,x, "  |*$$$$*|  ");
    mvprintw(y+6,x, "  |*&&&&*|  ");
    mvprintw(y+7,x, "   \\/  \\/  ");
   refresh();
   
}//plot of my first air
void remove_my_air(int y, int x){
    mvprintw(y,x   ,"            ");
    mvprintw(y+1, x,"            ");
    mvprintw(y+2, x,"            ");
    mvprintw(y+3, x,"            ");
    mvprintw(y+4, x,"            ");
    mvprintw(y+5, x,"            ");
    mvprintw(y+6,x ,"            ");
    mvprintw(y+7,x ,"            ");
    refresh();
}//my idea to remove my air after fly
void my_air2(int y , int x)
{
    mvprintw(y,x,  "   /\\   ");
    mvprintw(y+1,x,"  ($$$)  ");
    mvprintw(y+2,x,"  ($$$)  ");
    mvprintw(y+3,x," /$$$$$\\");
    mvprintw(y+4,x,"/$$$$$$$\\");
    mvprintw(y+5,x,"\\$$/\\$$/");
    mvprintw(y+6,x," \\/  \\/ ");
    refresh();
}//plot of my second air
void remove_my_air2(int y , int x)
{
    mvprintw(y,x,  "           ");
    mvprintw(y+1,x,"           ");
    mvprintw(y+2,x,"           ");
    mvprintw(y+3,x,"           ");
    mvprintw(y+4,x,"           ");
    mvprintw(y+5,x,"           ");
    mvprintw(y+5,x,"           ");
    mvprintw(y+6,x,"           ");
    refresh();
}//my idea to remove my air after fly
void create_win(WINDOW *win){
    win =newwin(30, 80,0 , 0);
    refresh();
    box(win , 0,0);
    wrefresh(win);
}//this function just make my login page box
void create_win2(WINDOW *win2){
    win2 =newwin(30, 30,0, 80);
    refresh();
    box(win2 , 0,0);
    wrefresh(win2);
    mvprintw(1 ,81,"$$$$$$$$$$$$$$$$$$$$$$$$$$$");
    mvprintw(2 ,81,"$$$$$$$@@@@** **@@@@$$$$$$$");
    mvprintw(3 ,81,"$$$$$$@@@@**   **@@@@$$$$$$");
    mvprintw(4 ,81,"$$$$$@@@@**     **@@@@$$$$$");
    mvprintw(5 ,81,"$$$$@@@@**       **@@@@$$$$");
    mvprintw(6 ,81,"$$$@@@@**         **@@@@$$$");
    mvprintw(7 ,81,"$$@@@@**           **@@@@$$");
    mvprintw(8 ,81,"$@@@@**             **@@@@$");
    mvprintw(9 ,81,"@@@@**               **@@@@");
    mvprintw(10,81,"@@@**                 **@@@");
    mvprintw(11,81,"@@**                   **@@");
    mvprintw(12,81,"@**                     **@");
    mvprintw(13,81,"**                       **");
    mvprintw(14,81,"*                         *");
    mvprintw(15,81,"**                        *");            
    mvprintw(16,81,"***                      **");                           
    mvprintw(17,81,"@***                    **@");                        
    mvprintw(18,81,"@@***                  **@@");                   
    mvprintw(19,81,"@@@***                **@@@");                     
    mvprintw(20,81,"@@@@***              **@@@@");                          
    mvprintw(21,81,"$@@@@***            **@@@@$");                        
    mvprintw(22,81,"$$@@@@***          **@@@@$$");                        
    mvprintw(23,81,"$$$@@@@***        **@@@@$$$");                    
    mvprintw(24,81,"$$$$@@@@***      **@@@@$$$$");                          
    mvprintw(25,81,"$$$$$@@@@***    **@@@@$$$$$");                 
    mvprintw(26,81,"$$$$$$@@@@***  **@@@@$$$$$$");
    mvprintw(27,81,"$$$$$$$@@@@** **@@@@$$$$$$$");
    mvprintw(28,81,"$$$$$$$$$$$$$$$$$$$$$$$$$$$");   
    mvprintw(10,87,"user name=%s",name);
    mvprintw(14,83,"press q twice quit game");
    refresh(); 
}//this is make my rihgt side box and i have some design
void create_win3(WINDOW *win3){
    win3 =newwin(15, 30,10,10);
    refresh();
    box(win3 , 0,0);
    wrefresh(win3);
}//make my main box of my air
void login(){
    char b;
    WINDOW *win;
    win=newwin(10,20,9,29);
    create_win(win);
    mvprintw(2,26,"ENTER YOUR NAME PLEASE:");
    scanw("%s",name);//get name from usser
    mvprintw(4,26,"welcome to my air %s ,i wish you enjoy ",name);
    mvprintw(6,26,"choose your air please...");
    mvprintw(7,26,"press R to have  right side air");
    mvprintw(8,26,"press L to have left side air");
    my_air(10,20);
    my_air2(10,40);
    b=getch();//get botten to choose air
    if(b=='L'||b=='l'){
        start();//called to first start function
    } else if(b=='R'||b=='r'){
        start2();////called to first start function
    }
    endwin();
}//desighn of login page
void hurdle(int y , int x){
    mvprintw(y    , x,"********");
    mvprintw(y+1  , x,"********");
     mvprintw(y+2 , x,"********");
    refresh();
}//my hurdle 1 plot
void remove_hurdle(int y , int x){
    mvprintw(y    , x,"         ");
    mvprintw(y+1  , x,"         ");
     mvprintw(y+2 , x,"         ");
    refresh();
}//my idea to remove my hurdle before after come down
void hurdle2(int y , int x){
    mvprintw(y    , x,"********");
    mvprintw(y+1  , x,"********");
     mvprintw(y+2 , x,"********");
    refresh();
}//my hurdle 1 plot
void remove_hurdle2(int y , int x){
    mvprintw(y    , x,"         ");
    mvprintw(y+1  , x,"         ");
    mvprintw(y+2  , x,"         ");
    refresh();
}//my idea to remove my hurdle before after come down
void lose_game(){
  int score;
  WINDOW *win3;
    win3 =newwin(15,30,0,0);
    create_win3(win3);
    mvprintw(11,11,"$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
    mvprintw(12,11,"$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
    mvprintw(13,11,"$$$@@@@@@          @@@@@@$$$");
    mvprintw(14,11,"$$$@@@@@            @@@@@$$$");
    mvprintw(15,11,"$$$@@@@   YOU LOSE   @@@@$$$");
    mvprintw(16,11,"$$$@@@                @@@$$$");
    mvprintw(17,11,"$$$@@                  @@$$$");
    mvprintw(18,11,"$$$@@@   THANKFUL TO  @@@$$$");
    mvprintw(19,11,"$$$@@@@     PLAY     @@@@$$$");
    mvprintw(20,11,"$$$@@@@@  OUR GAME  @@@@@$$$");
    mvprintw(21,11,"$$$@@@@@@          @@@@@@$$$");
    mvprintw(22,11,"$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
    mvprintw(23,11,"$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
    

    refresh();
  
}// make new box and design for when usser lose game
int random_hurdle(){
  srand(time(0));
    return rand()%66+1;
}//this function just give us random number
int random_hurdle2(){
    return rand()%66+1;
}//this function just give us random number
void fly(){
    int y=21,x=25;
    int y2=2;//another y get to hurdle to prevent from getting involved with y of air
    int x2=random_hurdle();//another x get to hurdle to prevent from getting involved with x of air
    int y3=2;//another y get to hurdle to prevent from getting involved with y of air
    int x3=random_hurdle2();//another x get to hurdle to prevent from getting involved with x of air
    int score=0;
    char ch;
    int m=0;//i use it for flag 
    while(1){
          
        remove_hurdle(y2,x2);

        if(y2!=26)
           y2++;//use it to hurdle not to go under of box


        if(y2==26){
          y2=1;//use it if hurdle arrive end come back to first
                 score++;//score increas when hurdle arrive to end of box

               x2=random_hurdle(); //give us random x
         }

        mvprintw(9,90,"score=%d",score);

            hurdle(y2,x2);

       timeout(150);
 
       remove_hurdle2(y3,x3);

        if(y3!=26)
            y3++;//use it to hurdle not to go under of box


        if(y3==26){
             y3=1;//use it if hurdle arrive end come back to first
                 x3=random_hurdle2();
          }
         
       hurdle2(y3,x3);
       timeout(150);

       if(x2<=x+11 && x2>=x-7 && y2==y-2||x3<=x+11 && x3>=x-7 && y3==y-2){//this function use for collision
         clear();
         lose_game();
         mvprintw(16,18,"YOUR SCORE = %d",score);
         if(high_score<=score)//to compare score and high score 
         high_score=score;//if score is higher than highscore ,get score equal of high score
         mvprintw(17,18,"high score =%d",high_score);
         refresh();
         sleep(3);
         endwin();
         start();//start again game
       } 
          
        ch=getch();
        if(ch=='a'||ch=='A'){
            remove_my_air(y,x);

          if(x!=1)//controll air to not break my box
            x--;//air go left

        }else if(ch=='d'||ch=='D') {
                remove_my_air(y,x);


           if(x!=60)//controll air to not break my box
             x++;//air right

        }if(ch=='w'||ch=='W'){
            remove_my_air(y,x);


         if(y==1) 
           y=17;//come back 


         if(y!=1)//controll air to not break my box
            y--;//air go up

        }else if(ch=='S'||ch=='s') {
            remove_my_air(y,x);

           if(y!=21)//controll air to not break my box
             y++;//air go down
        }else if(ch=='q'||ch=='Q'){
         clear();
         lose_game();
         refresh();
         m++;
         break;//close while function
        }
        my_air(y,x);
       
        
    }
if(m!=0)// to quit game
        endwin();
        }

 void fly2(){
    int y=21,x=25;
    int y2=2;//another y get to hurdle to prevent from getting involved with y of air
    int x2=random_hurdle();//another x get to hurdle to prevent from getting involved with x of air
    int y3=2;//another y get to hurdle to prevent from getting involved with y of air
    int x3=random_hurdle2();//another x get to hurdle to prevent from getting involved with x of air
    int score=0;//i use it for flag 
    char ch;
    int m=0;
    while(1){
        remove_hurdle(y2,x2);

        if(y2!=26)
             y2++;//use it to hurdle not to go under of box


        if(y2==26){
          y2=1;//use it if hurdle arrive end come back to first
          score++;//score increas when hurdle arrive to end of box

         x2=random_hurdle(); 
         }

        mvprintw(9,90,"score=%d",score);

       hurdle(y2,x2);

       timeout(150);
 
       remove_hurdle2(y3,x3);

        if(y3!=26)
          y3++;//use it to hurdle not to go under of box


        if(y3==26){
          y3=1;//use it if hurdle arrive end come back to first
             x3=random_hurdle2();
          }
         
       hurdle2(y3,x3);
       timeout(150);

       if(x2<=x+10 && x2>=x-8 && y2==y-2||x3<=x+10 && x3>=x-8 && y3==y-2){//this function use for collision
         clear();
         lose_game();
         mvprintw(16,18,"YOUR SCORE = %d",score);
         if(high_score<=score)//to compare score and high score 
         high_score=score;//if score is higher than highscore ,get score equal of high score
         mvprintw(17,18,"high score =%d",high_score);
         refresh();
         sleep(3);
         endwin();
         start2();//start again game
       } 
          
        ch=getch();
        if(ch=='a'||ch=='A'){
            remove_my_air2(y,x);

          if(x!=1)//controll air to not break my box
            x--;//air go left

        }else if(ch=='d'||ch=='D') {
            remove_my_air2(y,x);


           if(x!=60)//controll air to not break my box
             x++;//air right

        }if(ch=='w'||ch=='W'){
            remove_my_air2(y,x);


         if(y==1) 
           y=17;//come back 


         if(y!=1)//controll air to not break my box
            y--;//air go up

        }else if(ch=='S'||ch=='s') {
            remove_my_air2(y,x);

           if(y!=21)//controll air to not break my box
             y++;//air go down
        }else if(ch=='q'||ch=='Q'){
         clear();
         lose_game();
         refresh();
         m++;
         break;//close while function
        }
        my_air2(y,x);
       
        
    }
        if(m!=0)// to quit game
          endwin();
        }