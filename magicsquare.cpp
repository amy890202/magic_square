//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "magicsquare.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
#define MaxSize = 21;
int square[21][21];
int direction=1;
int start=5;
//---------------------------------------------------------------------------
void PrintSquare(int n)
{

	String row1; // Or AnsiString
	int len = IntToStr(n*n).Length();
	int block_len = len+3;
    //int block_len2 = len+3;
	int blank_len, i, j, k;
	int tempsum=0;
	int dialog=0;



	for (i=0; i<n; i++)
	{
        String s3="";
		for (j=0; j<n; j++)
		{
			s3=s3+" "+IntToStr(square[i][j]);

		}
		Form1->Memo2->Lines->Add(s3);
	}





	for (i=0; i<n; i++)
	{
		row1="";
		for (j=0; j<n; j++)
		{
			blank_len = len-IntToStr(square[i][j]).Length();
			for (k=0; k<blank_len; k++)
				row1 += " ";
			row1 += IntToStr(square[i][j])+" ";
		}
		Form1->Memo1->Lines->Add(row1);
	}
	// print square in StringGrid
	Form1->StringGrid1->RowCount = n+1; // why n+1?
	Form1->StringGrid1->ColCount = n+1;
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
			Form1->StringGrid1->Cells[j][i] = square[i][j];

	}
	String data_str = "";
	String data_str2 = "";

	int block_len2 = IntToStr(n*n).Length()+2;
    int block_len3 = IntToStr(n*n).Length()+2;

	// block_len2 即存放那"固定欄寬"的長度, 目前設為比n*n 數字的位數多2

	int blank_len2 = 0;
	int blank_len3 = 0;
	String s2 = ""; // 清空字串 s
	String str="";
//

	for (i=0; i<n; i++)
	{
		int sum=0;
		int sum2=0;
		String s = ""; // 清空字串
		int sum3=0;

		for(int m=0;m<n;m++)
		{
			sum3=sum3+square[m][m];

		}
		str=IntToStr(sum3);

		for (j=0; j<n; j++)
		{
			sum2 = sum2+square[j][i];
			data_str = IntToStr(square[i][j]);
			data_str2 = IntToStr(sum2);

					// square 為魔術方塊矩陣; square[i][j] 是該魔術數字

			blank_len2 = block_len2 - data_str.Length();
			blank_len3 = block_len3 - data_str2.Length();

					// 數字前的空格數= 欄寬- 數字的字元數

			for (k=0; k<blank_len2; k++)
				s += " ";

			// 在s 字串前先預放blank_len 偌多的空格
			for (k=0; k+2<blank_len3; k++)
				s2 += " ";

			s += data_str; // 將代表數字的字串, 接在s 字串之後
		   //	s2 += data_str2; // 將代表數字的字串, 接在s 字串之後
			sum = sum+square[i][j];
			//ShowMessage(square[j][i]);
			//tempsum=sum;


		}

		s=s+"/"+IntToStr(sum);
		if((tempsum!=sum && i>=1 )|| sum3!= sum)
		{
			dialog=1;

		}
		tempsum=sum;
//
		Form1->ListBox1->Items->Add(s);


	  //	ShowMessage(sum2);
		//s2 = s2+ "/"+IntToStr(sum2);
	   //	data_str2 = "/"+IntToStr(sum2);
		s2 = s2 +"/"+data_str2 ;
		if(i==n-1)
			Form1->ListBox1->Items->Add(s2+"'\'"+str);


//
	}
   //	Form1->ListBox1->Items->Add(s2);
   if(dialog==1)
   {
		ShowMessage("It is not a magic square!");
		Form1->ListBox1->Items->Add("It is not a magic square!");
		Form1->Memo1->Lines->Add("It is not a magic square!");
		Form1->Memo2->Lines->Add("It is not a magic square!");
   }
   dialog=0;

}

void MagicSquare(int n)
{
	int i, j, k, l, data;

	if ((n>21)||(n<1))
	{
	   //	ListBox1->Items->Add();
		ShowMessage("輸入方塊過大,不予處理。");

		return;
	}
	else if ((n%2)==0)
	{
		//listBox1->Items->Add("輸入方塊邊長為偶數,不予處理");
		ShowMessage("輸入方塊邊長為偶數,不予處理");

		return;
	}

	for (i=0; i<n; i++)
		for (j=0; j<n; j++)
			square[i][j] = 0;

	i = 0; j = (n-1)/2;
	if(start==5)
	{	i = 0;
		j = (n-1)/2;
	}
	else if(start==6)
	{
		i=(n-1)/2;
		j=0;
	}
	else if(start==7)
	{
		i=(n-1)/2;
		j=n-1;
		//ShowMessage(start);

	}
	else
	{
		j=(n-1)/2;
		i=n-1;

	}

	square[i][j] = 1;
	data = 2;

	while (data <= n*n)
	{
		if(direction==1) //左上
		{
			k = (i-1<0) ? n-1 : i-1;
			l = (j-1<0) ? n-1 : j-1;
			if (square[k][l] > 0)
			{
				if(start==6)//左
				{
					 j=(j+1)%n;
				}
				else if (start==8 && n%3==0)//下
				{
					 //j=(j+1)%n;
					 //ShowMessage("It's not a magic square");
					 i = (i+1)%n;
					 //ShowMessage("It's not a magic square");
				}
				else
				{
					i = (i+1)%n;
				}
			}
			else
			{
				i = k;
				j = l;
			}
		}
		else if(direction==2)  //左下
		{

			k = (i+1>n-1) ? 0 : i+1;   //下
			l = (j-1<0) ? n-1 : j-1;
			if (square[k][l] > 0)
			{

				if(start==6) //左
					j= (j+1)%n;
				else
					i = (i+1)%n;

			}
			else
			{
				i = k;
				j = l;
			}

		}
		else if(direction==3)        //右上
		{

			k = (i-1<0) ? n-1 : i-1;
			l = (j+1>n-1) ? 0 : j+1;
			if (square[k][l] > 0)
			{

				i = (i+1)%n;

			}
			else
			{
				i = k;
				j = l;
			}

		}
		else if(direction==4)              //右下
		{

			k = (i+1>n-1) ? 0 : i+1;
			l = (j+1>n-1) ? 0 : j+1;
			if (square[k][l] > 0)
				i = (i-1)%n;
			else
			{
				i = k;
				j = l;
			}

		}
		square[i][j] = data++;
	}
   // Form1->Panel2->PageControl1->TabSheet2->listBox2->Items->Add(IntToStr(n)+"?e"+IntToStr(n)+"的魔術方塊");
   /*	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
			cout<<squarepi][j]<<” ”;
	cout<<endl;
	}      */
	PrintSquare(n);
}

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Form1 -> Memo1->Lines->Clear();   //開始先清空
    Form1 -> Memo2->Lines->Clear();
	Form1->ListBox1->Items->Clear();
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{

	Form1 -> Memo1->Lines->Clear();     //開始先清空
    Form1 -> Memo2->Lines->Clear();     //開始先清空
	Form1->ListBox1->Items->Clear();
	for(int i=1;i<=4;i++)
	{

		 TRadioButton *RadioBtn=(TRadioButton *)FindComponent("RadioButton"+(String)(i));
		 if(RadioBtn->Checked==true)
			direction=i;
	}    //direction    1左上 2左下 3右上 4右下
	for(int j=5;j<=8;j++)
	{

		 TRadioButton *RadioBtn=(TRadioButton *)FindComponent("RadioButton"+(String)(j));
		 if(RadioBtn->Checked==true)
			start=j;    //5上 6左 7右 8下
	}    //start
	 int n;
	 n = StrToInt(Edit1->Text);
	 MagicSquare(n);

}
//---------------------------------------------------------------------------


