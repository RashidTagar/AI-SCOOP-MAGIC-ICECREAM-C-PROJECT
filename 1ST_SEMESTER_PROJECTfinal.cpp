#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <windows.h>
using namespace std;

class IceCreamMachine {
private:
    string buttons[4] = {"1 Red", "2 Yellow", "3 Green", "4 Pink"};
    string flavours[4] = {"Strawberry", "Whitecream", "Chocolate", "Pink Flavour"};
    string functions[4] = {
        "Button 1 FOR Strawberry FLAVOUR",
        "Button 2 FOR Whitecream FLAVOUR",
        "Button 3 FOR Chocolate FLAVOUR",
        "Button 4 FOR Pink FLAVOUR"
    };
    string actualPrice[4]   = {"RS 100", "RS 200", "RS 300", "RS 400"};
    string discountPrice[4] = {"RS 50",  "RS 100", "RS 150", "RS 200"};

    int button;
    string username;
    string password;
    int wallet = 0;



    void setColor(int color){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    }

    void animatedText(const string &text, int delay = 25){
        for (char c : text) {
            cout<<c << flush;
            Sleep(delay);
        }
        cout << endl;
    }

    void animatedBox(const string &text, int color = 14){
        setColor(color);
        int len = text.length();

        cout << "\n   ";
        for (int i = 0; i < len + 6; i++) cout << "=";

        cout << "\n   ||  ";
        setColor(11);

        for (char c : text) {
            cout << c << flush;
            Sleep(35);
        }

        setColor(color);
        cout << "  ||\n   ";

        for (int i = 0; i < len + 6; i++) cout << "=";
        cout << "\n\n";

        setColor(7);
    }

    void printBox(const string& text, int color = 14) {
        setColor(color);
        int len = text.length();
        cout << "\n   ";
        for (int i = 0; i < len + 6; i++) cout << "=";
        cout << "\n   ||  " << text << "  ||\n   ";
        for (int i = 0; i < len + 6; i++) cout << "=";
        cout << "\n\n";
        setColor(7);
    }

    bool processPayment(int price) {
        int payChoice;
        setColor(13);
        cout << "\nChoose Payment Method:\n";
        setColor(7);
        cout << "1. Cash\n";
        cout << "2. Debit Card / Wallet\n";
        cout << "Enter your choice: ";
        cin >> payChoice;

        if (payChoice == 1) {
            setColor(10);
            cout << "\nYou chose to pay with Cash on Delivery.\n";
            setColor(7);
            return true;
        }
        else if (payChoice == 2) {
            string cardNumber, cardHolderName, expiryDate, cvv;

            cin.ignore();

            cout << "Enter Card Holder Name: ";
            getline(cin, cardHolderName);

            cout << "Enter Card Number (16 digits): ";
            getline(cin, cardNumber);

            cout << "Enter Expiry Date (MM/YY): ";
            getline(cin, expiryDate);

            cout << "Enter CVV (3 digits): ";
            getline(cin, cvv);

            if (cardNumber.length() != 16 || cvv.length() != 3) {
                setColor(12);
                cout << "\nInvalid card details entered. Payment failed.\n";
                setColor(7);
                return false;
            }

            setColor(10);
            cout << "\nPayment of RS " << price << " processed successfully via Debit Card.\n";
            setColor(7);
            return true;
        }
        else {
            setColor(12);
            cout << "Invalid payment option selected.\n";
            setColor(7);
            return false;
        }
    }




    void welcomeMessage() {
        animatedBox("WELCOME DEAR MITHA MARHOO TO SCOOP MAGIC ICECREAM SHOP", 14);
        Sleep(600);
        setColor(10);
        animatedText("FROM RASHID TAGAR  |  ROLL NO: 05525SW", 35);
        setColor(7);
        Sleep(700);
    }

    void signUp() {
        setColor(11);
        animatedText("PLEASE SIGN UP TO CONTINUE...", 30);
        setColor(7);

        cout << "\nEnter Username: ";
        setColor(10); cin >> username; setColor(7);

        cout << "Create Password: ";
        setColor(12); cin >> password; setColor(7);

        wallet = 50;

        setColor(10);
        cout << "\nSIGN UP SUCCESSFUL!\n";
        cout << "You received RS 50 BONUS in your wallet.\n";
        setColor(7);

        cout << "Press any key to continue...";
        getch();
    }

    void showMenu() {
        setColor(14);
        cout << "\nChoose what you want to see:\n";
        setColor(11);
        cout<<":DON't FORGET TO VISIT BUTTON 3: " <<endl;
        cout << "1. Current Month Selling Prices\n";
        cout << "2. Ice Cream Colours\n";
        cout << "3. Ice Cream Flavours (Order Now)\n";
        cout << "4. Offers on Ice Cream\n";
        cout << "5. Exit\n";
        setColor(7);
    }

    void showPrices() {
        setColor(13);
        cout << "\nOLD PRICES:\n";
        setColor(7);

        for (int i = 0; i < 4; i++)
            cout << flavours[i] << " = " << actualPrice[i] << endl;

        Sleep(600);
        setColor(14);
        cout << "\nNOVEMBER SALE PRICES (50% OFF):\n";
        setColor(7);

        for (int i = 0; i < 4; i++)
            cout << flavours[i] << " = " << discountPrice[i] << endl;

        cout << "\nPress any key to go back...";
        getch();
    }

    void showColours() {
        setColor(9);
        cout << "\nICE CREAM BUTTON COLOURS:\n";
        setColor(7);

        for (int i = 0; i < 4; i++)
            cout << buttons[i] << endl;

        cout << "\nPress any key to go back...";
        getch();
    }

    void showFlavours() {
        setColor(13);
        cout << "\nICE CREAM FLAVOURS AVAILABLE:\n";
        setColor(7);

        for (int i = 0; i < 4; i++)
            cout << functions[i] << endl;
    }

    void showOffers() {
        setColor(13);
        cout << "\nCURRENT OFFERS ON ICE CREAM:\n";
        setColor(7);
        cout << "1. Strawberry 50% OFF\n";
        cout << "2. Whitecream 50% OFF\n";
        cout << "3. Chocolate 50% OFF\n";
        cout << "4. Pink Flavour 50% OFF\n";
        cout << "\nPress any key to go back...";
        getch();
    }

    int selectFlavour() {
        setColor(13);
        cout << "\nSELECT YOUR FLAVOUR BUTTON: ";
        setColor(7);
        cin >> button;

        string flavourName;
        int price = 0;

        switch (button) {
            case 1: flavourName = "Strawberry"; price = 50; break;
            case 2: flavourName = "Whitecream"; price = 100; break;
            case 3: flavourName = "Chocolate"; price = 150; break;
            case 4: flavourName = "Pink Flavour"; price = 200; break;
            default:
                setColor(12);
                cout << "Invalid choice.\n";
                setColor(7);
                Sleep(900);
                return 0;
        }

        setColor(10);
        cout << "\nYou selected: " << flavourName << endl;
        setColor(14);
        cout << "SALE PRICE: RS " << price << "\n\n";
        setColor(7);

        bool paymentSuccess = processPayment(price);
        if (!paymentSuccess) {
            setColor(12);
            cout << "\nOrder cancelled due to payment failure.\n";
            setColor(7);
            Sleep(1500);
            return 0;
        }

        setColor(9);
        cout << " PLEASE ENTER YOUR ADDRESS WHERE YOU WANT TO GET YOUR ORDER " << endl;

        string name, address, phone;

        cout << "Enter Your Name: ";
        setColor(10);
        cin >> name;
        setColor(7);

        cout << "Enter Your Address: ";
        cin.ignore();
        getline(cin, address);

        while (true) {
            cout << "Enter Pakistani 11-Digit Phone Number: ";
            setColor(10);
            cin >> phone;
            setColor(7);

            if (phone.length() == 11 && phone[0] == '0' && phone[1] == '3')
                break;

            setColor(12);
            cout << "Invalid Number! Pakistani numbers start with 03 and must be 11 digits.\n";
            setColor(7);
        }

        setColor(10);
        cout << "\nYour order has been booked successfully!\n";
        setColor(10);
        cout << " THANKS FOR ORDERING !!! " << endl;
        setColor(14);
        cout << "Rider is coming towards your location in 5 minutes.\n\n";
        setColor(7);

        cout << "Press any key to continue...";
        getch();

        return price;
    }
public:
    void run() {
        welcomeMessage();
        signUp();

        int choice;

        while (true) {
            system("cls");
            printBox("SCOOP MAGIC ICECREAM MACHINE MENU", 11);
            showMenu();

            cout << "\nEnter your choice: ";
            cin >> choice;

            system("cls");

            if (choice == 1) showPrices();
            else if (choice == 2) showColours();
            else if (choice == 3) { showFlavours(); selectFlavour(); }
            else if (choice == 4) showOffers();
            else if (choice == 5) break;
            else {
                setColor(12);
                cout << "Invalid option.\n";
                setColor(7);
                Sleep(900);
            }
        }

        setColor(10);
        cout << "\nTHANK YOU FOR VISITING SCOOP MAGIC ICECREAM SHOP!\n";
        setColor(7);
        animatedText("HAVE A SWEET DAY!", 30);
    }
};

int main() {
    IceCreamMachine machine;
    machine.run();
    return 0;
}
