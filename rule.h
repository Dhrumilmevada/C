
/*word to match for question mark sentence at start of sentence.
*	first letter should be capital
*	at end of sentence put question mark [?] 
*/
char *ques_word[7] = {"Can","What","How","Where","Who","Do","Did","When","Is","Are","Which","Was","Were","Which","Was",
			"Were","Will","Shold","May"};

/*word to match for exclametion  sentence at start of sentence.
*	first letter should be capital
*	it may be possible to have one word sentence
*	at end of sentence put question mark [!] 
*/


char *excla_word[15] = {"Yes","Wow","Help","Stop","Whoa","Yiles","Ouch","Absolutly","Nice"};

/*	set of academical degree to match and put comma before these degees
*   	if sentence after these degree is  complete then put period there.
*/

char *degree_set[7] = {"B.E.""B.Tech","M.Tech","M.E.","M.S.","B.com","MBA","B.A.","M.A.","PhD","B.Arch",};

/* this date data are used to match date in paragraph.
*  February 17 2018 will be converted to February 17, 2018
*/
char *date[15] = {"January","February","March","April","May","June","July","August","September","Octomber","November","December"};


/* This set of adjective is used in two way to put comaa in paragraph 
*	1) if they come in back to back in line seperate them with comma
*	2) if adjective is at start of sentence and first charactor is in capital then put comma after adjective.
*
*/
char *adj[20] = {"beutiful","clean","fency","glamorous","handsome","alive","better","carefull","clever","obedient","silly","thankfull","rich",
		"shy","zealous","proud","gentle","helpless","itchy","nervous","worried","broad","flat","high","low","narrow","skinny","big",
		"flat","short","small","tiny","tall","loud","melodic","noisy","quit","whispering","slow","fast","late","long","bitter","fresh",
		"juicy","hot","icy","salty","Strong","sweat","yummy","cold","cool","wet"};

/* these set of word used to put comma
* 	1) if matching word are from below mention except please and when then put comma before matching word
*	2)if matching word is please at end of sentence then put comma before it.
*	3) if matching word is when and there is two depended sentence then put comma after first sentence
*		i.e. When rain falls , road get wet. 
*/
char *comma_word[10] = {"but","nor","or","so","yet","when","please"};
