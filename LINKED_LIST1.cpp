#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <strings.h>
int count = 0;
using namespace std;
struct node
{
	int info;
	struct node *next;
};
struct node *pfirst = NULL, *pthis;

void insertatbeg(int va)
{
	struct node *pnew = (struct node *)malloc(sizeof(struct node));
	count++;
	pnew->info = va;
	if (pfirst == NULL)
	{
		cout << "The list is empty\n";
		pfirst = pnew;
		pfirst->next = NULL;
	}
	else
	{
		pnew->next = pfirst;
		pfirst = pnew;
	}
}
void insertatend(int va)
{
	count++;
	struct node *pnew = (struct node *)malloc(sizeof(struct node)), *pthis;
	pnew->info = va;
	if (pfirst == NULL)
	{
		cout << "The list is empty\n";
		pfirst = pnew;
		pnew->next = NULL;
	}
	else
	{
		pthis = pfirst;
		while (pthis->next != NULL)
		{
			pthis = pthis->next;
		}
		pthis->next = pnew;
		pnew->next=NULL;
	}
}
void Insert_after_spec_node(int va)
{   count++;
	int loc;
	struct node *pthis, *ptemp, *pnew = (struct node *)malloc(sizeof(struct node));
	pnew->info = va;
	cout << "Enter the location of the specified node";
	cin >> loc;
     if (pfirst == NULL)
         {
             pfirst = pnew;
             pnew->next = NULL;
         }
	else
	{

		pthis = pfirst;
		for (int i = 1; i < loc; i++)
		{
			pthis = pthis->next;
		}
		ptemp = pthis->next;
		pthis->next = pnew;
		pnew->next = ptemp;
	}
}
void Insert_before_spec_node(int va)
{   count++;
	int loc;
	struct node *pthis, *ptemp, *pnew = (struct node *)malloc(sizeof(struct node));
	pnew->info = va;
	cout << "Enter the location of the specified node";
	cin >> loc;
	 if (pfirst == NULL)
         {
             pfirst = pnew;
             pnew->next = NULL;
         }
	else
	{
		if(loc==0)
		{
			insertatbeg(va);
		}
		else{

		pthis = pfirst;
		for (int i = 1; i < loc - 1; i++)
		{
			pthis = pthis->next;
		}
		ptemp = pthis->next;
		pthis->next = pnew;
		pnew->next = ptemp;
		}
	}
}

void deleteatbeg()
{
	count--;

	struct node *ptemp;
	if (pfirst == NULL)
	{
		cout << "\nlist is empty";
		exit(0);
	}
	else if (pfirst->next == NULL)
	{
		free(pfirst);
		pfirst = NULL;
	}
	else
	{
		ptemp = pfirst->next;
		free(pfirst);
		pfirst = ptemp;
	}
}
void deleteatend()
{
	count--;
	struct node *ptemp, *pthis;
	if (pfirst == NULL)
	{
		cout << "list is empty";
		exit(0);
	}
	else if (pfirst->next == NULL)
	{
		free(pfirst);
		pfirst = NULL;
	}
	else
	{
		pthis = pfirst;
		while (pthis->next->next != NULL)
		{
			pthis = pthis->next;
		}
		free(pthis->next);
		pthis->next = NULL;
	}
}
void DeleteSpecifiedNode()
{   count--;
    struct node *pthis, *ptemp;
    int l;
    cout << "\nEnter the location of the node:";
    cin >> l;
    if (pfirst->next == NULL)
    {
        cout << "The deleted data is:" << pfirst->info;
        free(pfirst);
        pfirst = NULL;
    }
    else
    {
        pthis = pfirst;
        for (int i = 1; i < l - 1; i++)
        {
            pthis = pthis->next;
        }
        cout << "The deleted data is:" << pthis->next->info;
        ptemp = pthis->next->next;
        free(pthis->next);
        pthis->next = ptemp;
    }
}


 void graphicsr(int c,string data,string NextAddr)
{
    switch (c)
    {
    case 1:
    {
        rectangle(100 + 4, 104, 208 - 2, 150 - 4);
        rectangle(208 + 2, 104, 315 - 4, 150 - 4);

        rectangle(100, 100, 315, 150);
        settextstyle(9,0,1);
        // formula to keep the text in the box midpoint of the box x+10 and y  - 10
        outtextxy(100+50+10,125-10,const_cast<char*>(data.c_str()) );
        outtextxy(210+50,125-10,const_cast<char*>(NextAddr.c_str()));


        break;
    }
    case 2:
    {
        line(315 - 4, 125, 415, 125);
        rectangle(415 + 4, 104, 523 - 2, 146);
        rectangle(523 + 2, 104, 630 - 4, 146);

        rectangle(415, 100, 630, 150);
        settextstyle(9,0,1);
        outtextxy(419+61,125-10,const_cast<char*>(data.c_str()));
        outtextxy(525+50,125-10,const_cast<char*>(NextAddr.c_str()));

        break;
    }
    case 3:
    {
        line(630 - 4, 125, 730, 125);
        rectangle(730 + 4, 104, 838 - 2, 150 - 4);
        rectangle(838 + 2, 104, 945 - 4, 150 - 4);

        rectangle(730, 100, 945, 150);
        settextstyle(9,0,1);
        outtextxy(730+61,125-10,const_cast<char*>(data.c_str()));
        outtextxy(840+50,125-10,const_cast<char*>(NextAddr.c_str()));
        break;
    }
    case 4:
    {
        line(945 - 4, 125, 1045, 125);

        rectangle(1045 + 4, 104, 1153 - 2, 150 - 4);
        rectangle(1153 + 2, 104, 1260 - 4, 150 - 4);

        rectangle(1045, 100, 1260, 150);
         settextstyle(9,0,1);
       outtextxy(1110,125-10,const_cast<char*>(data.c_str()));
       outtextxy(1155+50,125-10,const_cast<char*>(NextAddr.c_str()));
        break;
    }
    case 5:
    {
        line(1260, 125, 1310, 125);
        line(1310, 125, 1310, 325);
        line(1310, 325, 1260, 325);

        rectangle(1045 + 4, 104 + 200, 1153 - 2, 150 - 4 + 200);
        rectangle(1153 + 2, 104 + 200, 1260 - 4, 150 - 4 + 200);

        rectangle(1045, 300, 1260, 350);
         settextstyle(9,0,1);
        outtextxy(1049+61,325-10,const_cast<char*>(data.c_str()));
        outtextxy(1155+50,325-10,const_cast<char*>(NextAddr.c_str()));


        break;
    }
    case 6:
    {

        line(945 - 4, 325, 1045, 325);
        rectangle(730 + 4, 104 + 200, 838 - 2, 150 - 4 + 200);
        rectangle(838 + 2, 104 + 200, 945 - 4, 150 - 4 + 200);

        rectangle(730, 300, 945, 350);
        settextstyle(9,0,1);
        outtextxy(734+61,325-10,const_cast<char*>(data.c_str()));
        outtextxy(840+50,325-10,const_cast<char*>(NextAddr.c_str()));


        break;
    }
    case 7:
    {

        line(630 - 4, 325, 730, 325);
        rectangle(415 + 4, 104 + 200, 523 - 2, 146 + 200);
        rectangle(523 + 2, 104 + 200, 630 - 4, 146 + 200);

        rectangle(415, 300, 630, 350);
        settextstyle(9,0,1);
        outtextxy(419+61,325-10,const_cast<char*>(data.c_str()));
        outtextxy(525+50,325-10,const_cast<char*>(NextAddr.c_str()));


        break;
    }
    case 8:
    {     line(315 - 4, 325, 415, 325);
         rectangle(100 + 4, 104 + 200, 208 - 2, 150 - 4 + 200);
        rectangle(208 + 2, 104 + 200, 315 - 4, 150 - 4 + 200);

        rectangle(100, 300, 315, 350);
settextstyle(9,0,1);
        outtextxy(104+61,325-10,const_cast<char*>(data.c_str()));
        outtextxy(210+50,325-10,const_cast<char*>(NextAddr.c_str()));
        break;
    }
    case 9:
    {
        line(100, 325, 50, 325);
        line(50, 325, 50, 525);
        line(50, 525, 100, 525);

        rectangle(100 + 4, 104 + (2 * 200), 208 - 2, 150 - 4 + (2 * 200));
        rectangle(208 + 2, 104 + (2 * 200), 315 - 4, 150 - 4 + (2 * 200));

        rectangle(100, 300 + 200, 315, 350 + 200);
        settextstyle(9,0,1);
        outtextxy(104+61,525-10,const_cast<char*>(data.c_str()));
        outtextxy(210+50,525-10,const_cast<char*>(NextAddr.c_str()));

        break;
    }
    case 10:
    {
        line(315 - 4, 525, 415, 525);
        rectangle(415 + 4, 104 + (2 * 200), 523 - 2, 146 + (2 * 200));
        rectangle(523 + 2, 104 + (2 * 200), 630 - 4, 146 + (2 * 200));

        rectangle(415, 300 + 200, 630, 350 + 200);
        settextstyle(9,0,1);
        outtextxy(419+61,525-10,const_cast<char*>(data.c_str()));
        outtextxy(525+50,525-10,const_cast<char*>(NextAddr.c_str()));
        break;
    }
    case 11:
    {
        line(630 - 4, 525, 730, 525);
        rectangle(730 + 4, 104 + (2 * 200), 838 - 2, 150 - 4 + (2 * 200));
        rectangle(838 + 2, 104 + (2 * 200), 945 - 4, 150 - 4 + (2 * 200));

        rectangle(730, 300 + 200, 945, 350 + 200);
        settextstyle(9,0,1);
        outtextxy(734+61,525-10,const_cast<char*>(data.c_str()));
        outtextxy(840+50,525-10,const_cast<char*>(NextAddr.c_str()));
        break;
    }
    case 12:
    {
        line(945 - 4, 525, 1045, 525);
        rectangle(1045 + 4, 104 + (2 * 200), 1153 - 2, 150 - 4 + (2 * 200));
        rectangle(1153 + 2, 104 + (2 * 200), 1260 - 4, 150 - 4 + (2 * 200));

        rectangle(1045, 300 + 200, 1260, 350 + 200);
        settextstyle(9,0,1);
       outtextxy(1049+61,525-10,const_cast<char*>(data.c_str()));
       outtextxy(1155+50,525-10,const_cast<char*>(NextAddr.c_str()));
        break;
    }
    default:
        break;
    }

}




 void display()
 {
     int pos=1;
     initwindow(getmaxwidth(),getmaxheight(),"Display window");
     settextstyle(9, 0, 4);
    settextjustify(1, 2);
    setcolor(RGB(247, 181, 5));
    outtextxy(getmaxwidth() / 2, 40, "Singly Linked List");
    pthis=pfirst;
do{
        cout<<"i am dummy";
        stringstream nn;
      string dat,locat;
      if(pthis==NULL)
      {
          outtextxy(getmaxwidth()/2,getmaxheight()/2,"NO  any node");
          break;

      }
      else
      {
        nn << hex << reinterpret_cast<std::uintptr_t>(pthis->next);
      locat=nn.str();
      if(locat=="\0")
      {
          locat="NULL";
      }
      dat=to_string(pthis->info);
      graphicsr(pos,dat,locat);
      pos++;
      }
      pthis=pthis->next;
} while(pthis!=NULL);


getch();
closegraph();

 }
int main()
{
	int c, value;
	char g;
	bool vari = 0;
	do
	{
	 system("cls");
		cout << "--------------Main menu-----------------\n";
		cout << "1.Inserting the node at begining \n";
		cout << "2.Inserting the node at the end\n";
		cout << "3.Inserting a node before the specified node\n";
		cout << "4.Inserting a node after the specified node\n";
		cout << "5.Deleting the node at begining \n";
		cout << "6.Deleting the node at the end\n";
		cout << "7.Deleting a node before or after the specified node\n";
		cout << "8.Display\n";
		cout << "9.exit\n";
		cout<<"Enter the choice: ";
		cin >> c;
		switch (c)
		{
		case 1:
			{
				cout << "Enter the value to insert (max 3 digit allowed) \n";
				cin >> value;
				insertatbeg(value);
			}

			break;
		case 2:

			{
				cout << "Enter the value to insert(max 3 digit allowed) \n";
				cin >> value;
				insertatend(value);
			}

			break;
		case 3:
		{

			{
				cout << "Enter the value to insert(max 3 digit allowed) \n";
				cin >> value;
				Insert_before_spec_node(value);


			}
			break;
		}
		case 4:
		{
				cout << "Enter the value to insert(max 3 digit allowed)\n";
				cin >> value;
				Insert_after_spec_node(value);

			break;
		}
		case 5:

		{

				deleteatbeg();
				break;
		}

		case 6:
		{
				deleteatend();

			break;
		}
		case 7:
		{
			DeleteSpecifiedNode();
			break;
		}
		case 8:
		{
				display();
			break;

		}
		case 9:
		{
			cout<<"\nWE are exiting."<<endl;
			break;
		}
		 default:
		 	cout << "Wrong input please try again!!";
		 }

	} while (c !=9);
	return 0;
}
