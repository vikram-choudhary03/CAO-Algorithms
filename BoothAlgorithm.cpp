//Booth multiplication algorithm
#include<iostream>
#include<math.h>
using namespace std;

 int twocomp[100];
int predictCarry(int in, int A[], int B[])    // func for predict carry
{
    int carry;
    if(in==-1)
        return 0;
    else
        carry=(A[in]&B[in])|((A[in]^B[in])&predictCarry(in-1, A,B));

        return carry;
}


int twocomplement(int arr[],int arr1[],int n)     // for two's complement
{    twocomp[n];
    int c,k;
     for( k=0; k<n; k++)
     {
        if(arr[k]==0){
        arr[k]=1;
        c=predictCarry(k-1, arr,arr1);
        twocomp[k]=(arr[k]^arr1[k])^c;}
        else{
        arr[k]=0;
        c=predictCarry(k-1, arr,arr1);
        twocomp[k]=(arr[k]^arr1[k])^c;}
     }
     for( k=k-1; k>=0;k--)
     {  arr[k]=twocomp[k];
        //cout<<twocomp[k];
     }

    return 0;
}
int print(int accprint[],int Qprint[], int Q_1print[], int Mprint[], int n)    //for displaying the array values
{
     for(int l=n-1; l>=0; l--)
     {
          cout<<accprint[l];
     }
     cout<<"\t";
     for(int l=n-1; l>=0; l--)
     {
          cout<<Qprint[l];
     }
     cout<<"\t";
     //for(int l=n-1; l>=0; l--)
     //{
          cout<<Q_1print[0];
     //}
     cout<<"\t";
     for(int l=n-1; l>=0; l--)
     {
          cout<<Mprint[l];
     }
     cout<<endl;
     return 0;
}
int shift(int accshift[],int Qshift[], int Q_1shift[],  int n)     //for shifting the array values
{   Q_1shift[0]=Qshift[0];
    for( int l=0; l<n;l++)
    {    if(l!=0)
        Qshift[l-1]=Qshift[l];

    }
    Qshift[n-1]=accshift[0];
    for(int l=0; l<n;l++)
    {   if(l!=0)
        accshift[l-1]=accshift[l];

    }


    return 0;
}
int main()
{

  int q,m,c,i;
  cout<<"Enter the multiplicand(M): ";
  cin>>m;
  cout<<"Enter the multiplier(Q): ";
  cin>>q;
  cout<<"first number :";
   int n;
   if(abs(m)>=abs(q))
   {
    i=2;
    while(1)
   {
      if ( abs(m)>=(-pow(2,i-1)) && abs(m)<=(pow(2,i-1)-1))
      { n=i;
      break;
      }

      i++;
   }
   }
   else
    {  i=2;
      while(1)
     {
       if ( abs(q)>=(-pow(2,i-1)) && abs(q)<=(pow(2,i-1)-1))
       {n=i;
       break;
       }
       i++;
     }
    }

   int M[n],Q[n],one[n],Acc[n],Acc_store[n],Mdup[n];

   int t,t1,j;
   t1=n;
   t=m;
   for(i=0; i<n;i++)
     {   if(i==0)
         one[i]=1;
         else
         one[i]=0;
    }
    i=0;
   while(n>0)
    {
      M[i]=abs(m)%2;
      m=abs(m)/2;
      i++;
      n--;
    }
    n=t1;
    if(t<0)   //if the no is negative
    {
      twocomplement(M,one,n);
      for(int i=n-1; i>=0;i--)
     {
      cout<<M[i];
     }
     for(int i=n-1; i>=0;i--)
     {
       Mdup[i]=M[i];
     }

    }
    else
    {
    for(i=i-1;i>=0;i--)      //if no is positive
    {
        cout<<M[i];
    }
    for(int i=n-1; i>=0;i--)
     {
       Mdup[i]=M[i];
     }

    }
    cout<<endl;

    cout<<"second number : ";

   i=0;
   t=q;
    while(n>0)
    {

      Q[i]=abs(q)%2;
      q=abs(q)/2;
      i++;
      n--;
    }
      n=t1;
    if(t<0)   //if the no is negative
    {

      twocomplement(Q,one,n);
      for(int i=n-1; i>=0;i--)
     {
      cout<<Q[i];
     }
    }

    else
    {
    for(i=i-1;i>=0;i--)      //if no is positive
    {
        cout<<Q[i];
    }
    }
    cout<<endl;

   int Q_1[1]={0};
   cout<<"A\tQ\tQ-1\tM"<<endl;

  for( int i=0; i<n; i++)
    {   Acc[i]=0;}

   print(Acc,Q,Q_1,M,n);

  int no_iteration=n;
  while(no_iteration>0)
 {
  if(Q[0]==1 && Q_1[0]==0)
  { cout<<endl;
    twocomplement(M,one,n);
    for(int i=0; i<n; i++ )
    {
        c=predictCarry(i-1,M,Acc);
        Acc_store[i]=(M[i]^Acc[i])^c;
    }
     for(int i=n-1; i>=0; i-- )
    {   Acc[i]=Acc_store[i];

    }
    print(Acc,Q,Q_1,Mdup,n);
    shift(Acc,Q,Q_1,n);
    print(Acc,Q,Q_1,Mdup,n);
    no_iteration--;
  }
   else if(Q[0]==0 && Q_1[0]==1)
  {  cout<<endl;
      for(int i=n-1; i>=0;i--)
     {
       M[i]=Mdup[i];
     }
    for(int i=0; i<n; i++ )
    {
        c=predictCarry(i-1,M,Acc);
        Acc_store[i]=(M[i]^Acc[i])^c;
    }
     for(int i=n-1; i>=0; i-- )
    {   Acc[i]=Acc_store[i];

    }
    print(Acc,Q,Q_1,Mdup,n);
    shift(Acc,Q,Q_1,n);
    print(Acc,Q,Q_1,Mdup,n);

    no_iteration--;
  }
  else
  {  cout<<endl;
    shift(Acc,Q,Q_1,n);
    print(Acc,Q,Q_1,Mdup,n);
    no_iteration--;
  }

 }

  return 0;

}

