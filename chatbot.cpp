#include<bits/stdc++.h>
using namespace std;

void chatbotReply(string message){
    if(message == "Hello" || message == "Hi"){
        cout<<"Chatbot: Hello, Welcome to our service"<<endl;
    }

    else if(message == "How are you"){
        cout<<"Chatbot: I am fine. How can I help you"<<endl;
    }

    else if(message == "Products"){
        cout<<"Chatbot: We sell Laptops, Mobiles, Desktops and their accessories"<<endl;
    }

    else if(message == "Price"){
        cout<<"Chatbot: Prices start from Rs.5000"<<endl;
    }

    else if(message == "Delivery"){
        cout<<"Chatbot: Delivery takes 3 to 5 days"<<endl;
    }
    
    else if(message == "Payment"){
        cout<<"Chatbot: We accept Upi, cards, and net banking"<<endl;
    }

    else if(message == "Bye"){
        cout<<"Chatbot: Thank you for visiting! Have a nice day"<<endl;
    }

    else{
        cout<<"Chatbot: Sorry! I did not understand"<<endl;
    } 
}

int main(){
    string usermessage;

    cout<<"========Customer Support Chatbot========"<<endl;

    cout<<"Type 'Bye' to exit"<<endl;

    while(true){
        cout<<"You: ";
        getline(cin,usermessage);

        chatbotReply(usermessage);

        if(usermessage == "Bye"){
            break;
        }
    }
    return 0;
}