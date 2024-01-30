#include <iostream>

using namespace std;

bool choiceSelector(int someNum)
{
    if (someNum == 1)
    {
        return true;
    }
    else if (someNum == 2)
    {
        return false;
    }
}
bool getAnswer()
{
    cout << "Enter 1 to Add or 2 to Delete a value" << endl;
    int someAns = 0;
    cin >> someAns;
    if(someAns == 1)
    {
        cout << "ADDING" << endl;
        return choiceSelector(someAns);
        
    }
    else if(someAns == 2)
    {
        cout << "DELETING" << endl;
        return choiceSelector(someAns);
        
    }
    else
    {
        cout << "INVALID RESPONSE" << endl;
        
    }
}


void showList(char someList[],int someLink[], int somePtr)
{
    cout << "Position" << " || " << "List" << " || " << "Link" << endl;
    for (somePtr; someList[somePtr] != NULL; somePtr++)
    {
        cout << somePtr << "         " << someList[somePtr] << "         " << someLink[somePtr] << endl;
    }
}

void addVal( char someL[], int someLk[], int lPtr)
{
    char tempLetter = ' ';
    cout << "Enter a letter to Add:" << endl;
    cin >> tempLetter;
    int i = 0;
    while(someL[i] != NULL)
    {
        if (tempLetter == someL[i])
        {
            cout << "Value already exists!!!" << endl;
            return;
        }
        i++;
    }
    someL[i] = tempLetter;
    showList(someL, someLk, lPtr);
    getAnswer();
}

void reLink(char letter, char someL[], int someLk[], int lPtr)
{

    if (letter == someL[lPtr])
    {
        cout << "Value already exists!!!" << endl;
        return;
    }
    else
    {
        if (letter < someL[lPtr])
        {
            return;
        }
    }
}
int main()
{
    char myList[99] = { 'D','G','J','M','R','W'};
    int temp = 0;
    cout << "List" << endl;
    while( myList[temp] != NULL)
    {
        cout << myList[temp] << endl;
        temp++;
    }
    int myLink[99] = { 1,2,3,4,5,99};
    int listPtr = 0;
    char tempChar;  // value for user to add or delete
    int tempLink =0;
    showList(myList, myLink, listPtr);
    getAnswer();
    if (getAnswer() == true)
    {
        addVal(myList, myLink, listPtr);
    }
    else
    { 
        cout << "some deleting stuff goin on" << endl;
    
    }
}

