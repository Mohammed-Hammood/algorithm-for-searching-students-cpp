#include <iostream>
#include <time.h>
#include <string.h>
#define Line cout<<"___________________________"<<endl;
using namespace std;

struct Student{
    char first_name[50];
    char surname[50];
    int group;
    int scores[3];
};


int checkIncluded(Student arr[], int n, int includedNum){
    int k = 0;
    for(int i=0; i<n; i++){
            for(int j=0; j<3; j++){
                if(arr[i].scores[j] == includedNum){
                    k +=1;
                    break;
                    }
                }
    }
    return k;
}
int checkExcluded(Student arr[], int n, int ExcludedNum){
    int k = 0;
    bool flag=false;
    for(int i=0; i<n; i++){
            for(int j=0; j<3; j++){
                if(arr[i].scores[j] == ExcludedNum){
                    flag = true;
                    break;
                    }
                }
                if(flag == false){k +=1;}
                else {flag = false;}
    }
    return k;
}
void Search(Student arr[], int n, int *result, int myNum, string status){
        int r=0;
        if(status == "Included"){
                for(int i=0; i<n; i++){
                for(int j=0; j<3; j++){
                    if(arr[i].scores[j] == myNum){
                            result[r] = i;
                            r +=1;
                            break;
                        }
                    }
                }
        }else{
        //----------------------------------
                bool flag = false;
                for(int i=0; i<n; i++){
                    for(int j=0; j<3; j++){
                        if(arr[i].scores[j] == myNum){
                                flag = true;
                                break;
                            }
                        }
                    if(flag == false){
                            result[r] = i;
                            r +=1;
                    }else{
                        flag = false;
                    }
            }

        /// --------------------------------
        }


}


void output(Student arr[], int n){
    for(int i=0; i<n; i++){
            cout<<i+1<<"."<<endl;
            cout<<"Student: "<<arr[i].first_name<<" "<<arr[i].surname<<endl;
            cout<<"Group: "<< arr[i].group<<endl;
            cout<<"Scores: [";
            for(int j=0; j<3; j++){
                    cout<<arr[i].scores[j]; if(j!= 2){cout<<", ";}}cout<<"]"<<endl; Line;
    }
}

void input(Student arr[], int n){
    const char *names[] = {"Ben", "Sara", "Mash", "Akeel", "Sam", "Mark", "John"};
    const char * surnames[] = {"Smith", "Taylor", "Brown", "Williams", "Wilson", "Johnson"};
    const int groups[] = {932020, 932021, 932022,932023,932024,932025, 932026,932027,932028};
    srand(time(0));
    for(int i=0; i<n; i++){
        int groups_size = rand()%(sizeof(groups)/sizeof(groups[0]));
        int names_size = rand()%(sizeof(names)/sizeof(names[0]));
        int surnames_size = rand()%(sizeof(surnames)/sizeof(surnames[0]));
        strcpy(arr[i].first_name, names[names_size] );
        strcpy(arr[i].surname, surnames[surnames_size]);
        arr[i].group = groups[groups_size];
        for(int j=0; j<3; j++){arr[i].scores[j] = 2+(rand()%4);}
    }
}



void printResult(Student arr[], int n, int* result, int k){
    int index;
    for(int i=0; i<k;i++){
            index = result[i];
            cout<<i+1<<"."<<endl;
            cout<<"Student: "<<arr[index].first_name<<" "<<arr[index].surname<<endl;
            cout<<"Group: "<< arr[index].group<<endl;
            cout<<"Scores: [";
            for(int j=0; j<3; j++){cout<<arr[index].scores[j]; if(j!= 2){cout<<", ";}}
                    cout<<"]"<<endl; Line;
    }
}

int main(){
    //myNum is number that you want to exclude or include to print
    int n = 10, number, myNum=2;
    string status;
    Student stud[n];
    input(stud, n);
    //If you want to print all the students, so uncomment the following function:
     output(stud, n);



    status = "Excluded";
   //status = "Included";

    if(status =="Excluded"){
        number = checkExcluded(stud, n, myNum);
        if (number == n){
         cout<<"All the students have number ("<<myNum<<")! "<<endl;
        }else{
            cout<<"Number of students who does not have scores("<<myNum<<"): "<<number<<endl<<endl;
            int*result = new int[number];
            Search(stud, n, result, myNum, status);
            printResult(stud, n, result, number);
            delete[] result;
        }
    }
    else{
        number = checkIncluded(stud, n, myNum);
        if(number==0){
            cout<<"There is no student who has scores ("<<myNum<<")! "<<endl;
        }else{
            cout<<"Number of students with scores("<<myNum<<"): "<<number<<endl<<endl;
            int*result = new int[number];
            Search(stud, n, result, myNum, status);
            printResult(stud, n, result, number);
            delete[] result;
        }
    }



return 0;
}
