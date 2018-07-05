#include<stdio.h>
#include<stdlib.h>
int p[50],n;
void lru();
void fifo();
void main()
	{
                int choice;
                
		printf("\nENTER NUMBER OF PAGES : ");
		scanf("%d",&n);
		printf("Enter the pages:");
		for(int i=0;i<n;i++)
			{
				 scanf("%d",&p[i]);
			}
		printf("enter 1 for lru or 2 for fifo\n");
                scanf("%d",&choice);
                switch(choice)
  {
case 1: lru(); break;
case 2: fifo(); break;

	}	
}
void lru()
{
 int nof,i,count=0;
          
          
          printf("\n\t Enter the No of frames:-");
          scanf("%d",&nof);
          int frame[nof],fcount[nof];
          for(i=0;i<nof;i++)
          {
          frame[i]=-1; //Store the frames
          fcount[i]=0; //Track when the page is last used
          }
          
          for(i=0;i<n;i++)
          {
            int flag=0;
            for(int j=0;j<nof;j++)
            {
               if(p[i]==frame[j])
               {  //Checking whether page already exist in frames or not
               flag=1;
               fcount[j]=i+1;
               }
            }    
               
            printf("\n\t************************\n");
            printf("%d\t",p[i]);    
            if(flag==0)
            {
             int min=0;
             for(int k=0;k<nof-1;k++)
                {
                 
                  if(fcount[min]>fcount[k+1]) //Calculating the page which is least recently used
                    min=k+1;
                }
               frame[min]=p[i]; //Replacing it
               fcount[min]=i+1;    //Increasing the time 
               count++;           //counting Page Fault

            for(int j=0;j<nof;j++)
               printf("%d\t",frame[j]);
               
             } // end of if            
          }  // end of for
          printf("\n\t************************\n");
          printf("\n\tPage Fault is:%d",count);        
}        

void fifo()
{
int i,j,frame[10],no,k,avail,count=0;
printf("\n ENTER THE NUMBER OF FRAMES : ");
		scanf("%d",&no);
		for(i=0;i<no;i++)
		frame[i]= -1;
		j=0;
		printf("\nREFERENCE STRING\t\t\t PAGE FRAMES\n");
		for(i=0;i<n;i++)
			{
				printf("%d\t\t\t\t\t",p[i]);
				avail=0;
				for(k=0;k<no;k++)
				if(frame[k]==p[i])
				avail=1;
				if (avail==0)
				    {
					frame[j]=p[i];
					j=(j+1)%no;
					count++;
					for(k=0;k<no;k++)
						{
							if(frame[k]!=-1)
							printf("%d\t",frame[k]);
							else
							printf("  \t");
						}
				    }
				printf("\n");
			}
		printf("PAGE FAULT IS %d",count);	
		
}

