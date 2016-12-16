#include<stdio.h>
#include<time.h>
#include<string.h>
#include <ctype.h>
#include <sys/stat.h>
#include<stdlib.h>
 void main(int argc, char* argv[])
 {
   int tstat;
   struct stat file_info;
   int i,j,x;
   long long z;
   time_t timer;
   time_t timer2;
   struct tm *t;
   char week[7][7]={"일", "월", "화", "수", "목", "금", "토"};
   argv[argc]="sad";
   timer=time(NULL);
   timer2=time(NULL);
   if(argv[1]==NULL){
	timer = time(NULL);
  	}

   else if(strcmp(argv[1],"-d")==0){
	for(i=2;i<argc;i++){
		if(strcmp(argv[i],"yesterday")==0){
	    	timer = timer-(24*60*60);
		}
		else if(strcmp(argv[i],"years")==0){
			x = atoi(argv[i-1]);
				if(x==0)
				   x=1;
			
				if(strcmp(argv[i+1],"ago")==0){
				   t = localtime(&timer);
				   if(t->tm_year<2)
				   timer= timer-24*60*60;
				   for(j=0;j<x;j++)
			     	   {
					t = localtime(&timer);
					if((t->tm_year+1900)% 400 == 0||((t->tm_year+1900)% 4 == 0 && (t->tm_year+1900) % 100))
						{  
							timer=timer-(24*60*60*366);
						}
    					else
    						{
        						timer=timer-(24*60*60*365);
    						}
				   }
				}
				else{
				   t = localtime(&timer);
				   if(t->tm_year>2)
				   timer= timer-24*60*60;
				   for(j=0;j<x;j++)
			     	   {
					t = localtime(&timer);
					if((t->tm_year+1900)% 400 == 0||((t->tm_year+1900)% 4 == 0 && (t->tm_year+1900) % 100))
						{  
							timer=timer+(24*60*60*366);
						}
    					else
    						{
        						timer=timer+(24*60*60*365);
    						}
				   }
				} 
		}
		
		else if(strcmp(argv[i],"month")==0){
			x = atoi(argv[i-1]);
				if(x==0)
				   x=1;
			
				if(strcmp(argv[i+1],"ago")==0){
				   t = localtime(&timer);
				  
				   for(j=0;j<x;j++)
			     	   {
					t = localtime(&timer);
					if((t->tm_year+1900)% 400 == 0||((t->tm_year+1900)% 4 == 0 && (t->tm_year+1900) % 100))
						{  
							if(t->tm_mon+1== 5||t->tm_mon+1== 7||t->tm_mon+1== 10||t->tm_mon+1== 12)
							timer=timer-(24*60*60*30);
							else if(t->tm_mon+1 == 3)
							timer=timer-(24*60*60*29);
							else
							timer=timer-(24*60*60*31);				
						}
    					else
    						{
        						if(t->tm_mon+1== 5||t->tm_mon+1== 7||t->tm_mon+1== 10||t->tm_mon+1== 12)  
							timer=timer-(24*60*60*30);
							else if(t->tm_mon+1 == 3)
							timer=timer-(24*60*60*28);
							else
							timer=timer-(24*60*60*31);
    						}
				   }
				}
				else{
				   t = localtime(&timer);
			
				   for(j=0;j<x;j++)
			     	   {
					t = localtime(&timer);
					if((t->tm_year+1900)% 400 == 0||((t->tm_year+1900)% 4 == 0 && (t->tm_year+1900) % 100))
						{  
							if(t->tm_mon+1== 4||t->tm_mon+1== 6||t->tm_mon+1== 9||t->tm_mon+1== 11)
							timer=timer+(24*60*60*30);
							else if(t->tm_mon+1== 2)
							timer=timer+(24*60*60*29);
							else
							timer=timer+(24*60*60*31);				
						}
    					else
    						{
        						if(t->tm_mon+1== 4||t->tm_mon+1== 6||t->tm_mon+1== 9||t->tm_mon+1== 11)
							timer=timer+(24*60*60*30);
							else if(t->tm_mon+1== 2)
							timer=timer+(24*60*60*28);
							else
							timer=timer+(24*60*60*31);
    						}
				   }
				} 
		}
		
		else if(strcmp(argv[i],"day")==0){
			x = atoi(argv[i-1]);
			
			if(x!=0)
			{
			z = 24*60*60*x;	
			}
			else if(x==0)
			{
			z= 24*60*60*1;			   
			}
			if(strcmp(argv[i+1],"ago")==0){
			timer = timer-z;
			}
			else{ 
			timer = timer+z;
			}  
		}
		else if(strcmp(argv[i],"hour")==0){
			x = atoi(argv[i-1]);
			
			if(x!=0)
			{
			z = x*60*60;	
			}
			else if(x==0)
			{
			z = 60*60;			   
			} 
			if(strcmp(argv[i+1],"ago")==0){
			timer = timer-z;
			}
			else{ 
			timer = timer+z;
			}  
		}
		else if(strcmp(argv[i],"min")==0){
			x = atoi(argv[i-1]);
			
			if(x!=0)
			{
			z = x*60;	
			}
			else if(x==0)
			{
			z = 60;			   
			}
			if(strcmp(argv[i+1],"ago")==0){
			timer = timer-z;
			}
			else{ 
			timer = timer+z;
			}  
		}
		else if(strcmp(argv[i],"sec")==0){
			x = atoi(argv[i-1]);
			
			if(x!=0)
			{
			z = x;	
			}
			else if(x==0)
			{
			z = 1;			   
			}
			if(strcmp(argv[i+1],"ago")==0){
			timer = timer-z;
			}
			else{ 
			timer = timer+z;
			}  
		}
	}
       
    }
     else if(strcmp(argv[1],"-r")==0){
 	if ((tstat = stat(argv[2], &file_info)) == -1)
    	{
        perror("Error : ");
        exit(0);
    	}
	timer = file_info.st_mtime;
	
    
    }
     t = localtime(&timer);
     printf("%d. %d. %d. (%s) %d:%d:%d KST\n ", t->tm_year+1900, t->tm_mon+1,
     t->tm_mday, week[t->tm_wday], t->tm_hour, t->tm_min, t->tm_sec);
}
