#pragma once

#include <stdio.h>
#include <string>
#include <queue>
#include <stack>
#include<conio.h>
#include<process.h>
#include <SFML/Audio.hpp>

class dqueue
{
	int skor=0;
	struct node
	{
		char item;
		node *next;
		

	}*front, *rear, *temp;
public: dqueue()
{
	front = NULL;
	rear = NULL;
}
		void add(char item);
		void del();
		void display();
		int ret();
		void dogruMu();
};

void dqueue::add(char item1)
{
	temp = new node();
	temp -> item=item1;

	if (front == NULL)
	{
		front = temp;
		rear = temp;
	}
	else
	{
		temp->next = NULL;
		rear->next = temp;
		rear = temp;

	}
}

//Kuyruktan eleman çýkaran fonksiyon
void dqueue::del()
{
	temp = new node();
	temp = front;
	if (front == NULL)
	{
		//std::cout << "No Data Found";
	}
	else
	{

		while (front = NULL)
		{
			front = front->next;
			delete temp;
			//std::cout << "Deleted Successfully";
		}
	}//else
}//delete


void dqueue::display()
{
	temp = new node();
	temp = front;

	while (temp != NULL)
	{
		std::cout << temp->item;
		//return temp->item;
		temp = temp->next;
	}
}

void dqueue::dogruMu()
{
	char cumle1[] = { 'G', 'i', 't', 'm', 'e', 'k', 'I', 's', 't', 'i', 'y', 'o', 'r', 'u', 'm' };           
	char cumle2[] = { 'S','e', 'n', 'l', 'e', 'G', 'i', 't', 'm', 'e', 'k', 'I', 's', 't', 'i', 'y', 'o', 'r', 'u', 'm'};
	char cumle3[] = { 'E','v', 'e', 'G', 'i', 't', 'm', 'e', 'k', 'I', 's', 't', 'i', 'y', 'o', 'r', 'u', 'm' };
	char cumle4[] = { 'S','e', 'n', 'l', 'e', 'O', 'y', 'u', 'n', 'O', 'y', 'n', 'a', 'm', 'a', 'y', 'i', 'S', 'e', 'v', 'i', 'y', 'o', 'r', 'u', 'm' };
	char cumle5[] = { 'A','n','n','e','m','i','C','o','k','S','e','v','i','y','o','r','u','m' };             /// eklenmedi
	char cumle6[] = { 'E','v','e','S','e','n','l','e','G','i','t','m','e','k','I','s','t','i','y','o','r','u','m' };
	char cumle7[] = { 'S','e','n','l','e','E','v','e','G','i','t','m','e','k','I','s','t','i','y','o','r','u','m' };
	char cumle8[] = { 'O','y','u','n','O','y','n','a','m','a','y','i','I','s','t','i','y','o','r','u','m' };
	char cumle9[] = { 'S','e','n','l','e','O','y','u','n','O','y','n','a','m','a','y','i','I','s','t','i','y','o','r','u','m' };
	char cumle10[] = { 'A','n','n','e','m','i','I','s','t','i','y','o','r','u','m' };
	char cumle11[] = { 'A','n','n','e','m','i','S','e','v','i','y','o','r','u','m' };
	char cumle12[] = { 'S','e','n','l','e','O','y','n','a','m','a','y','i','S','e','v','i','y','o','r','u','m' };
	char cumle13[] = { 'O', 'y', 'u', 'n', 'O', 'y', 'n', 'a', 'm', 'a', 'y', 'i', 'S', 'e', 'v', 'i', 'y', 'o', 'r', 'u', 'm' };


	temp = new node();
	temp = front;
	int i = 0;
	int c = 0;
	while (temp != NULL)
	{
		
		if (cumle1[i]==temp->item)
		{
			//return 1;
			//std::cout << "Dogru";
			c++;
			
		}
		else if (cumle2[i] == temp->item)
		{
			c++;
		}
		else if(cumle3[i] == temp->item)
		{
			c++;
		}
		else if(cumle4[i] == temp->item)
		{
			c++;
		}
		else if (cumle5[i] == temp->item)
		{
			c++;
		}
		else if (cumle6[i] == temp->item)
		{
			c++;
		}
		else if (cumle7[i] == temp->item)
		{
			c++;
		}
		else if (cumle8[i] == temp->item)
		{
			c++;
		}
		else if (cumle9[i] == temp->item)
		{
			c++;
		}
		else if (cumle10[i] == temp->item)
		{
			c++;
		}
		else if (cumle11[i] == temp->item)
		{
			c++;
		}
		else if (cumle12[i] == temp->item)
		{
			c++;
		}
		else if (cumle13[i] == temp->item)
		{
			c++;
		}
		i++;
		
		temp = temp->next;
	}
	if (i == c & i!=0 & c!=0)
	{
		std::cout << "Dogru"<<std::endl;
		skor++;

		
	}
	else if (i!=0)
	{ 
		std::cout << "Yanlis";
		skor--;
		
	}
	
	              
}

int dqueue::ret()
{
	if (skor<0)
	{
		skor == 0;
	}
	return skor;
}
/*
void dqueue::ret(char dizi[])
{
temp = new node();
temp = front;
int i = 0;
while (temp != NULL)
{
dizi[i]= temp->item;
//return temp->item;
temp = temp->next;
i++;
}
}

*/