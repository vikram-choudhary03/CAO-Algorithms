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
int print(int accprint[],int Qprint[], int Mprint[], int n)    //for displaying the array values
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

     for(int l=n-1; l>=0; l--)
     {
          cout<<Mprint[l];
     }
     cout<<endl;
     return 0;
}
int shift(int accshift[],int Qshift[], int n)     //for shifting the array values
{
    for(int l=n-2; l>=0;l--)
    {
        accshift[l+1]=accshift[l];

    }
    accshift[0]=Qshift[n-1];
    for( int l=n-2; l>=0;l--)
    {
        Qshift[l+1]=Qshift[l];

    }

    return 0;
}

int accrestore(int res1[],int res2[],int n)
{
    for(int l=n-1; l>=0;l--)
    {
        res2[l]=res1[l];
    }
    return 0;
}
int main()
{

  int q,m,c,i;
  cout<<"Enter the Dividend(Q): ";
  cin>>q;
  cout<<"Enter the Divisior(M): ";
  cin>>m;
  cout<<"Divisior in binary:";
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
    m=t;
    n=t1;

    for(i=i-1;i>=0;i--)      //if no is positive
    {
        cout<<M[i];
    }
    for(int i=n-1; i>=0;i--)
     {
       Mdup[i]=M[i];
     }

    cout<<endl;

    cout<<"Dividend in binary: ";

   i=0;
   t=q;
    while(n>0)
    {

      Q[i]=abs(q)%2;
      q=abs(q)/2;
      i++;
      n--;
    }
     q=t;
      n=t1;

    for(i=i-1;i>=0;i--)      //if no is positive
    {
        cout<<Q[i];
    }

    cout<<endl;


   cout<<"A\tQ\tM"<<endl;

  for( int i=0; i<n; i++)
    {   Acc[i]=0;}

   print(Acc,Q,M,n);
   cout<<endl;
  int no_iteration=n;
  int restore_Acc[n];
  accrestore(Acc,restore_Acc,n);
  while(no_iteration>0)
 {
    shift(Acc,Q,n);
    accrestore(Acc,restore_Acc,n);
    print(Acc,Q,Mdup,n);
    for(int i=n-1; i>=0;i--)
     {
       M[i]=Mdup[i];
     }
    twocomplement(M,one,n);
    for(int i=0; i<n; i++ )
    {
        c=predictCarry(i-1,M,Acc);
        Acc_store[i]=(M[i]^Acc[i])^c;
    }
    for(int i=n-1; i>=0; i-- )
    {   Acc[i]=Acc_store[i];

    }
    //print(Acc,Q,Mdup,n);
    if(Acc[n-1]==1)
    {
        Q[0]=0;
        print(Acc,Q,Mdup,n);
        accrestore(restore_Acc, Acc,n);
        print(Acc,Q,Mdup,n);
        cout<<endl;
        no_iteration--;
    }
    else
    {
        Q[0]=1;
        print(Acc,Q,Mdup,n);
        cout<<endl;
        no_iteration--;
    }

 }
  int signR, signQ;
  signR=q;
  if(signR<0)
  {   twocomplement(Acc, one, n);
      cout<<"Remainder: ";
      for(int i=n-1; i>=0; i--)
          cout<<Acc[i];
  }
  else
  {   cout<<"Remainder: ";
      for(int i=n-1; i>=0; i--)
          cout<<Acc[i];
  }
  cout<<endl;

  signQ = q*m;
  if(signQ<0)
  {   twocomplement(Q, one, n);
      cout<<"Quotient: ";
      for(int i=n-1; i>=0; i--)
          cout<<Q[i];
  }
  else
  {   cout<<"Quotient: ";
      for(int i=n-1; i>=0; i--)
          cout<<Q[i];
  }


  return 0;

}
