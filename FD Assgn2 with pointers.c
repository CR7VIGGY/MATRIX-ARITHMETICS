//VIGHNESH TIWARI , 4252 , AIT , PUNE
#include<stdio.h>
#include<conio.h>
int main()
{  int i,j,r1,c1,r2,c2,b;
	printf("ENTER THE SIZE OF ROW AND COLUMN OF MATRIX 1");
	scanf("%d%d",&r1,&c1);
	printf("\nENTER THE SIZE OF ROW AND COLUMN OF MATRIX 2");
	scanf("%d%d",&r2,&c2);
	int arr1[r1][10];int arr2[r2][10];
  
    
	printf("\nenter first matrix\n");
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			{
				scanf(  "%d",&*(*(arr1+i)+j));
			}
		}
		printf("\n");
		
		
		printf("\nenter second matrix\n");
		for(i=0;i<r2;i++)
		{
			for(j=0;j<c2;j++)
			{
				scanf("%d",&*(*(arr2+i)+j)  );
			}
		}	
		printf("\n");

	
	do 
	{ printf("\nPRESS 1 : for Addition \nPRESS 2 : for Subtraction \nPRESS 3 : for multiplication \nPRESS 4 : for Transpose of First matrix \nPRESS 5 :for finding Saddle Point \nPRESS 6 : to exit\nEnter your choice"                       );
		scanf("%d",&b);
		switch(b)
		{
			case 1 : add(r1,c1,arr1,r2,c2,arr2);break;
			case 2 : sub(r1,c1,arr1,r2,c2,arr2);break;
			case 3 : mul(r1,c1,arr1,r2,c2,arr2);break;
			case 4 : transpose(r1,c1,arr1,r2,c2,arr2);break;
		    case 5 : saddle(r1,c1,arr1);break;	
			
		}
	}while(b!=6);
}
int add(int p,int q,int (*x)[10],int m,int n,int (*y)[10])
{   
	if(p==m && q==n)
	{
			int i ,j;
	
		printf("\nAdditon is\n");
		for(i=0;i<p;i++)
		{
			for(j=0;j<q;j++)
			{
				printf("%d  ", *(*(x+i)+j) + *(*(y+i)+j)  );
			}
			printf("\n");
		}
 	}	 
	else 
	printf("ADDITION CANNOT BE PERFORMED");
	
}


int sub(int p,int q,int (*x)[10],int m,int n,int (*y)[10])
{   
	if(p==m && q==n)
	{
			int i ,j;
	
		printf("\nsubtraction\n");
		for(i=0;i<p;i++)
		{
			for(j=0;j<q;j++)
			{
				printf("%d  ",*(*(x+i)+j) -  *(*(y+i)+j) );
			}
			printf("\n");
		}
 	}	 
	else 
	printf("\nINVALID ENTRY FOR SUBTRACTION");
	
}


void mul(int r1,int c1,int  (*x)[10],int r2,int c2,int  (*y)[10])
{
    int i,j,n,k;
   
   if(c1==r2)
	{
			int z[r1][c2];
		
	
	    printf("\nMULTIPLICATION IS :\n");	
		for(i = 0 ; i < r1 ; i++)
		{
			for(j = 0 ; j < r1 ; j++)
			{
				z[i][j] = 0;
				for(k = 0 ; k < r1 ; k ++)
				{
					z[i][j] = z[i][j] + *(*(x+i)+k) * *(*(y+k)+j);
				}
			}
		}
		
		for(i = 0 ; i < r1 ; i++)
		{
			for(j = 0 ; j < c1 ; j++)
			{
					printf("%d  ",z[i][j]);
					
			}printf("\n");
		}
	}
	else
	printf("INVALID ENTRY FOR MULTIPLICATION");
	
}

void transpose(int r1,int c1,int (*x)[10],int r2,int c2,int (*y)[10])
{
	printf("\nTranspose of matrix 1 is\n");
	int i,j;
	
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			{
				printf("%d  ",*(*(x+j)+i)  );
			}
			printf("\n");
		}

	printf("\nTranspose of matrix 2 is\n");
	
		for(i=0;i<r2;i++)
		{
			for(j=0;j<c2;j++)
			{
				printf("%d  ", *(*(y+j)+i)   );   
			}
			printf("\n");
		}

}


void saddle(int r,int c,int arr[][10])
{
	int a1[r],a2[c];
	int i,j,k,count=0;
	for(k=0;k<r;k++)
	{  
		for(i=0;i<c;i++)
		{  
			for(j=0;j<c;j++)
			{
				if(*(*(arr+k)+i)  <  *(*(arr+k)+j))
				{
					count++;
				}
			}
			if(count==c-1)
			{
				a1[k]=arr[k][i];
			}		
		count=0;
		}
		
	}
	
	for(k=0;k<c;k++)
	{  
		for(i=0;i<r;i++)
		{  
			for(j=0;j<r;j++)
			{
				if( *(*(arr+i)+k)  > *(*(arr+j)+k)  )
				{
					count++;
				}
			}
			if(count==r-1)
			{
		
			a2[k]=arr[i][k];
			}		
		count=0;
		}
	}
	int flag=0;
	for(i=0;i<r;i++) 
	{
			for(j=0;j<c;j++)
		{
			if(a1[i]==a2[j])
			printf("\n %d",a1[i]);
			 flag++;
		}
		
	}
	
	if(flag==0)
	printf("\n No Saddle Point");
	
}




