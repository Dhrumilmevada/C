#include<String.h>
#include "rule.h" 
/* 
* macros to decide what type symbol a sentence required
*/
#define question_mark 0     //for questiobn mark
#define exclamation_mark 1	//for exclamation mark
#define comma 2			//to put comma
#define degree 3		//when some type of degree word found in sentence
#define date 4			//when date found in sentence
#define adjective 5		//when adjective find in sentence


/*
* function	compare
* @date 	19/07/2018
* @brief	To compare word with dataset
* @param	char three_word_array : it contain set of three word from paragraph 		
*		flag_array[] : it contain detail of whether first letter of each word in 
*				three_word_array is capital or not 
*				0 :lowercase character
*				1: uppercase character
*
* @return	int 
*
*/
int compare (char three_word_array[][15],short flag_array[] )
{
	int size =3;
	int i =0;
	/*to check word id belong to question mark dataset
	* if yes then return 0
	*/	
	for(i=0;i<ques_word_lenth;i++)
	{
		if(strcmp(three_word_array[2],ques_word[i]))
		{
			return question_mark;
		}	
	}
	/*to check word id belong to exclamation mark dataset
	* if yes then return 1
	*/
	for(i=0;i<excla_word_lenth;i++)
	{
		if(strcmp(three_word_array[2],excla_word[i]))
		{
			return exclamation_mark;
		}	
	}
	/*to check word id belong to comma dataset
	* if yes then return 2
	*/
	for(i=0;i<comma_word_lenth;i++)
	{
		if(strcmp(three_word_array[2],comma_word[i]))
		{
			return comma;
		}	
	}
	/*to check word id belong to degree_set dataset
	* if yes then return 3
	*/
	for(i=0;i<degree_set_lenth;i++)
	{
		if(strcmp(three_word_array[2],degree_set[i]))
		{
			return degree;
		}	
	}
	/*to check word id belong to date set dataset
	* if yes then return 4
	*/
	for(i=0;i<date_lenth;i++)
	{
		if(strcmp(three_word_array[2],date[i]))
		{
			return date;
		}	
	}
	/*to check word id belong to adjective dataset
	* if yes then return 5
	*/
	for(i=0;i<adj_lenth;i++)
	{
		if(strcmp(three_word_array[2],adj[i]))
		{
			return adjective;
		}	
	}
}
