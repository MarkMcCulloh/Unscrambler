 //   Made by Mark McCulloh   //
//Comments written |1/1/2010|//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

string line;
int wordval;
int numoflines;
string number;
int numoflinescall;
string ans;
int blah;
string filename;
string scrambledf;
bool comma;
string seperation;
int main();

void pause()
{
     cin.get();
     cin.clear();
}

int maketext()
{
     string newlines;
     string nline;
     int choice1;
     int tlop;
     int n;
     wordval = 1;//Set wordval to 1 so multiplication works
     cout << "Enter the filename of the list of words" << endl;
     while(cin.peek() == ' '){
                      cin.ignore();
                      }
     //cin >> filename;
     getline(std::cin,filename);
     //filename.replace(filename.begin(), filename.end(), " ", "");//should work, but causes runtime error
     /*string::size_type pos = 0;
     while ( (pos = filename.find(" ", pos)) != string::npos ) {//this works, for only 1 space
        filename.replace( pos, 1, "" );//changing 1 breaks it
        pos++;
    }
    */
     //filename = filename.replace(" ", "");
     //cin.ignore(12, ' ');
     //cin.ignore(INT_MAX, ' ');
     ifstream infile (filename.c_str());
     if(infile.fail()){
                       cout << filename << " does not exist!" << endl;
                       cin.clear();
                       pause();
                       //cin.ignore(INT_MAX, ' ');
                       main();
                       }
     cout << "How is the wordlist seperated?" << endl;
     cout << "[1] Newlines" << endl << "[2] Commas" << endl;
     cin >> choice1;
     switch(choice1){
                     case 1:
                     comma = false;
                     seperation = "newlines";
                     break;
                     
                     case 2:
                     comma = true;
                     seperation = "commas";
                     break;
                     
                     default:
                     cout << "Im just going to assume you typed 1";
                     comma = false;
                     seperation = "newlines";
                     break;
                     }
     
    // ifstream infile (filename.c_str());//Load wordlist
     ofstream exfile ("numbers.txt");//Load txt for ASCII export
     if (infile.is_open()&&exfile.is_open())//Check if both files opened
    {
        while(!infile.eof())//Find number of words(lines)
        {
        if(comma == false){
        getline(infile,newlines);
        numoflines++;
        }
        else{
              getline(infile,newlines,',');
              numoflines++;        
             }
        }
        infile.clear();
        infile.seekg(0);
        cout << "There are " << numoflines - 1 << " words seperated by " << seperation << "." << endl;
        for(int j = 0;j!=numoflines+1;++j)//Repeat for the amount of
        {
            if(comma == false){
            getline (infile,nline);
            }
            else{
            getline(infile,nline,',');
            }
            for(int a = 0;a!=nline.length();++a)//Repeat for the length of the word
            {
                  
                  wordval *= int(nline[a]);//Multiply current value of the line by each ASCII value
            }
            //cout << wordval << endl; //Can enable to show numbers
            if(j < numoflines)
            {
            exfile << wordval << endl;//Write numbers to file
            }
            wordval=1;//Set wordval to 1 so multiplication works                        
        }//Then go back for the next word
    }else
    {
    infile.clear();
    infile.seekg(0);
    infile.close();//Close files
    exfile.close();
    cout << "Could not open required files" << endl;
    exit(1);
    }
    infile.clear();
    infile.seekg(0); 
    exfile.clear();
   infile.close();//Close files
   exfile.close(); 
}

int uword()
{
    fstream infile("numbers.txt");
    fstream exfile(filename.c_str());
    infile.clear();
    infile.seekg(0);
    exfile.clear();
    exfile.seekg(0);
    string numb[numoflines];
    string lines[numoflines];  
    wordval = 1;
    for(int i=0;i<numoflines;++i)
        {
            if(comma == false){
            getline (infile,number);
            numb[i] = number;
            getline (exfile,line);
            lines[i] = line;
            }
            else{
            getline(infile,number);
            numb[i] = number;
            getline (exfile,line,',');
            lines[i] = line;          
            }
        }
    infile.close();
    exfile.close();    
    string yourword;
    int wf;
    wf = 0;
    cout << endl << "Enter text you wish to unscramble:" << endl;
    cin >> yourword;
    for(int j=0;j!=yourword.length();++j)
    {
            wordval *= int(yourword[j]);
    }
    pause();
    stringstream val;
    val << wordval;
    for(int k=0;k<numoflines;++k)
    {
            if(numb[k] == val.str())
            {
                       cout << "Your word unscrambled is " << lines[k] <<"." << endl << "It was number " << k << " on the list. ASCII: " << numb[k] << "." << endl << endl;
                       wf = 1;
            }
            }
   if(wf == 0)
    {
          cout << yourword << " was not found in the wordlist." << endl;

    }   
    pause();
}

int utext()
{
    int snumoflines;
    int temp;
    string newlines;
    snumoflines = 0;    
    cout << "Enter the name of the scrambled list of words" << endl;
    cin >> scrambledf;
    ifstream scrambled(scrambledf.c_str());
    ofstream unscrambled("unscrambled.txt");
        while(scrambled.good())//Find number of words(lines)
        {
        getline(scrambled,newlines);
        snumoflines++;
        }  
    scrambled.clear();
    scrambled.seekg(0);
    ifstream infile("numbers.txt");
    ifstream exfile(filename.c_str());
    infile.clear();
    infile.seekg(0);
    exfile.clear();
    exfile.seekg(0);
    string numb[numoflines];
    string lines[numoflines];  
    wordval = 1;
    for(int i=0;i<numoflines;++i)
        {
        getline (infile,number);
        numb[i] = number;
        getline (exfile,line);
        lines[i] = line;
        //cout << lines[i] << endl;
        }
    infile.close();
    exfile.close();
    infile.clear();
    infile.seekg(0);
    exfile.clear();  
    cout << "Press enter to take " << scrambledf << " then unscramble it to unscrambled.txt" << endl;
    pause();
        scrambled.clear();
        scrambled.seekg(0);
        cout << snumoflines << " words" << endl;
        for(int j = 0;j < snumoflines;++j)
        {
        if(comma == false){
            getline (scrambled,ans);
            }
        else{
            getline(scrambled,ans);      
            }        
                for(int a = 0;a!=ans.length();++a)
                {
                wordval *= int(ans[a]);
                }
                  
    stringstream ss;
    ss << wordval;
    for(int i=0;i < numoflines;++i)
    {
    if(numb[i] == ss.str())
       {
       unscrambled << lines[i] << ",";
       cout << ", " << lines[i];
       }
    wordval = 1; 
}     
}    

cout << endl << "Success, press enter to go back to options menu" << endl;
    scrambled.close();
    unscrambled.close();
pause();
}



int main()
{
 int q;
 q =0;
 cout << "UNSCRAMBLER" << endl << "Made by Mark McCulloh" << endl << "----------------------------------------------------" << endl;
 cout << "Press enter to start" << endl;
 pause();
 maketext(); 
 cout << "Creating numbers.txt with ASCII values..." << endl;
 cout << endl << "Word encryption successful!" << endl;
 cout << "----------------------------------------------------" << endl;
 while(q == 0)
 {
 int choice; 
  cout << "Choose an option:" << endl << "[1] Unscramble word" << endl;
  cout << "[2] Unscramble text file" << endl << "[3] Exit" << endl;
  cin >> choice;
  
  switch(choice)
               {
          case 1:
               cout << "----------------------------------------------------" << endl;
               cout << "Unscramble a word" << endl;
               uword();
               cout << "Push enter to return to options screen" << endl;
               cout << string(50, '\n');
               cout << "UNSCRAMBLER" << endl << "Made by Mark McCulloh" << endl << "----------------------------------------------------" << endl;
               break;
          case 2:
               cout << "----------------------------------------------------" << endl;
               cout << "Unscramble a text file" << endl;
               utext();
               cout << string(50, '\n');
               cout << "UNSCRAMBLER" << endl << "Made by Mark McCulloh" << endl << "----------------------------------------------------" << endl;
               break;
          case 3:
               exit(0);
               break;
          default:
               cout << "No... just push enter to quit." << endl;
               pause();
               exit(0);
               }
               
}
 return 0;
}

