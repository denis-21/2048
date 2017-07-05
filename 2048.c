//Denis Joseph
//21 Dec 2014
//2 jan 2015
#include<stdio.h>
#include<conio.h>
void add(int grid[][4],int arr[][4]);
void display(int grid[][4]);
void left(int grid[][4]);
void right(int grid[][4]);
void up(int grid[][4]);
void down(int grid[][4]);
int arrcomp(int grid[][4]);
int init[4][4]; 
int arr[4][4];

int main()
{
  int grid[4][4]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int arr[4][4]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int a;
  add(grid,arr);
  add(grid,arr);
  display(grid);
  
  while(a!=0)
  {
    switch (a)
    {
      case 4:
        system("cls");
        left(grid);
        display(grid);
        break;
                
      case 6:
        system("cls");
        right(grid);
        display(grid);
        break;
        
      case 8:
        system("cls");
        up(grid);
        display(grid);
        break;
        
      case 5:
        system("cls");
        down(grid);
        display(grid);
        break;  
     
       default:
        break;
    }
    printf("");
    a=getch()-48;
  }  
}  
  
//add no. 
void add(int grid[][4],int arr[][4]) 
{
  int i,j,t,a,b,k; 
  srand((unsigned) time(&t));
  k=1;
  for(i=0;i<4;i++)
  {
    for(j=0;j<4;j++)
    {
     if(grid[i][j]==0)
          {
                    arr[i][j]=k;
                    k++;
          }     
    }
  }
  a=(rand()%(k-1))+1;
  b=(rand()%(k-1))+1;
  for(i=0;i<4;i++)
  {
    for(j=0;j<4;j++)
    {
          if(arr[i][j]==a)
                grid[i][j]=(rand()%2+1)*2;
    }
  }
   for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
         arr[i][j]=0;   
        }
    }    
}  


 //to display
 void display(int grid[][4])
{
    int i,j;
    printf("\n");
    printf("\n");
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(grid[i][j]==0)
            printf("   .");
            else
            printf(" %3d",grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
} 

//Left
void left(int grid[][4])
{
    int i,j,a=0,b=0,k,l;
    int c, temp[4][4];
    
    for(i=0;i<4;i++)
    {
      for(j=0;j<4;j++)
      {
        init[i][j]=grid[i][j];
      }
    }    
    
    
    for(i=0;i<4;i++)
    {
      for(j=0;j<4;j++)
      {
        if(grid[i][j]!=0)
        {
          temp[a][b]=grid[i][j];
          b++;
        }
      }
      while(b<4)
      {
        temp[a][b]=0;
        b++;
      }  
      a++;
      b=0;
    }  
          
          
    for(i=0;i<4;i++)
    {
      if(temp[i][0]==0 && temp[i][1]==0 && temp[i][2]==0 && temp[i][3]==0)
      {
      }  
      
      else
      {
          for(j=0;j<3;j++)
          {
            if(temp[i][j]==temp[i][j+1])
            {
              temp[i][j]=temp[i][j]*2;
              for(k=j+1;k<4;k++)
                {
                  temp[i][k]=temp[i][k+1];
                } 
                temp[i][3]=0; 
            }  
          }
      }  
    }
    
    for(i=0;i<4;i++)
    {
      for(j=0;j<4;j++)
      {
        grid[i][j]=temp[i][j];
      }
    }
    
    c = arrcomp(grid);
    if(c==1)
    {
    }
    else if(c==0)
    {
      add(grid,arr);
    }  
}        
          
          
          
//Right
void right(int grid[][4])
{
    int i,j,a=0,b=3,k,l;
    int c, temp[4][4];
    
    for(i=0;i<4;i++)
    {
      for(j=0;j<4;j++)
      {
        init[i][j]=grid[i][j];
      }
    }
    
    for(i=0;i<4;i++)
    {
      for(j=3;j>=0;j--)
      {
        if(grid[i][j]!=0)
        {
          temp[a][b]=grid[i][j];
          b--;
        }
      }
      while(b>=0)
      {
        temp[a][b]=0;
        b--;
      }  
      a++;
      b=3;
    }  
    
    
          
          
    for(i=0;i<4;i++)
    {
      if(temp[i][0]==0 && temp[i][1]==0 && temp[i][2]==0 && temp[i][3]==0)
      {
      }  
      
      else
      {
          for(j=3;j>=0;j--)
          {
            if(temp[i][j]==temp[i][j-1])
            {
              temp[i][j]=temp[i][j]*2;
              for(k=j-1;k>=0;k--)
                {
                  temp[i][k]=temp[i][k-1];
                } 
                temp[i][0]=0; 
            }  
          }
      }  
    }
    for(i=0;i<4;i++)
    {
      for(j=0;j<4;j++)
      {
        grid[i][j]=temp[i][j];
      }
    }
    
    c = arrcomp(grid);
    if(c==1)
    {
    }
    else if(c==0)
    {
      add(grid,arr);
    }    
}   



//Up
void up(int grid[][4])
{
    int i,j,a=0,b=0,k,l;
    int c,temp[4][4];
    
    for(i=0;i<4;i++)
    {
      for(j=0;j<4;j++)
      {
        init[i][j]=grid[i][j];
      }
    }
    
    for(j=0;j<4;j++)
    {
      for(i=0;i<4;i++)
      {
        if(grid[i][j]!=0)
        {
          temp[a][b]=grid[i][j];
          a++;
        }
      }
      while(a<4)
      {
        temp[a][b]=0;
        a++;
      }  
      b++;
      a=0;
    }  
          
          
    for(j=0;j<4;j++)
    {
      if(temp[0][j]==0 && temp[1][j]==0 && temp[2][j]==0 && temp[3][j]==0)
      {
      }  
      
      else
      {
          for(i=0;i<3;i++)
          {
            if(temp[i][j]==temp[i+1][j])
            {
              temp[i][j]=temp[i+1][j]*2;
              for(k=i+1;k<4;k++)
                {
                  temp[k][j]=temp[k+1][j];
                } 
                temp[3][j]=0; 
            }  
          }
      }  
    }
    
    for(i=0;i<4;i++)
    {
      for(j=0;j<4;j++)
      {
        grid[i][j]=temp[i][j];
      }
    }
    
    c = arrcomp(grid);
    if(c==1)
    {
    }
    else if(c==0)
    {
      add(grid,arr);
    }        
}



//Down
void down(int grid[][4])
{
    int i,j,a=3,b=0,k,l;
    int c,temp[4][4];
    
    for(i=0;i<4;i++)
    {
      for(j=0;j<4;j++)
      {
        init[i][j]=grid[i][j];
      }
    }
    
    for(j=0;j<4;j++)
    {
      for(i=3;i>=0;i--)
      {
        if(grid[i][j]!=0)
        {
          temp[a][b]=grid[i][j];
          a--;
        }
      }
      while(a>=0)
      {
        temp[a][b]=0;
        a--;
      }  
      b++;
      a=3;
    }  
          
          
    for(j=0;j<4;j++)
    {
      if(temp[0][j]==0 && temp[1][j]==0 && temp[2][j]==0 && temp[3][j]==0)
      {
      }  
      
      else
      {
          for(i=3;i>=0;i--)
          {
            if(temp[i][j]==temp[i-1][j])
            {
              temp[i][j]=temp[i-1][j]*2;
              for(k=i-1;k>=0;k--)
                {
                  temp[k][j]=temp[k-1][j];
                } 
                temp[0][j]=0; 
            }  
          }
      }  
    }
    
    for(i=0;i<4;i++)
    {
      for(j=0;j<4;j++)
      {
        grid[i][j]=temp[i][j];
      }
    }
    
    c = arrcomp(grid);
    if(c==1)
    {
    }
    else if(c==0)
    {
      add(grid,arr);
    }        
}       


//array comparison
int arrcomp(int grid[][4])
{
  int i,j;
  for(i=0;i<4;i++)
  {
    for(j=0;j<4;j++)
    {
      if(init[i][j]!=grid[i][j])
         return 0;
    }
  }
  return 1;
}      
