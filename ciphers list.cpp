#include<iostream>
#include<string>
#include <cctype>
#include<vector>
#include<algorithm>
#define endl "\n"
#define all(v)  v.begin() ,v.end()
using namespace std;

class node {
public:
    int val;
    node* next;
};

void Rail_fence(int choice );
void vignere_Encrypt();
void vignere_Decrypt();
void Atbash_Cipher();


int main()
{
    cout<<"Welcome to message cipher and decipher program."<<endl;
    while (true)
    {
        cout<<"What do you want to do?"<<endl;
        cout<<"1-Cipher a message"<<endl<<"2-Decipher a message"<<endl<<"3-Exit"<<endl<<endl;
        string user_choice1;
        cout<<"Please enter a number from 1 to 3"<<endl;
        cin>>user_choice1;

        while (true)
        {
            if (user_choice1!="1" and user_choice1!="2" and user_choice1!="3" )
            {
                cout<<"Invalid choice. Please enter a number from 1 to 3"<<endl;
                cin>>user_choice1;
            }
            else break;
        }

        if (user_choice1=="1")
        {
            cout<<endl;
            string user_choice2;
            cout<<"Which Cipher do you want to use?"<<endl<<"1-Atbash Cipher"<<endl<<"2-Vignere Cipher"<<endl<<"3-Rail-fence Cipher"<<endl;
            cin>>user_choice2;

            while (true)
            {
                if (user_choice2!="1" and user_choice2!="2" and user_choice2!="3" )
                {
                    cout<<"Invalid choice. Please enter a number from 1 to 3"<<endl;
                    cin>>user_choice2;
                }

                else break;
            }
            cout<<endl;

            if (user_choice2=="1")
            {
                Atbash_Cipher();
                cout<<endl;
            }

            if (user_choice2=="2")
            {
                vignere_Encrypt();
                cout<<endl;
            }

            if (user_choice2=="3")
            {
                Rail_fence(1);
                cout<<endl;
            }

        }

        if (user_choice1=="2")
        {
            cout<<endl;
            string user_choice2;
            cout<<"Which Decipher do you want to use?"<<endl<<"1-Atbash Decipher"<<endl<<"2-Vignere Decipher"<<endl<<"3-Rail-fence Decipher"<<endl;
            cin>>user_choice2;
            while (true)
            {
                if (user_choice2!="1" and user_choice2!="2" and user_choice2!="3" )
                {
                    cout<<"Invalid choice. Please enter a number from 1 to 3"<<endl;
                    cin>>user_choice2;
                }

                else break;
            }
            cout<<endl;

            if (user_choice2=="1")
            {
                Atbash_Cipher();
                cout<<endl;
            }

            if (user_choice2=="2")
            {
                vignere_Decrypt();
                cout<<endl;
            }

            if (user_choice2=="3")
            {
                Rail_fence(2);
                cout<<endl;
            }
        }


        if (user_choice1=="3")
        {
            break;
        }
    }

}


void Atbash_Cipher()
{
    string user_choice3;
    cout<<"1-Use the whole alphabet"<<endl<<"2-Divide the alphabet into 2 groups"<<endl;
    cin>>user_choice3;
    while (true)
    {
        if (user_choice3!="1" and user_choice3!="2")
        {
            cout<<"Invalid choice. Please enter 1 or 2"<<endl;
            cin>>user_choice3;
        }

        else break;
    }
    cout<<endl;
    if (user_choice3=="1")
    {
        string msg,y,output;
        cin.ignore();
        cout<<"Enter the message: ";
        getline(cin, msg);
        for (char character : msg)
        {
            if (isalpha(character))
            {
                y=y+char(toupper(character));
            }
        }
        for (char character : y)
        {
            output += char(int(character) + 25 - 2 * (int(character) - 65));
        }
        cout<<"The output message is: "<< output<<endl;
    }

    if (user_choice3=="2")
    {
        string msg,y,output;
        cin.ignore();
        cout<<"Enter the message: ";
        getline(cin, msg);
        for (char character : msg)
        {
            if (isalpha(character))
            {
                y=y+char(toupper(character));
            }
        }
        for (char character : y)
        {
            if (int(character)>=65 and int(character)<=77)
            {
                output += char(int(character) + 12 - 2 * (int(character) - 65));
            }
            if (int(character)>=78 and int(character)<=90)
            {
                output += char(int(character) + 12 - 2 * (int(character) - 78));
            }
        }
        cout<<"The output message is: "<< output<<endl;
    }
}

void vignere_Encrypt() {
    string message, keyword;
    cin.ignore();
    cout << "Enter the message (up to 80 characters): ";
    getline(cin, message);
    cout << "Enter the keyword (up to 8 characters): ";
    getline(cin, keyword);
    if (message.length() > 80 || keyword.length() > 8) {
        cout << "Message or keyword exceeds the length limit." << endl;
        return;
    }
    string encryptedMessage;
    int keywordIndex = 0;

    for (char &ch: message) {
        if (isalpha(ch))
            ch = toupper(ch);
    }

    for (char &ch: keyword) {
        ch = toupper(ch);
    }
    while (keyword.length() < message.length()) {
        keyword += keyword[keywordIndex++];
        keywordIndex %= keyword.length();
    }

    for (int i = 0; i < message.length(); i++) {
        char ch = message[i];
        if (isalpha(ch)) {
            char keywordChar = keyword[i];
            int shift = (keywordChar - 'A') % 26;
            ch = ((ch - 'A' + shift) % 26) + 'A';
        }
        encryptedMessage += ch;
    }
    cout << "Encrypted message: " << encryptedMessage << endl;
}

void vignere_Decrypt() {
    string encryptedMessage, keyword;
    cin.ignore();
    cout << "Enter the message (up to 80 characters): ";
    getline(cin, encryptedMessage);
    cout << "Enter the keyword (up to 8 characters): ";
    getline(cin, keyword);
    if (encryptedMessage.length() > 80 || keyword.length() > 8) {
        cout << "Message or keyword exceeds the length limit." << endl;
        return;
    }
    string decryptedMessage = "";
    int keywordIndex = 0;

    for (char& ch : keyword)
        ch = toupper(ch);

    while (keyword.length() < encryptedMessage.length()) {
        keyword += keyword[keywordIndex++];
        keywordIndex %= keyword.length();
    }

    for (int i = 0; i < encryptedMessage.length(); i++) {
        char ch = encryptedMessage[i];
        if (isalpha(ch)) {
            char keywordChar = keyword[i];
            int shift = (keywordChar - 'A') % 26;
            ch = ((ch - 'A' - shift + 26) % 26) + 'A';
        }
        decryptedMessage += ch;
    }
    cout << "Decrypted message: " << decryptedMessage << endl;
}

void Rail_fence(int choice ) {

    int key;
    string s;
    cin.ignore();
    if (choice == 1) {
        cout << "Please enter the message to cipher : "<<endl;
        getline(cin,s);
        int size = s.size() - count(all(s), ' ');
        remove(all(s), ' ');
        cout << "Please enter the Key : ";
        cin >> key;
        while (!(key <= size / 2)) {
            cout << "Please enter a valid Key : ";
            cin >> key;
        }
        vector<string>v(key,"");

        int x = 0;
        bool flag = 1;

        for (int i =0 ; i < size;i++) {
            v[x] += s[i];
            if (flag)x++;
            else x--;
            if (x == 0 || x == key - 1)flag = !flag;
        }

        cout << "Cipher text : ";
        for (int i = 0; i < key; i++) {
            cout << v[i];
        }
        cout << endl;
    }
    else if (choice == 2) {
        cout << "Please enter the cipher text : " << endl;
        cin >> s;
        cout << "Please enter the Key : ";
        cin >> key;
        while (!(key <= s.size() / 2)) {
            cout << "Please enter a valid Key : ";
            cin >> key;
        }
        vector<vector<char>>v(key,vector<char>(s.size(),'.'));
        string ans = "";
        bool flag = 0;
        int x = 0, y = 0;
        for (int i = 0; i < s.size(); i++) {
            if (x == 0)flag = 1;
            else if (x == key - 1)flag = 0;
            v[x][y] = ' ';
            y++;
            if (flag)x++;
            else x--;
        }
        int position = 0;
        for (int i = 0; i <key; i++) {
            for (int j = 0; j < s.size(); j++) {
                if (v[i][j] == ' ') {
                    if (position < s.size())
                    {
                        v[i][j] = s[position];
                        position++;
                    }
                }
            }
        }
        x = 0; y = 0;
        for (int i = 0; i < s.size(); i++) {
            if (x == 0)flag = 1;
            else if (x == key - 1)flag = 0;
            if (v[x][y] != '.')ans += v[x][y++];
            if (flag)x++;
            else x--;
        }
        cout << "Cipher text is : " << ans << endl;

    }

}
