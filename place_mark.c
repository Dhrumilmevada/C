
/* function	put_question_mark
*  @date 	18/07/2018
*  @brief	to find out the end of sentence and put question mark
*  @param	char three_word_array : it contain set of three word from paragraph 		
*		flag_array[] : it contain detail of whether first letter of each word in 
*				three_word_array is capital or not 
*				0 :lowercase character
*				1: uppercase character
*		int pfinal_array : pointing the index from where we can add remaning sentence 
* @return 	null
*/
int put_question_mark(char three_word_array[][15],int flag_array[],char final_array[][15],int pfinal_array)
{
	while(flag_array[0]!=0 && flag_array[1]!=0 && flag_array[1]!=1)   //loop to check final array content
	{
		swap_three_word_array(int end_p_word_array,char three_word_array[][15],int flag_array[]);  //move to next word
		
		if(flag_array[0]==0 && flag_array[1]==0 && flag_array[1]==1) //satisfied when end of array fonud 
		{
			for(;start_p_word_array < (end_p_word_array-1);start_p_word_array++)
			{
				strcpy(final_array[pfinal_array++],word[start_p_word_array]); //copy all the word to final array
			}
			final_array[pfinal_array] = "?";
		}	
		start_p_word_array = end_p_word_array -1;
	}
return 0;
}


/* function	put_exclametion_mark
*  @date 	18/07/2018
*  @brief	to find out the exclametion word and put question mark
*  @param	char three_word_array : it contain set of three word from paragraph 		
*		flag_array[] : it contain detail of whether first letter of each word in 
*				three_word_array is capital or not 
*				0 :lowercase character
*				1: uppercase character
*		int pfinal_array : pointing the index from where we can add remaning sentence 
* @return 	null
*/
int put_exclametion_mark(char three_word_array[][15],int flag_array[],char final_array[][15],int pfinal_array)
{
	for(;start_p_word_array < (end_p_word_array-1);start_p_word_array++) //loop to add exclametion mark and to copy word final array 
	{
		if(start_p_word_array == end_p_word_array - 1)
		{
			final_array[pfinal_array++] = "!";  //put exclametion mark at proper location
			break; 			
		}
		strcpy(final_array[pfinal_array++],word[start_p_word_array]);  //copy the content to final array
	}
	swap_three_word_array(int end_p_word_array,char three_word_array[][15],int flag_array[]); //swap three word array
	start_p_word_array = end_p_word_array - 1 //set the start pointer of word array
}
