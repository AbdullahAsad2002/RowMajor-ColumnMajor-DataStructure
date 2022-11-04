#include <iostream>
using namespace std;
int main()
{   int n;
    cout<<"Enter dimensions :";
    cin>>n;
    int*s = new int[n];
    for (int i = 0; i < n; i++)
    {   // int a[2][3][4]; 24 elements
    //a[0][1][2] address
        cout<<"Enter Sizes : ";
        cin>>s[i];
    }
    int size = 1;
    for (int i = 0; i < n; i++)
    {
        size = size * s[i];
    }
    int*arr =new int[size];
    cout<<"TOTAL SIZE OF ARRAY IS "<<size<<endl;
    int *baseAddress = &arr[0];
    const int size_dt = 4;
    int e;
    int* I =new int[n];
    for (int k = 0; k < n; k++)
    {
        cout<<"Enter Index of Dimension: "<<k+1<<endl;
        cin>> e;
        I[k]= e;
    }
    int p = 1;
    int q = 0;
    int d = n;
    //k,l variables in for loops are used bcz in wikipedia article they have also use k,l in their formula
    for (int k = 0 ; k < d; k++)
    {   
        for (int l = k+1 ; l < d; l++)
        {
            p = p * s[l];
        }
        q = q + I[k]*p;
        p = 1;         
    }
  int  address = int(baseAddress)+(q*size_dt);
    cout<<"The Base Address Is "<<int(baseAddress)<<endl;
    cout<<"The address of Given Indexes "<<address<<endl;
        delete s;
        s = nullptr;
        delete I;
        I = nullptr;
        delete arr;
        arr = nullptr;
    return 0;
}
// (xYZ+yZ+z)
// a[s0][s1][s2][s3][s4][s5];
//    3   2   2
//  (i0*S1+id-3(Sd-2 x Sd-1 x Sd)+id-2(Sd-1 x Sd)+id-1(Sd)+id)
//(id + id-1 (sd) + id-2 (sd-1 x sd) + id-3 (sd-2 x sd-1 x sd) + id-4 (sd-3 x sd-2 x sd-1 x sd)....)
//(id +sd(id-1 + id-2 x sd-1 + id-3 x sd-2 x sd-1 + id-4 x sd-3 x sd-2 x sd-1))
//id + sd(id-1 + sd-1(id-2 + id-3 x sd-2 + id-4 x sd-3 x sd-2))

// a[i0][i1][i2][i3][i4][i5]
//    1   2   0
//    address btado
// a[1][2][5][3][4]
// a[0][0][0][0][0](i0*s1*s2*s3*s4*s5+i1*s2*s3*s4*s5+i2*s3*s4*s5............)*size of datatype
// a[2][1](2 * 2 + 1)
// arr[2][4][3][4]
//        s1 s2 s3

// a[2][1][2][2]     (2*4*3*4+1*3*4+2*4+2) =118 
//   i0 i1 i2 i3

// a[2][3][2]=a[1][1][1]=
// {
// {{{1},{2}},
// {{3},{4}},
// {{5},{6}}},
// {{{7},{8}},
// {{9},{10}},
// {{11},{12}}}
// }
// D[X][Y][Z]->D[x][y][z] =[x +Xy+XYz]
// [i1 + S1 x i2 + S1 x S2 x i3 + s1 x s2 x s3 x i4]
//D[2][2][2]->D[1][1][1] =[i0+S0*i1+S0*S1*i2.............+s0.....Sn-1*in]
// base == 2000 =a[0][0][0]
// a[2][2][2]
    // {{000,001},{010,011}},
    // {{100,101},{110,111}}
// {000,010,100,110,001,011,101,111}
//s0 s1 s2 == X Y  Z
// a[1][1][1]
//i0 i1 i2  == x y z
// S= {2,2,2}
//I={0,1,2}
// int a[5]; a[0]
// a[2];
// B.A+i*size_dt
// a[0] =200
// a[3] =212
//      S0 s1
    //  R  C      
// int a[2][2]; 200
//   i0 i1
//  r  c 
// a[0][1]
// B.A+(rC+c)*size_dt
//200+(0*2+1)*4=204
// B.A+(xYZ+yZ+z)*size_dt
// B.A+(i0*S1*S2+i1*S2+i2)
// B.A+(i0*S1......Sn-1+i1*S2.......Sn-1+i2........................)
// int p=1;
// int sum =0;
// for(i=0;i<n;i++){
//     for (int j = i+1; j<n; j++)
//     {
//         p = p*S[j];
//     }   
//       sum=sum+I[j]*p;
//       p=1;
// }
// a[3][3];
// [1,2,3]
// [4,5,6]
// [7,8,9]
//a[1][1]
//[1,2,3,4,....9]
// a[1][1]