#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <vector>
#include <numeric>
#include <stdio.h>
using namespace std;
int sum=0;
bool z=true;
bool fullhouse=false;
bool q=true;
bool e=true;
void choosecardvalue(int& a){
    a=rand()%13+1;
}
void choosesuit(int& a){
    a=rand()%4+1;
    }
void facecard(int a){
    if(a==11){
        cout<<"Jack";
    }
    else if(a==12){
        cout<<"Queen";
    }
    else if(a==13){
        cout<<"King";
    }
    else if(a==1){
        cout<<"Ace";
    }
    else{
        cout<<a;
    }
}
void suits(int a){
    if(a==1){
        cout<<"Hearts";
    }
    else if(a==2){
        cout<<"Diamonds";
    }
    else if(a==3){
        cout<<"Clubs";
    }
    else if(a==4){
        cout<<"Spades";
    }
}
bool fullhous(int a[5]){//a[5]=temp[5]or tempc[5]
    if(binary_search(a, a+5, 2)&&binary_search(a,a+5, 3)){
        return true;
    }
        return false;
}
bool twopair(int a[5]){
    if(count(a, a+5, 2)==4){
        return true;
    }
    return false;
}
bool cardcombo(int a){//a=playcount or compcount and b=playtype or comptype
    switch(a){
        case 1: return false;
            break;
        case 2:

        return true;
                break;
        case 3:if(!fullhouse){
            }
             return true;
                break;
        case 4:
        return true;
                break;
        case 5:
        return true;
                break;
        default: cout<<"wtf man";
        return false;
    }
}
bool straightflush(int a[5], int b[5], int c){//c=playcount or compcount
    if(!cardcombo(c)){
        sort(a, a+5);
        if(accumulate(a,a+5, 0)==a[0]*5+10){
            for(int i=0; i<5; i++){
                if(b[i]!=b[0]){
                    q=false;
                }
            }
            if(q){
                return true;
            }
        }
    }
    return false;
}
bool RoyalFlush(int a[5], int b, int c[5]){//b=playcount or compcount
    if(!cardcombo(b)){
        for(int i=0; i<5; i++){
            sum+=a[i];
            if(c[i]!=c[0]){
                return false;
            }
        }
        if(sum==47){
            return true;
        }
    }
        return false;

    /*bool jack=false;
    bool queen=false;
    bool king=false;
    bool ace=false;
    bool allsame=true;
    for(int i=0; i<5; i++){
        if(a[i][0]==11){
            jack=true;
        }
        if(a[i][0]==12){
            queen=true;
        }
        if(a[i][0]==13){
            king=true;
        }
        if(a[i][0]==1){
            ace=true;
        }
        if(a[i][1]!=a[0][1]){
            allsame=false;
        }
    }
    if(jack&&queen&&king&&ace&&allsame){
        return true;
    }
    return false;*/
}
bool regularflush(int b[5]){
        for(int i=0; i<5; i++){
            if(b[i]!=b[0]){
                e=false;
            }
        }
    return e;
}
bool straight(int a[5], int b[5], int c){
    if(!cardcombo(c)){
        sort(a, a+5);
        if(accumulate(a,a+5, 0)==a[0]*5+10){
            for(int i=0; i<5; i++){
                if(b[i]!=b[0]){
                    q=false;
                }
            }
            if(!q){
                return true;
            }
        }
    }
    return false;
}
void highercard(int a[5], int b[5], string& c){//a=player, b=comp
    if(max_element(a, a+5)>max_element(b, b+5)){
        c="You";
    }
    else{
        c="The house";
    }
}
    int main()
{
    int playagain=true;
    int thing=0;
    int playtype;
    int comptype;
    srand (time(NULL));
    int mycards[5];
    int mysuits[5];
    int compcards[5];
    int compsuits[5];
    ifstream fin("money.txt");
    cout<<setw(30)<<"Welcome to Austin Casino! Care for a game of blackjack? \n";
    int money;
    int playcount=1;
    int compcount=1;
    int temp[5];
    int tempc[5];
    int switchchoice;
    bool o=true;
    int u=0;
    bool keepemhonest[5];
    int bet=0;
    string winner;
    int chosenp;
    int chosenc;
    int h;
    int d;
    fin>>d;
    if(!fin){
            cout<<setw(30)<<"Here's 1000 chips, free of charge, just to show that we're the best casino in town. ";
        money=1000;
    }
    else{
        money=d;
        cout<<"You have "<<money<<" left. ";
    }
    cout<<"Have fun!";
while(playagain){
        o=true;
bet=0;
thing=0;
u=0;
    cout<<"\nHere are your cards: \n";
    for(int i=0; i<5; i++){
            temp[i]=0;
            tempc[i]=0;
            keepemhonest[i]=true;
        choosecardvalue(mycards[i]);
        choosecardvalue(compcards[i]);
        choosesuit(mysuits[i]);
        choosesuit(compsuits[i]);
        facecard(mycards[i]);
        cout<<" of ";
        suits(mysuits[i]);
        if(i!=4){
            cout<<", ";
        }
    }
    while(o){
            if(u>0){
                cout<<"\nHow much more would you like to bet?\n";
                cin>>thing;
                bet+=thing;
                if(bet>money){
                    cout<<setw(30)<<"Whoa there! You don't have enough chips for that bet! If you want more, mail me some cash and I'll send you some chips\n";
                    cout<<setw(30)<<"Try again.\n";
                    cin>>thing;
                    bet-=thing;
                }
            }
            else if(u==0){
                cout<<"\nHow much would you like to bet?\n";
                cin>>bet;
                if(bet>money){
                    cout<<setw(30)<<"Whoa there! You don't have enough chips for that bet! If you want more, mail me some cash and I'll send you some chips\n";
                    cout<<"Make a new bet.\n";
                    cin>>bet;
                }
            }
            cout<<setw(30)<<endl<<"Would you like to switch any cards? Press 1 to switch out your first card, 2 for your second card, etc. Press 0 if you do not want to switch any cards.";
            cout<<setw(30)<<"\nYou may only switch each card once. \n";
            cin>>switchchoice;
            switch(switchchoice){
                    case 0: o=false;
                    continue;
                    break;
                    case 1: if(keepemhonest[0]){
                            choosecardvalue(mycards[0]);
                            choosesuit(mysuits[0]);
                            keepemhonest[0]=false;
                            }
                    break;
                    case 2: if(keepemhonest[1]){
                            choosecardvalue(mycards[1]);
                            choosesuit(mysuits[1]);
                            keepemhonest[1]=false;
                            }
                    break;
                    case 3: if(keepemhonest[2]){
                            choosecardvalue(mycards[2]);
                            choosesuit(mysuits[2]);
                            keepemhonest[2]=false;
                            }
                    break;
                    case 4: if(keepemhonest[3]){
                            choosecardvalue(mycards[3]);
                            choosesuit(mysuits[3]);
                            keepemhonest[3]=false;
                            }
                    break;
                    case 5: if(keepemhonest[4]){
                            choosecardvalue(mycards[4]);
                            choosesuit(mysuits[4]);
                            keepemhonest[4]=false;
                            }
                    break;
                    default: cout<<"\nYou screwed up. Try again. Remember to only put one number at a time and that only numbers between 0 and 5 are valid.\n";
            }
            cout<<"Here are your new cards"<<endl;
            for(int i=0; i<5; i++){
                facecard(mycards[i]);
                cout<<" of ";
                suits(mysuits[i]);
                if(i!=4){
                cout<<", ";
                }
            }
            u++;
    }
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(mycards[j]==mycards[i]){
                temp[i]++;
                h=mycards[i];
            }
        }
        if(playcount<temp[i]){
            playcount=temp[i];
            chosenp=h;
        }

        for(int j=0; j<5; j++){
            if(compcards[j]==compcards[i]){
                tempc[i]++;
                h=compcards[i];
            }
        }
        if(compcount<tempc[i]){
            chosenc=h;
            compcount=tempc[i];
        }
    }
    if(RoyalFlush(mycards, playcount, mysuits)){
        playtype=10;
    }
    else if(straightflush(mycards, mysuits, playcount)){
        playtype=9;
    }
    else if(playcount==4){
        playtype=8;
    }
    else if(fullhous(temp)){
        playtype=7;
    }
    else if(regularflush(mysuits)){
        playtype=6;
    }
    else if(straight(mycards, mysuits, playcount)){
        playtype=5;
    }
    else if(playcount==3){
        playtype=4;
    }
    else if(twopair(temp)){
        playtype=3;
    }
    else if(playcount==2){
        playtype=2;
    }
    else{
        playtype=1;
    }
    if(RoyalFlush(compcards, compcount, compsuits)){
        comptype=10;
    }
    else if(straightflush(compcards, compsuits, compcount)){
        comptype=9;
    }
    else if(compcount==4){
        comptype=8;
    }
    else if(fullhous(tempc)){
        comptype=7;
    }
    else if(regularflush(compsuits)){
        comptype=6;
    }
    else if(straight(compcards, compsuits, compcount)){
        comptype=5;
    }
    else if(compcount==3){
        comptype=4;
    }
    else if(twopair(tempc)){
        comptype=3;
    }
    else if(compcount==2){
        comptype=2;
    }
    else{
        comptype=1;
    }
    if(playtype>comptype){
        winner="You";

    }

    else if(playtype<comptype){
        winner="The house";
    }
    else if(playtype==1 &&comptype==1){
        highercard(mycards,compcards,winner);
    }

    if(playtype>comptype){
        cout<<setw(30)<<endl<<"You "<<"win! Congratulations!";
        money+=bet;
    }
    else if(playtype==comptype){
        if(chosenc>=chosenp){
            cout<<setw(30)<<"\nToo bad! "<<"The house "<<"wins! Better luck next time!\n";
        money-=bet;
        }
        if(chosenp>chosenc){
            cout<<setw(30)<<"\nYou "<<"win! Congratulations!";
        money+=bet;
        }
    }
    else{
        cout<<setw(30)<<"\nToo bad! "<<"The house "<<"wins! Better luck next time!\n";
        money-=bet;
    }
    cout<<"Your opponent's cards were:\n";
            for(int i=0; i<5; i++){
                facecard(compcards[i]);
                cout<<" of ";
                suits(compsuits[i]);
                if(i!=4){
                cout<<", ";
                }
            }
    cout<<"\nYou have "<<money<<" chips left\n";
    cout<<setw(30)<<"Would you like to play again? Press 1 for yes and 0 for no.\n";
    cin>>playagain;
}
ofstream fou("money.txt");
fou<<money;
    return 0;
}
