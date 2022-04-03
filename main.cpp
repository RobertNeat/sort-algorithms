#include <iostream>
#include <cstdlib>  //generating random numbers
#include <time.h>
#include <windows.h> //system cls

using namespace std;


//functions from previous project
void allocateMemory1D(int *&arr, int n){   arr = new int[n];   }
void allocateMemory2D(int **&arr, int w, int k)
{   arr= new int*[w];
    for(int x=0;x<w;x++){  arr[x]=new int[k];  }}

void fillArray1D(int *arr, int n, int a, int b){
    srand (time(NULL));
    for(int x=0;x<n;x++){
        arr[x]=rand()%(b-a+1)+a;// numbers between <a,b>
}}
void fillArray2D(int **arr, int w, int k, int a, int b){
    srand (time(NULL));
    for(int x=0;x<w;x++){
        for(int y=0;y<k;y++){
            arr[x][y]=rand()%(b-a+1)+a;// numbers between <a,b>
}}}

void deleteArray1D(int *&arr){  delete[] arr;   }
void deleteArray2D(int **&arr, int w){
    for(int x=0;x<w;x++){    delete[] arr[x];}
    delete[] arr;
}

void display1D(int* arr, int n){
    for(int x=0;x<n;x++){
        cout<<arr[x]<<" ";
}}
void display2D(int** arr, int w, int k){
    for(int x=0;x<w;x++){
        for(int y=0;y<k;y++){
            cout<<arr[x][y]<<" ";
    }cout<<endl;}}

void menu(){
cout<<endl<<"Menu:"<<endl;
cout<<"1. Bubble sort"<<endl;
cout<<"2. Selection sort"<<endl;
cout<<"3. Insert sort"<<endl;
cout<<"4. Bubble sort 2D"<<endl;
cout<<"5. Quit"<<endl;
cout<<"Choosing:";
}
void line(){cout<<"----------------------------------------------------";}
void lineD(){cout<<"===================================================";}


void bubbleSort(int* arr, int n, int mode){
    line();
    cout<<endl<<"Bubble sort"<<endl;
    cout<<"Before sorting:";
    display1D(arr,n);//display array before sorting
    if(mode==0){    //descending
        for(int a=n-1;a>=0;a--){
            for(int b=0;b<n-1;b++){
                if(arr[b]<arr[b+1]){
                    swap(arr[b],arr[b+1]);
                }
            }
        }
    }
    else if(mode==1){   //ascending
        for(int a=n-1;a>=0;a--){
            for(int b=0;b<n-1;b++){
                if(arr[b]>arr[b+1]){
                    swap(arr[b],arr[b+1]);
                }
            }
        }
    }
    cout<<endl<<"After sorting:";
    display1D(arr,n);//display array after sort
    cout<<endl;
}
void selectionSort(int* arr, int n, int mode){
    line();
    cout<<endl<<"Selection sort"<<endl;
    cout<<"Before sorting:";
    display1D(arr,n);  //display array before sorting

    if(mode==0){    //descending
        int minIndex;   //index wchich carry smallest value
        for(int a=0;a<n-1;a++){
            minIndex=a;
            for(int b=a+1;b<n;b++){ //loop that chooses the samllest element from array
                if(arr[minIndex]>arr[b]){
                    minIndex=b;
            }}
            swap(arr[a],arr[minIndex]); //swap the smallest value from sorted section with unsorted section
    }}
    else if(mode==1){   //ascending
        int maxIndex;
        for(int a=0;a<n-1;a++){
            maxIndex=a;
            for(int b=a+1;b<n;b++){
                if(arr[b]>arr[maxIndex]){
                    maxIndex=b;

            }}
            swap(arr[a],arr[maxIndex]);
    }}
    cout<<endl<<"After sorting:";
    display1D(arr,n);
    cout<<endl;
}
void insertSort(int* arr, int n, int mode){
    line();
    cout<<endl<<"Insert sort"<<endl;
    cout<<"Before sorting";
    display1D(arr,n);  //display array before sorting

    if(mode==0){
        int tmp,b;
        for(int a=1;a<n;a++){
            tmp=arr[a];
            b=a-1;

            while(b>=0 && arr[b]>tmp){
                arr[b+1]=arr[b];
                --b;
            }
            arr[b+1]=tmp;
        }
    }
    else if(mode==1){
        int tmp,b;
        for(int a=1;a<n;a++){
            tmp=arr[a];
            b=a-1;

            while(b>=0 && arr[b]<tmp){
                arr[b+1]=arr[b];
                --b;
            }
            arr[b+1]=tmp;
        }
    }

    cout<<endl<<"After sorting:";
    display1D(arr,n);
    cout<<endl;
}
void bubbleSort2D(int** arr, int w, int k, int mode, int colNum){
    line();
    cout<<endl<<"Bubble sort 2D"<<endl;
    cout<<"Before sorting:"<<endl;
    display2D(arr,w,k);
    colNum=colNum-1;
    if(mode==0){    //descending
            for(int a=0;a<w;a++){
                for(int b=0;b<w-1;b++){
                    if(arr[b][colNum]<arr[b+1][colNum]){
                        swap(arr[b],arr[b+1]);
    }}}}
    else if(mode==1){   //ascending
            for(int a=0;a<w;a++){
                for(int b=0;b<w-1;b++){
                    if(arr[b][colNum]>arr[b+1][colNum]){
                        swap(arr[b],arr[b+1]);
    }}}}

    cout<<endl<<"After sorting:"<<endl;
    display2D(arr,w,k);
}


int main()
{
    line();
    //one-dimensional array memory allocation 
    cout<<endl<<"One-dimensional array declaration:"<<endl;
    cout<<"Input number of cells for one-dimensional array:";
    int a;
    cin>>a;
    int* arr1 = new int;
    allocateMemory1D(arr1,a);

    line();
    //two-dimensional array memory allocation
    cout<<endl<<"Two-dimensional array declaration:"<<endl;
    int b,c;
    cout<<"Input number of rows:";
    cin>>b;
    cout<<"Input number of columns:";
    cin>>c;
    int** arr2 = nullptr;
    allocateMemory2D(arr2,b,c);

    lineD();
    //generating random numbers from interval as input for one-dimensional array
    cout<<endl<<"Generating content of one-dimensional array:"<<endl;
    cout<<"Input interval from which will be generated numbers <a,b>"<<endl;
    cout<<"Input min:";
    int d,e;
    cin>>d;
    cout<<"Input max:";
    cin>>e;
    fillArray1D(arr1,a,d,e);

    line();
    //generating random numbers from interval as input for two-dimensional array
    cout<<endl<<"Generating content of two-dimensional array:"<<endl;
    cout<<"Input interval from which will be generated numbers <a,b>"<<endl;
    cout<<"Input min:";
    int f,g;
    cin>>f;
    cout<<"Input max:";
    cin>>g;
    fillArray2D(arr2,b,c,f,g);

    system("cls");  //clear terminal

    lineD();
    //display generated one-dimensional array
    cout<<endl<<"Generated array:"<<endl;
    cout<<"One-dimensional:";
    display1D(arr1,a);
    cout<<endl;

    line();
    //display generated two-dimensional array
    cout<<endl<<"Two-dimensional:"<<endl;
    display2D(arr2,b,c);
    cout<<endl;
    line();



    int mode;   //sorting mode used in specific cases
    menu();
    int option=0;
    cin>>option;
    while(option!=5){
        switch (option)
      {
         case 1:
            cout<<"Choose mode (0-descending,1-ascending):";
            cin>>mode;
            bubbleSort(arr1,a,mode);
            line();
            menu();
            cin>>option;
            break;
         case 2:
            cout<<"Choose mode (1-descending,0-ascending):";
            cin>>mode;
            selectionSort(arr1,a,mode);
            line();
            menu();
            cin>>option;
            break;
         case 3:
            cout<<"Choose mode (1-descending,0-ascending):";
            cin>>mode;
            insertSort(arr1,a,mode);
            line();
            menu();
            cin>>option;
            break;
         case 4:
            cout<<"Choose mode (0-descending,1-ascending):";
            cin>>mode;
            int column;
            cout<<"Choose column, by which should be sorted:";
            cin>>column;
            bubbleSort2D(arr2,b,c,mode,column);
            line();
            menu();
            cin>>option;
            break;
         default:
            line();
            menu();
            cin>>option;
      }
    }


    deleteArray1D(arr1);
    deleteArray2D(arr2,b);

    return 0;
}


