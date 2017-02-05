#include<bits/stdc++.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

using namespace std;

map<string,double> mp_normal[10];
map<string,double> mp_attack[10];
double no_attack=0,attack=0;
double prob_attack=1,
	prob_noattack=1;
double p_att=1,
	p_nor=1;
char line[1024];
double total=0,
	correct=0;

char* getField(char*,int);

void test(FILE* file)
{
	int i;

	while(fgets(line,1024,file))
	{
		char* tmp = strdup(line);
		char* token = getField(tmp,8);

		for(i=1;i<=7;i++)
		{
			if(mp_normal[i][getField(strdup(line),i)]!=0)
			p_nor*=mp_normal[i][getField(strdup(line),i)];

			if(mp_attack[i][getField(strdup(line),i)]!=0)
			p_att*=mp_attack[i][getField(strdup(line),i)];
		}

		p_att*=prob_attack;
		p_nor*=prob_noattack;


		if(p_att>= p_nor)
		{
			if(strcmp(token,"normal."))
			correct++;
		}
		total++;
	}

}


char* getField(char* line, int num)
{
        char* tok = NULL;

	for (tok = strtok(line, ",");
            tok && *tok;
            tok = strtok(NULL, ",\n"))
	{
        	if (!--num){
            		return tok;
		}
        }

        return NULL;
}

int main(int argc, char** argv)
{
	FILE* in = fopen(argv[1],"r");          //Enter training dataset
	FILE* file = fopen(argv[2],"r");	//Enter testing dataset

	int i;
	map<string,double> mp;

	for(i=0;i<10;i++)
	{
		mp_normal[i] = mp;
		mp_attack[i] = mp;
	}

	while(fgets(line,1024,in))
	{
		char* tmp = strdup(line);
		char* token = getField(tmp,8);

		if(!strcmp(token,"normal."))
		{
			for(i=1;i<=7;i++)
				mp_normal[i][getField(strdup(line),i)]++;

			no_attack++;
		}

		else
		{
			for(i=1;i<=7;i++)
				mp_attack[i][getField(strdup(line),i)]++;

			attack++;
		}
		
	}

	for(i=0;i<10;i++)
	{
	

		for(map<string,double>::iterator it=mp_normal[i].begin();it!=mp_normal[i].end();++it)
		{
			it->second = (it->second)/(double)no_attack;
		}

		for(map<string,double>::iterator it=mp_attack[i].begin();it!=mp_attack[i].end();++it)
		{
			it->second = (it->second)/(double)attack;
		}
	}

	prob_attack = attack/(attack + no_attack);
	prob_noattack = no_attack/(attack + no_attack);

	test(file);						//testing the predictor

	printf("Accuracy rate is %lf\n",(correct/total));
	fclose(file);
	fclose(in);
	

}
	
