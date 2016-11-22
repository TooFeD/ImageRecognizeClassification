//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
#include <math.h>
#include <math.hpp>
#include <tchar.h>
#include <iostream>
#include <fstream>
#pragma argsused
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
Graphics::TBitmap*cells=new Graphics::TBitmap;
Graphics::TBitmap *Etalon =new Graphics::TBitmap;
//Graphics::TBitmap *Sobel(Graphics::TBitmap *image);
//Graphics::TBitmap *img = new Graphics::TBitmap;
//Graphics::TBitmap *Sob = new Graphics::TBitmap;
Graphics::TBitmap *Try = new Graphics::TBitmap;
//Graphics::TBitmap *Test = new Graphics::TBitmap;
//Graphics::TBitmap *Etalon = new Graphics::TBitmap;
//Graphics::TBitmap*cells=new Graphics::TBitmap;

using namespace std;
bool show=1;
 struct TPixel{
	 BYTE B;
	 BYTE G;
	 BYTE R;
 };
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::N2Click(TObject *Sender)
{
	if(!show)    //���� ���� ��������
	 {
		 Image2->Picture->Bitmap=0;       //������� ������
		  Image2->Canvas->Draw(0,0,Sob); //������ ���� � ��������
		 show=1;                    //���� ���������
	 }
	 else {  //� ��������� ������
	 Image2->Canvas->Draw(0,0,Sob);      //������ ���� � ��������
	 Image2->Canvas->Draw(0,0,cells);show=0; //� �� ��� ���� � ������
}
}
//---------------------------------------------------------------------------

	void __fastcall TForm2::FormCreate(TObject *Sender)
{
cells->Transparent=1;              //�������� ������������ � ������� � �����, ����� �� �� ���������� ������ � ��������
cells->TransparentColor=clWhite;  //���� ������������ - �����
cells->Canvas->Pen->Color=clGray;
  //������� ����� �������� ��������� ��� ������� Image1
cells->Width=Form3->Image1->Width;       //  figurs->Width=Image1->Width;
cells->Height=Form3->Image1->Height;	 //figurs->Height=Image1->Height;
 //��� ��� ������ ������������ ����
int size=15; //������ ����� ������
   for(int i=0;i<Form3->Image1->Width;i+=size)
   {
	  for(int j=0;j<Form3->Image1->Height;j+=size)
   {
	  cells->Canvas->Rectangle(i,j,i+size,j+size);
   }
	  }

   Image2->Canvas->Draw(0,0,cells);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N3Click(TObject *Sender)
{
	int i ;
	int j;
	int size=15;
		for (i = 0; i < Sob->Width; i+=size) {
			for (j = 0; j < Sob->Height; j+=size) {
				if (cells->Canvas->Pixels[i][j]!= clWhite && Sob->Canvas->Pixels[i][j] != clWhite) {
				Image2->Canvas->Pixels[i][j] = clBlue;
			   //	Image2->Canvas->LineTo(i, j);
												}
	}
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N4Click(TObject *Sender)
{
int i ;
	int j;
	int MaxW=0,MaxH=0,MinW=Sob->Width,MinH=Sob->Height;
	int MaxW2=0,MaxH2=0,MinW2=Sob->Width,MinH2=Sob->Height;
		for (i = 1; i < Sob->Width; i++) {
				for (j = 1; j < Sob->Height; j++){
					if (Sob->Canvas->Pixels[i][j]!=clWhite) {
						Image2->Canvas->Pixels[i][j] = clRed;
						Image2->Canvas->Pixels[i][j] = clRed;
						break;
					}

				}

		}

		for (i = 1; i < Sob->Width; i++) {
			 for (j = Sob->Height-10; j > 0; j--) {
				 if (Sob->Canvas->Pixels[i][j]!=clWhite) {
						  Image2->Canvas->Pixels[i][j] = clRed;
						 Image2->Canvas->Pixels[i][j] = clRed;
						 break;
					}
			}
		}
	 Try = Image2->Picture->Bitmap;
   // Image2->Canvas->CopyRect(Try,Image2->Canvas,Image2);
	  //Image1->Canvas->Draw(0,0,Try);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N5Click(TObject *Sender)
{
int Count=0,OwnCount=0;
	 OpenPictureDialog1->Execute();
	 Etalon->LoadFromFile(OpenPictureDialog1->FileName);
		for (int i = 0; i < Try->Width; i++) {
			for (int j = 0; j < Try->Height; j++){
				if (Try->Canvas->Pixels[i][j]==clRed) {
					Count+=1;
				}
			}
	}

	 for (int i = 0; i < Try->Width; i++) {
			for (int j = 0; j < Try->Height; j++){
				if (Try->Canvas->Pixels[i][j]==clRed && Etalon->Canvas->Pixels[i][j]==clBlack) {
					OwnCount+=1;
				}
			}
	}
	   //	Image2->Picture->Bitmap = NULL;
	  //	Etalon->Transparent=true;
	   //	Image2->Canvas->Draw(0,0,Etalon);
		Image2->Canvas->Draw(0,0,Try);
	 float mach = (float)OwnCount/Count *100;
   //	 Label1->Caption = FloatToStr(RoundTo(mach,-2))+"% ���������";
     Application->Title="��������� � ��������";
	 ShowMessage(FloatToStr(RoundTo(mach,-2))+"% ���������");

	// Etalon->graphics::-tbitmap();

}
//---------------------------------------------------------------------------

void __fastcall TForm2::N6Click(TObject *Sender)
{
int i ;
	int j;
	int MaxW=0,MaxH=0,MinW=Sob->Width,MinH=Sob->Height;
	int MaxW2=0,MaxH2=0,MinW2=Sob->Width,MinH2=Sob->Height;
	Image2->Picture->Bitmap = NULL;
	Etalon->Transparent=true;
	Image2->Canvas->Draw(0,0,Etalon);
		for (i = 1; i < Sob->Width/2; i++) {
				for (j = 1; j < Sob->Height; j++){
					if (Sob->Canvas->Pixels[i][j]!=clWhite) {
						 if (MaxH<j) {
							 MaxH=j;

						 }
						 if (MinH>j) {
							 MinH=j;

						 }

					}
					Image2->Canvas->Pixels[i][MaxH] = clRed;
						Image2->Canvas->Pixels[i][MinH] = clRed;
				}
		}

		for (i = Sob->Width-1; i > Sob->Width/2; i--) {
			for (j = MaxH; j > MinH; j--) {
				 if (Sob->Canvas->Pixels[i][j]!=clWhite) {
						 if (MaxH2<j) {
							 MaxH2=j;

						 }
						 if (MinH2>j) {
							 MinH2=j;

						 }
						 Image2->Canvas->Pixels[i][MaxH2] = clRed;
						 Image2->Canvas->Pixels[i][MinH2] = clRed;
					}
			}
		}
	 Try = Image2->Picture->Bitmap;
/*int w= Etalon->Width;
int h= Etalon->Height;
for(int x=0;x<w;x++)
  for(int y=20;y<70;y++)
  {
  int p=Etalon->Canvas->Pixels[x][y];
  int b= (GetBValue(p)+k<255)?(GetBValue(p)+k):255;
  int r= (GetRValue(p)+k<255)?(GetRValue(p)+k):255;
  int g= (GetGValue(p)+k<255)?(GetGValue(p)+k):255;

  if(b<0) b=0; if(g<0) g=0; if(r<0) r=0;

  Image2->Canvas->Pixels[x][y] = (TColor)RGB(r,g,b);//������
  }
 // Image2->
  //Image2->Canvas->Draw(0,0,Etalon);     */
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N7Click(TObject *Sender)
{
	ofstream fout;
	fout.open("coordinates.txt");
	int i=0,j=0,startX=0,startY=0,MinH[1000],MinH2[1000],MaxH[1000],as=0,ii=0,endX=0,endY=0;
	memset (MaxH, 0, sizeof (MaxH));
	for (int i = 1; i < Try->Width; i++) {
			if (startX==0) {
				for (int j = 1; j < Try->Height; j++)  {
					if (Try->Canvas->Pixels[i][j]==clRed){
						startX=i;
						startY=j;
						fout << "X= "<<i<<"\tY="<<j<<"\n";
						break;
						}
					}
				}
		else break;
	}
	Image2->Canvas->Pen->Color = clBlue;
	Image2->Canvas->Pen->Width = 2;
	Image2->Canvas->MoveTo(startX,startY);
		//  Label1->Caption = startX;
		 //  Label2->Caption = startY;
		for (i=startX; i < Try->Width; i+=30) {
			 for (int j=startY; j < Try->Height; j++){
				if (Try->Canvas->Pixels[i][j]==clRed){
					if (MinH[j]>j) {
						MinH[j]=j;
						Image2->Canvas->LineTo(i,j);
					   //	Image2->Canvas->MoveTo(i,j);
						as++;
						fout << "X= "<<i<<"\tY="<<j<<"\n";
						endX = i;
						endY = j;
					   break;
					  //	Label1->Caption = i;
					}
					   /*	if (MinH2[j]<j) {
						MinH2[j]=j;
						Image2->Canvas->LineTo(i,j);
					   //	Image2->Canvas->MoveTo(i,j);
						as++;
						fout << "X= "<<i<<"\tY="<<j<<"\n";
						endX = i;
						endY = j;
					   break;
					  //	Label1->Caption = i;
					} */

				}
			 }
		}


			for (i=(Try->Width)/2; i < Try->Width; i+=30) {
			 for (int j=(Try->Height)/2; j < Try->Height; j++){
				if (Try->Canvas->Pixels[i][j]==clRed){
				   /*	if (MinH[j]>j) {
						MinH[j]=j;
						Image2->Canvas->LineTo(i,j);
					   //	Image2->Canvas->MoveTo(i,j);
						as++;
						fout << "X= "<<i<<"\tY="<<j<<"\n";
						endX = i;
						endY = j;
					   break;
					  //	Label1->Caption = i;
					} */
						if (MinH2[j]<j) {
						MinH2[j]=j;
						Image2->Canvas->LineTo(i,j);
					   //	Image2->Canvas->MoveTo(i,j);
						as++;
						fout << "X= "<<i<<"\tY="<<j<<"\n";
						endX = i;
						endY = j;
					   break;
					  //	Label1->Caption = i;
					}
				}
			 }
		}

			Image2->Canvas->MoveTo(startX,startY);
			for (i=startX; i < Try->Width; i+=30) {
			 for (int j=startY; j > 0; j--){
				if (Try->Canvas->Pixels[i][j]==clRed){
					if (MaxH[j]<j) {
						MaxH[j]=j;
						Image2->Canvas->LineTo(i,j);
						fout << "X= "<<i<<"\tY="<<j<<"\n";
					   //	Image2->Canvas->MoveTo(i,j);
					   as++;
					   break;
					  //	Label1->Caption = i;
					}
				}
			 }
		}

				Image2->Canvas->MoveTo(endX,endY);
			   //	Image2->Canvas->LineTo(endX,endY);
			  Test = Image2->Picture->Bitmap;
			  //Label2->Caption = as;
			 fout.close();
	  /*	for (int i = 0; i < Try->Width; i++) {
			for (int j = 0; j < Try->Height; j++){
				 if (Try->Canvas->Pixels[i][j]==clRed){
					Image2->Canvas->MoveTo(startX,startY);

				 }
			}
		} */
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Image2MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	TColor color=Image2->Canvas->Pixels[X][Y];
//Label2->Caption="R="+IntToStr(GetRValue(color))+";G="+IntToStr(GetGValue(color))+";B="+IntToStr(GetBValue(color));

	//���������� �������
	for (int i = X; i < Image2->Width; i++) {
		for (int j = Y; j < Image2->Height; j++){
			if (Image2->Canvas->Pixels[i][j]!=clWhite) {
				ShowMessage("���������� � = "+IntToStr(i)+" Y= "+IntToStr(j));
				break;
			}
		}
		break;
	}

	int c = 0;

	//������� ������� ��������� �������
	Image2->Canvas->Brush->Color = clRed;
	Image2->Canvas->FloodFill(X,Y,color,fsSurface);

	//����� ������� ��������


	for(int i=1; i<=Image2->Width; i++)
		{
			for(int y=1; y<=Image2->Height; y++)
				{
				if(Image2->Canvas->Pixels[i][y]==clRed)
					{
						c++;//������� ������� ��������
					}
				}
		}
		 ShowMessage("����� = "+IntToStr(c)+" Y= ");
	   //������� �����(����������� ) ������
	   Image2->Canvas->Brush->Color = color;
	   Image2->Canvas->FloodFill(X,Y,clRed,fsSurface);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N8Click(TObject *Sender)
{
SavePictureDialog1->Execute();
Image2->Picture->SaveToFile( SavePictureDialog1->FileName );
}
//---------------------------------------------------------------------------
  int Square=0;
void __fastcall TForm2::N9Click(TObject *Sender)
{
    	ofstream fout;
	fout.open("test.txt");

	int stX=0,stY=0,fnX=0,fnY=0;
	Square=0;
	for (int j = 0; j < Try->Height; j+=10) {
			for (int i = 0; i < Try->Width ; i++){
				if (Try->Canvas->Pixels[i][j]!=clWhite) {
					Image2->Canvas->MoveTo(i,j);
					stX=i; stY=j;
					fout << "stX= "<<i<<"\tstY="<<j<<"\n";
					break;
				}
			}
			for (int i = Try->Width-5; i > 0 ; i--){
				if (Try->Canvas->Pixels[i][j]!=clWhite) {
						Image2->Canvas->LineTo(i,j);
						fnX=i; fnY=j;
						Square = ((fnX-stX)*10)+ Square;
						fout << "fnX= "<<i<<"\tfnY="<<j<< "\tSquare"<<Square<<"\n";
						break;
				}
			}
	}
		 fout.close();
		 Application->Title="����� �������";
		 ShowMessage("����� = "+IntToStr(Square)+" ��.��.");
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N10Click(TObject *Sender)
{
    Graphics::TBitmap *tmp= new Graphics::TBitmap();
//tmp->LoadFromFile("pics\\fon.bmp");
	OpenPictureDialog1->Execute();
	tmp->LoadFromFile(OpenPictureDialog1->FileName);
        Graphics::TBitmap *fon = new Graphics::TBitmap();
		Etalon->SetSize(Try->Width,Try->Height);
		Etalon->Canvas->StretchDraw(Rect(0,0,Image2->Width,Image2->Height),tmp);
	   //	Form1->Canvas->Draw(0,0,fon);

		int stX=0,stY=0,fnX=0,fnY=0,EtSquare=0;
		for (int j = 0; j < Etalon->Height; j+=10) {
			for (int i = 0; i < Etalon->Width ; i++){
				if (Etalon->Canvas->Pixels[i][j]!=clWhite) {
				   //	Image2->Canvas->MoveTo(i,j);
					stX=i; stY=j;
				   //	fout << "stX= "<<i<<"\tstY="<<j<<"\n";
					break;
				}
			}
			for (int i = Etalon->Width-5; i > 0 ; i--){
				if (Etalon->Canvas->Pixels[i][j]!=clWhite) {
					   //	Image2->Canvas->LineTo(i,j);
						fnX=i; fnY=j;
						EtSquare = ((fnX-stX)*10)+ EtSquare;
					   //	fout << "fnX= "<<i<<"\tfnY="<<j<< "\tSquare"<<Square<<"\n";
						break;
				}
			}
	}
	 ShowMessage("����� ����������= "+IntToStr(Square)+" ��.��.��." +"\n����� ������� = " +IntToStr(EtSquare)+" ��.��.��.");
}
//---------------------------------------------------------------------------
