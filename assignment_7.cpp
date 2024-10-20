#include<iostream>
using namespace std;

class webhistory{
    string websites[3];
    string remwebsites[5];
    int top1, top2, top;
    
    public:
        webhistory(){
            top1 = -1;
            top2 = -1;
            top = top2;
        }
        void visitedsites(string link){
            if(top1 < 3){
                top1++;
                websites[top1] = link;
            }
        }
        void backnavigate(){
            if(top1 <= 0){ 
                cout << "Stack is empty" << endl;
                return;
            }
            remwebsites[++top2] = websites[top1];  
            top1--;  
            cout << websites[top1] << endl;  
        }

        void ViewCurrentPage(){
            if(top1 >= 0) {
                cout << websites[top1] << endl;
            } else {
                cout << "No current page." << endl;
            }
        }

        void nohistory(){
            if(top1 < 0){
                cout << "No history to show." << endl;
            }
            else{
                printHistory();
            }
        }

        void printHistory(){
            for(int i = 0; i <= top1; i++){
                cout << websites[i] << endl;
            }
        }
};

int main() {
    webhistory h1;
    h1.visitedsites("google.com");
    h1.visitedsites("linkedin.com");
    h1.visitedsites("facebook.com");

    h1.printHistory(); 
    h1.backnavigate(); 
    h1.ViewCurrentPage();  
    h1.nohistory(); 
}