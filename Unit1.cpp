//---------------------------------------------------------------------------

#include <vcl.h>
#include <mmsystem.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int numbers [1000];
bool gameon = false;
int round = 0;
int count=0;
void seq()
{
Application->ProcessMessages(); Sleep(1000) ;

Form1->z1->Enabled = false;
Form1->z2->Enabled = false;
Form1->z3->Enabled = false;
Form1->z4->Enabled = false;
Form1->z5->Enabled = false;

Form1->Label1->Caption = "Next round in 2";
Application->ProcessMessages(); Sleep(1000) ;
Form1->Label1->Caption = "Next round in 1";
Application->ProcessMessages(); Sleep(1000) ;

Form1->Label1->Caption = "Memorize";
Application->ProcessMessages(); Sleep(1000) ;

round ++;
for (int i = 0; i<round; i++ )
{
        switch(numbers[i])
        {
        case 1:
        {
        sndPlaySound("snd/d1.wav",SND_ASYNC);
        Form1->z1a->Visible = true;}   break;
                case 2:
        {
        sndPlaySound("snd/d2.wav",SND_ASYNC);
        Form1->z2a->Visible = true;}   break;
                case 3:
        {
        sndPlaySound("snd/d3.wav",SND_ASYNC);
        Form1->z3a->Visible = true;}   break;
                case 4:
        {
        sndPlaySound("snd/d4.wav",SND_ASYNC);
        Form1->z4a->Visible = true;}   break;
                case 5:
        {
        sndPlaySound("snd/d5.wav",SND_ASYNC);
        Form1->z5a->Visible = true;}   break;
        }// switch
        Application->ProcessMessages(); Sleep(1200) ;
        Form1->z1a->Visible = false;
        Form1->z2a->Visible = false;
        Form1->z3a->Visible = false;
        Form1->z4a->Visible = false;
        Form1->z5a->Visible = false;
        Application->ProcessMessages(); Sleep(100) ;



}   // for
Form1->z1->Enabled = true;
Form1->z2->Enabled = true;
Form1->z3->Enabled = true;
Form1->z4->Enabled = true;
Form1->z5->Enabled = true;
Form1->Label1->Caption = "Your turn!";
count=0;


}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
        Form1->z1->Enabled = false;
        Form1->z2->Enabled = false;
        Form1->z3->Enabled = false;
        Form1->z4->Enabled = false;
        Form1->z5->Enabled = false;
        round = 0;
        count=0;
        gameon=false;
        
     randomize();
     for (int i=0; i<1000 ; i++)
     {
     numbers[i] = random (5)+1  ;
     }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Label1Click(TObject *Sender)
{
  if (gameon == false)
  {
       gameon = true;
       sndPlaySound("snd/start.wav", SND_ASYNC);
       seq();
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::z1Click(TObject *Sender)
{
       if (gameon==true)
       {
       count++;
       if (numbers[count-1]!=1)
                {
                round--;
                Label1->Caption = "Fail! your score: "+IntToStr(round);
                sndPlaySound("snd/koniec.wav", SND_ASYNC);
                TForm1::FormCreate(z1);
                }
       else if (count==round)
                {
                z1->Picture=buf->Picture;
                Label1->Caption = "Yay!";
                seq();
                }
       }

}
//---------------------------------------------------------------------------





void __fastcall TForm1::z2Click(TObject *Sender)
{
if (gameon==true)
       {
       count++;}
       if (numbers[count-1]!=2)
       {
        round--;
        Label1->Caption = "Fail! your score: "+IntToStr(round);
        sndPlaySound("snd/koniec.wav", SND_ASYNC);
        TForm1::FormCreate(z1);
       }
       else if (count==round)
       {
        z2->Picture=buf->Picture;
        Label1->Caption = "Yay!";
        seq();

       }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::z3Click(TObject *Sender)
{
if (gameon==true)
       {
       count++;}
       if (numbers[count-1]!=3)
       {
        round--;
        Label1->Caption = "Fail! your score: "+IntToStr(round);
        sndPlaySound("snd/koniec.wav", SND_ASYNC);
        TForm1::FormCreate(z1);
       }
       else if (count==round)
       {
        z3->Picture=buf->Picture;
        Label1->Caption = "Yay!";
        seq();

       }

        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::z4Click(TObject *Sender)
{
if (gameon==true)
       {
       count++;}
       if (numbers[count-1]!=4)
       {
        round--;
        Label1->Caption = "Fail! your score: "+IntToStr(round);
        sndPlaySound("snd/koniec.wav", SND_ASYNC);
        TForm1::FormCreate(z1);
       }
       else if (count==round)
       {
        z4->Picture=buf->Picture;
        Label1->Caption = "Yay!";
        seq();

       }

        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::z5Click(TObject *Sender)
{
if (gameon==true)
       {
       count++;}
       if (numbers[count-1]!=5)
       {
        round--;
        Label1->Caption = "Fail! your score: "+IntToStr(round);
        sndPlaySound("snd/koniec.wav", SND_ASYNC);
        TForm1::FormCreate(z1);
       }
       else if (count==round)
       {
        z5->Picture=buf->Picture;
        Label1->Caption = "Yay!";
        seq();

       }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::z1MouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
           buf->Picture=z1->Picture;
           z1->Picture=z1a->Picture;
           sndPlaySound("snd/d1.wav", SND_ASYNC);
}           
//---------------------------------------------------------------------------


void __fastcall TForm1::z2MouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
          buf->Picture=z2->Picture;
           z2->Picture=z2a->Picture;
           sndPlaySound("snd/d2.wav", SND_ASYNC);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::z3MouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
           buf->Picture=z3->Picture;
           z3->Picture=z3a->Picture;
           sndPlaySound("snd/d3.wav", SND_ASYNC);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::z4MouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
           buf->Picture=z4->Picture;
           z4->Picture=z4a->Picture;
           sndPlaySound("snd/d4.wav", SND_ASYNC);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::z5MouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
           buf->Picture=z5->Picture;
           z5->Picture=z5a->Picture;
           sndPlaySound("snd/d5.wav", SND_ASYNC);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::z1MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
z1->Picture=buf->Picture;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::z2MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
z2->Picture=buf->Picture;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::z3MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
z3->Picture=buf->Picture;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::z4MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
 z4->Picture=buf->Picture;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::z5MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
 z5->Picture=buf->Picture;
}
//---------------------------------------------------------------------------

