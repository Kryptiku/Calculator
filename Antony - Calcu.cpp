#include <iostream>
#include <conio.h>
#include <limits>
using namespace std;

struct calc
{
    float num1, num2, total;
    char opr;
};

calc arr[10];
string loop_input, opt_input, pointer_memory[10];
int i;
int counter = 0;

void add()
{
    arr[0].total = arr[0].num1 + arr[0].num2;
    cout << arr[0].num1 << " + " << arr[0].num2 << " = " << arr[0].total;
    counter += 1;
}

void sub()
{
    arr[0].total = arr[0].num1 - arr[0].num2;
    cout << arr[0].num1 << " - " << arr[0].num2 << " = " << arr[0].total;
    counter += 1;
}

void mul()
{
    arr[0].total = arr[0].num1 * arr[0].num2;
    cout << arr[0].num1 << " * " << arr[0].num2 << " = " << arr[0].total;
    counter += 1;
}

void div()
{
    arr[0].total = arr[0].num1 / arr[0].num2;
    cout << arr[0].num1 << " / " << arr[0].num2 << " = " << arr[0].total;
    counter += 1;
}

void menu()
{
    system("cls");
	cout << "\tCALCULATOR\n";
	cout << "[1] Basic Calculator\n";
    cout << "[2] History\n";
    cout << "[3] Exit\n";
    cout << "Select an option: ";
}

void history()
{
    for (int i = 9; i > 0; i--)
    {
        arr[i].num1 = arr[i-1].num1;
        arr[i].opr = arr[i-1].opr;
        arr[i].num2 = arr[i-1].num2;
        arr[i].total = arr[i-1].total;
    }
}

void input_validation()
{
    system("cls");
    cout << "Please Enter Computation" << endl;
    
    while(!(cin >> arr[i].num1 >> arr[i].opr >> arr[i].num2))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Syntax Error Please Try Again" << endl;
    }
}

int main()
{
    system("cls");
    menu();
    cin >> opt_input;
    if (opt_input == "1")
    {
        do
        {

            input_validation();
            switch(arr[0].opr){
                case '+':
                add();
                break;

                case '-':
                sub();
                break;

                case '*':
                mul();
                break;

                case '/':
                div();
                break;

                default:
                system("cls");
                cout << "Syntax Error Please Try Again";
                cout << "\nPress Enter To Try Again";
                getch();
                main();
                break;
            }

            i = 0;
            history();
            
            do 
            {
                cout << "\nDo you wish to compute again? Y/N: ";
                cin >> loop_input;

                if (loop_input == "N" || loop_input == "n")
                {
                    main();
                }

                else if (loop_input != "Y" && loop_input != "y" && loop_input != "N" && loop_input != "n") 
                {
                    cout << "\nSyntax Error. Please Try Again.";
                    cout << "\nPress Enter To Continue";
                    getch();
                }
            }

            while (loop_input != "Y" && loop_input != "y");       
        }

        while(loop_input == "Y" || loop_input == "y");
    }

    else if(opt_input == "2")
    {
        cout << "History";
        cout << "\n";
    
        string* pointer = &pointer_memory[0];
    
        for(int i = 0; i < 9; i++)
        {
            pointer_memory[i] = to_string(arr[i].num1) + " " + arr[i].opr + " " + to_string(arr[i].num2) + " = " + to_string(arr[i].total);
            cout << "\n" << pointer_memory[i];
            cout << " [" << pointer + i << "]" << " \n\n"; 
        }
    }

    else if(opt_input == "3")
    {
        system("cls");
        cout << "\tTerminating Program....";
        getch();
        return 0;
    }

    else
    {
        system("cls");
        cout << "Syntax Error Please Try Again";
        cout << "\nPress Enter To Continue";
        getch();
        main();
    }
 
}