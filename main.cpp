//Lenguajes y Automatas
//Regular Processing
/////////////////////////////////////////////////////

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>

using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

string cadena; //save the string that is written by the user
int n;  //save the string length for create the char array
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int fstate=2; //final state
int alphabetSize=10;
char E[10]={'x','X','0','1','2','3','4','5','6','7'}; //ALPHABET

	 						 //Transicion table     indicates resulting state afther the simbol processing, -1 indicates that transicion does not exist
int transicion[4][10]={ 					//     x   X   0   1   2   3   4   5   6   7
-1,-1, 1,-1,-1,-1,-1,-1,-1,-1,				//q0  -1  -1   1  -1  -1  -1  -1  -1  -1  -1
 2, 2,-1,-1,-1,-1,-1,-1,-1,-1,				//q1   2   2  -1  -1  -1  -1  -1  -1  -1  -1  
-1,-1, 3, 3, 3, 3, 3, 3, 3, 3,				//q2  -1  -1  -1   3   3   3   3   3   3   3      
-1,-1, 2, 2, 2, 2, 2, 2, 2, 2,				//q3  -1  -1  -1   2   2   2   2   2   2   2        
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int find(char c) //find the character c in the alphabet and return your index, return -1 if the character does not exist
{
	for(int i=0;i<alphabetSize;i++)
	{
		if (c==E[i])
		{
			return i;
		}
	}
	
	return -1;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int delta(int q, char sigma)
{
	int sigmaIndex=find(sigma);
	if (sigmaIndex==-1)
	{
		return -1;
	}
	for(int i=0;i<alphabetSize;i++)
	{
		if (transicion[q][find(sigma)]>-1)
		{
			return transicion[q][sigmaIndex];
		}
	}
	return -1;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int process(int q, char *w)
{
	int state=q;
	for(int i=0; i<n; i++)
	{
		printf("\n\t(%i,%c)",state,w[i]);
		state=delta(state,w[i]);
		if(state==fstate)
		{
			printf("\tAceptada ");
		}
		else
		{
			printf("\tRechazada ");
		}
		//printf(" -> %i",state);
		
		if (state==-1)
		{
			return -1;
		}
	}
		
	return state;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool test(char *w)
{
	if(process(0,w)==fstate)
	{
		return 1;
	} 
	
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	cout<<"Cadena: ";cin>>cadena;
	n=cadena.length();
	char a[n]; //EVENTS
	strcpy(a,cadena.c_str());
	
	cout<<"(Estado,Evento)  Status";
	cout<<endl<<"------------------------------";
	
	if(test(a)==1)
	{
		cout<<endl<<"------------------------------";
		cout<<endl<<"La cadena es aceptada";
	}
	else
	{
		cout<<endl<<"------------------------------";
		cout<<endl<<"La cadena es rechazada";
	}
	
	cout<<endl;
	system("pause");
	return 0;
}
