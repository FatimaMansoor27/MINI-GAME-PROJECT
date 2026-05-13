#include<iostream>
#include<ctime>
#include<string>
#include <cstdlib>
#include <algorithm>
using namespace std; 
//GLOBAL VARIABLES FOR PERFORMANCE REPORT
int totalScore = 0;
int gamesPlayed = 0;
string bestGame = "none yet";
int bestPercent = 0;
int maxDifficulty[6] = {0, 3, 3, 2, 1, 2};
// FUNCTIONS DECLARATION
int wordscramble(int d);
int wordsearch(int d);
int sudoko(int d);
int tictactoe(int d);
int cardgame(int d);

//PERFORMANCE REPORT FUNCTION
void showReport()
{int average=0; 
    if(gamesPlayed>0)
   average = (totalScore * 100) / (gamesPlayed * 10); // percentage
//BEST SKILL
    string bestSkill = "Problem solving";   // default

    if(bestGame == "Sudoku")
        bestSkill = "Problem solving";       
    
    else if(bestGame == "Word Scramble")
        bestSkill = "Vocabulary Strength";
     
    else if(bestGame == "Word Search")
        bestSkill = "Pattern Recognition";
    
    else if(bestGame == "Tic Tac Toe")
        bestSkill = "Strategic Thinking";
    
    else if(bestGame == "Card Game")
        bestSkill = "Memory Recall";
    
    cout << "\n\n";
    cout << "=============================================\n";
    cout << "           GAMING PERFORMANCE REPORT      \n";
    cout << "=============================================\n\n";

    cout << "Total Games Played    : " << gamesPlayed << endl;
    cout << "Total Score           : " << totalScore <<"/50"<< endl;
    cout << "Average Score         : " << average << "%" << endl;
    cout << "Best Game             : " << bestGame 
         << " (" << bestPercent << "%)"<< endl;
    cout << "Your Skill            : " << bestSkill<<endl;
    cout << "Performance Summary   : ";
    if (average >= 80)
        cout << "Excellent Performance!\nYou can try higher difficulty games. \n";
    else if (average >= 60)
        cout << "Good Job!\n Keep practicing to reach 80%+\n";
    else
        cout << "You can do better\nStart with easier levels next time.\n\n";

    cout << "==============================================\n";
    cout << "     CONGRATULATIONS! All Games Completed! \n";
    cout << "==============================================\n\n";
}


// RANDOM GAME SUGGESTION
int randomgame(int &difficulty, bool played[6][10]) {
    int choice;
    do {
        choice = rand() % 5 + 1; // 1 to 5

        // Adjust difficulty for this game
        int adjustedDifficulty = difficulty;
        while(adjustedDifficulty > maxDifficulty[choice] && adjustedDifficulty > 1) {
            adjustedDifficulty--; // lower difficulty
        }

        difficulty = adjustedDifficulty;

    } while (played[choice][difficulty]);

    return choice;
}

 int wordscramble(int d){ 
  int score = 0;
  string answer;
  
  cout<<"********************** "<<endl;
  cout<<"* WORD SCRAMBLE GAME * "<<endl;
  cout<<"********************** "<<endl; 
   
  if(d==1){
  	 string words[5] = {"evolution","array","skeleton","credit","learn"}; 
    string scrambled[5] = {"volutioen","rayar","tonsklee","cterdi","nlear"};

    for(int i = 0; i < 5; i++)
    {
        cout << "\nUnscramble the word: " << scrambled[i] << endl;
        cout << "Enter correct word: ";
        cin >> answer;

        if(answer == words[i])
        {
            cout << "Correct!\n";
            score++;
        }
        else
        {
            cout << "Wrong! Correct word is: " << words[i] << endl;
        }
    }
    cout<<"\nYour final score is:"<<score<<"out of 5"<<endl;  
	score = (score * 10) / 5;
	 return score;
  }  
  
  else if(d==2){ 
     string words[5] = {"account","customer","beautiful","asteroid","difficult"};
    string scrambled[5] = {"cnacuot","ecmstoru","utabueifl","taserodi","ffidulcit"};
    string answer;
    int score=0;

    for(int i = 0; i < 5; i++)
    {
        cout << "\nUnscramble the word: " << scrambled[i] << endl;
        cout << "Enter correct word: ";
        cin >> answer;

        if(answer == words[i])
        {
            cout << "Correct!\n";
            score++;
        }
        else
        {
            cout << "Wrong! Correct word is: " << words[i] << endl;
        }
    }
    cout<<"\nYour final score is:"<<score<<"out of 5"<<endl; 
    score = (score * 10) / 5;
	 return score;
   } 
     
   else if(d==3){
   	
   	 string words[5] = {"consultant","mysterical","habitually","phenomena","compensate"};
    string scrambled[5] = {"suctanlont","tyrsiemacl","bauthllaiy","menaohpen","pomacesten"};

    for(int i = 0; i < 5; i++)
    {
        cout << "\nUnscramble the word: " << scrambled[i] << endl;
        cout << "Enter correct word: ";
        cin >> answer;

        if(answer == words[i])
        {
            cout << "Correct!\n";
            score++;
        }
        else
        {
            cout << "Wrong! Correct word is: " << words[i] << endl;
        }
    } 
    
    cout<<"\nYour final score is:"<<score<<"out of 5"<<endl;
    score = (score * 10) / 5;
	 return score;
    
   } else { cout<<"invalid difficulty\n";
    score = 0;
	return score;	}
  	
  } 
  int wordsearch(int d) {
  int score = 0;
  string guess;  
  
  cout<<"********************** "<<endl;
  cout<<"* WORD SEARCH GAME   * "<<endl;
  cout<<"********************** "<<endl; 
   
  if(d==1)	{
    char grid[5][5] = {
        {'P','S','D','E','Q'},
        {'G','T','S','A','U'},
        {'T','A','G','M','E'},
        {'G','C','M','A','U'},
        {'P','K','A','E','E'} };

    string words[9] = {"STACK","stack","Stack", "QUEUE", "queue", "Queue", "GAME", "game", "Game"};
    string guess;

    for(int i=0;i<5;i++)
    {for(int j=0;j<5;j++)
        {cout << grid[i][j] << " ";
        }cout << endl;
    }

    cout << "\nFind 3 hidden words!\n";
    for(int attempt=0;attempt<3;attempt++)
    {
	cout << "Enter a word: ";
    cin >> guess;

    bool found = false;

    for(int i=0;i<9;i++)
    {
        if(guess == words[i])
        {
            found = true;
        }
    }

    if(found) {
	
        cout << "Correct! Word found.\n";
		score++;
		}
    else
       {
		 cout << "Word not found.\n";
		 }
} 
  cout<<"GAME OVER!\n"; 
  score = (score * 10 ) / 3;
 return score;  }
  else if(d==2){  char grid[10][10] = {
        {'A','L','G','O','R','I','T','H','M','S'},
        {'M','E','T','A','M','N','R','P','H','T'},
        {'T','A','G','R','E','N','K','A','S','A'},
        {'G','C','M','C','U','O','M','E','W','T'},
        {'P','K','A','H','I','V','E','P','G','I'},
        {'A','Q','O','A','I','A','X','Z','A','S'},
		{'S','Q','M','E','U','T','T','E','E','T'},
		{'R','W','A','O','Y','I','P','R','O','I'},
		{'K','T','P','L','T','O','S','O','O','C'},
		{'S','Z','X','O','O','N','D','C','X','N'},
    };

    string words[9] = {"STATISTIC","statistic","Statistic", "INNOVATION", "innovation", "Innovation", "ALGORITHM", "algorithm", "Algorithm"};
    string guess;

    for(int i=0;i<10;i++)
    {for(int j=0;j<10;j++)
        {cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nFind 3 hidden words!\n";
    for(int attempt=0;attempt<3;attempt++)
    {
	cout << "Enter a word: ";
    cin >> guess;

    bool found = false;

    for(int i=0;i<9;i++)
    {
        if(guess == words[i])
        {
            found = true;
        }
    }

    if(found) {
	
        cout << "Correct! Word found.\n";
		score++;
		}
    else
       {cout << "Word not found.\n";
		 }
} 
  cout<<"GAME OVER!\n";
  score = (score * 10 ) / 3;
 return score;}  
  else if(d==3){
  	char grid[13][13] = {
        {'A','S','D','E','Q','S','M','P','O','S','X','O','P'},
        {'M','E','T','A','M','O','R','P','H','O','S','I','S'},
        {'T','A','G','R','E','U','K','A','S','G','S','M','Q'},
        {'G','C','M','C','U','N','M','E','W','S','F','K','L'},
        {'P','K','A','H','A','J','O','P','G','F','D','S','C'},
        {'A','Q','O','A','I','S','X','Z','A','Q','H','V','Y'},
		{'S','Q','M','E','U','G','T','E','E','P','Q','D','W'},
		{'R','W','F','O','Y','T','P','R','O','L','M','P','Q'},
		{'K','L','P','L','T','O','S','O','O','W','J','W','X'},
		{'S','Z','X','O','O','M','D','C','X','N','B','L','H'},
		{'I','O','K','G','B','N','I','B','P','A','O','G','K'},
		{'M','U','C','Y','P','I','W','S','Z','T','S','M','L'},
		{'N','B','V','C','I','Z','L','C','S','Q','N','L','Y'}
    };

    string words[9] = {"METAMORPHOSIS","metamorphosis","Metamorphosis", "ARCHAEOLOGY", "archaeology", "Archaeology", "ASTRONOMY", "astronomy", "Astronomy"};
   
    for(int i=0;i<13;i++)
    {for(int j=0;j<13;j++)
        { cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nFind 3 hidden words!\n";
    for(int attempt=0;attempt<3;attempt++)
    {
	cout << "Enter a word: ";
    cin >> guess;

    bool found = false;

    for(int i=0;i<9;i++)
    {
        if(guess == words[i])
        {
            found = true;
        }
    }

    if(found) {
	
        cout << "Correct! Word found.\n";
		score++;
		}
    else
       {
		 cout << "Word not found.\n";
		 }
}  
  cout<<"GAME OVER!\n";
   score = (score * 10 ) / 3;
 return score; } 
  else { cout<<"invalid difficulty\n";
    score = 0;
	return score;	}
   }  
  int sudoku(int d) { 
  int score=0;
  int moves = 0; 
  cout<<"********************** "<<endl;
  cout<<"*       SUDOKO       * "<<endl;
  cout<<"********************** "<<endl; 
  if(d == 1)  
    {
        int board[3][3] =
        {
            {0,1,2},
            {0,3,0},
            {1,0,3}
        };

        int row, col, num;

        while(true)
        {
            // Display
            cout << "\n--- 3x3 SUDOKU ---\n";
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                    if(board[i][j]==0) cout<<". ";
                    else cout<<board[i][j]<<" ";
                }
                cout<<endl;
            }

            // Check complete
            bool complete = true;
            for(int i=0;i<3;i++)
                for(int j=0;j<3;j++)
                    if(board[i][j]==0)
                        complete = false;

            if(complete) break;

            // Input
            cout<<"\nRow (1-3): ";
            cin>>row;
            cout<<"Col (1-3): ";
            cin>>col;
            cout<<"Num (1-3): ";
            cin>>num;

            row--; col--;

            // Validation
            if(row<0 || row>2 || col<0 || col>2)
            {
                cout<<"Invalid position!\n";
                continue;
            }

            if(num<1 || num>3)
            {
                cout<<"Invalid number!\n";
                continue;
            }

            if(board[row][col] != 0)
            {
                cout<<"Cell already filled!\n";
                continue;
            }

            bool valid = true;
    
            // Row & Column check
            for(int i=0;i<3;i++)
            {
                if(board[row][i]==num) valid = false;
                if(board[i][col]==num) valid = false;
                
            }

            if(valid)
            {
                board[row][col] = num;
                cout<<"Placed!\n";
            }
            else
            {
                cout<<"Invalid move!\n"; 
                moves++;
            }
        }

        cout << "\n3x3 Sudoku Completed!\n"; 
        score = 10 - moves;
        if(score < 0) score = 0; 
        return score;
    }

    // ---------- 4x4 GAME ----------
    else if(d == 2)
    {
        int board[4][4] =
        {
            {1,0,3,0},
            {0,0,2,1},
            {0,1,0,2},
            {2,4,0,0}
        };

        int row, col, num;

        while(true)
        {
            cout << "\n--- 4x4 SUDOKU ---\n";
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<4;j++)
                {
                    if(board[i][j]==0) cout<<". ";
                    else cout<<board[i][j]<<" ";

                    if(j==1) cout<<"| ";
                }
                cout<<endl;
                if(i==1) cout<<"-----------\n";
            }

            bool complete = true;
            for(int i=0;i<4;i++)
                for(int j=0;j<4;j++)
                    if(board[i][j]==0)
                        complete = false;

            if(complete) break;

            cout<<"\nRow (1-4): ";
            cin>>row;
            cout<<"Col (1-4): ";
            cin>>col;
            cout<<"Num (1-4): ";
            cin>>num;

            row--; col--;

            if(row<0 || row>3 || col<0 || col>3)
            {
                cout<<"Invalid position!\n";
                continue;
            }

            if(num<1 || num>4)
            {
                cout<<"Invalid number!\n";
                continue;
            }

            if(board[row][col] != 0)
            {
                cout<<"Cell already filled!\n";
                continue;
            }

            bool valid = true;

            // Row & Column
            for(int i=0;i<4;i++)
            {
                if(board[row][i]==num) valid = false;
                if(board[i][col]==num) valid = false;
            }

            int sr = row - row%2;
            int sc = col - col%2;

            for(int i=0;i<2;i++)
                for(int j=0;j<2;j++)
                    if(board[sr+i][sc+j]==num)
                        valid = false;

            if(valid)
            {
                board[row][col] = num;
                cout<<"Placed!\n";
            }
            else
            {
                cout<<"Invalid move!\n"; 
                moves++;
            }
        }

        cout << "\n4x4 Sudoku Completed!\n"; 
        
    }

    else
    {
        cout << "Invalid difficulty!\n";
    }
    cout << "\nSudoku Completed!\n";
    
      score = 10 - moves;
     if(score < 0) score = 0; 
     return score;
      }
  int tictactoe(int d){ 
     int score;
  cout<<"********************** "<<endl;
  cout<<"*     TIC TAC TOE    * "<<endl;
  cout<<"********************** "<<endl; 
    char board[3][3] = 
    {
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
    };

    int row, col;

    //DISPLAY
    auto printboard = [&](void){
        cout<<endl;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cout<<" "<<board[i][j]<<" ";
                if(j<2) cout<<"|";
            }
            if(i<2) cout<<"\n---|---|---\n";
        }
        cout<<endl;
    };

    //CHECK WIN
    auto checkWin = [&](char player){
        for(int i=0;i<3;i++)
            if(board[i][0]==player && board[i][1]==player && board[i][2]==player) return true;

        for(int i=0;i<3;i++)
            if(board[0][i]==player && board[1][i]==player && board[2][i]==player) return true;

        if(board[0][0]==player && board[1][1]==player && board[2][2]==player) return true;
        if(board[0][2]==player && board[1][1]==player && board[2][0]==player) return true;

        return false;
    };

    //CHECK DRAW
    auto checkDraw = [&](){
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(board[i][j]==' ')
                    return false;
        return true;
    };

    // COMPUTER MOVE
    auto computerMove = [&](){

        // Win if possible
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(board[i][j]==' '){
                    board[i][j]='O';
                    if(checkWin('O')) return;
                    board[i][j]=' ';
                }

        // Block player
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(board[i][j]==' '){
                    board[i][j]='X';
                    if(checkWin('X')){
                        board[i][j]='O';
                        return;
                    }
                    board[i][j]=' ';
                }

        // Center
        if(board[1][1]==' '){
            board[1][1]='O';
            return;
        }

        // Corners
        for(int i=0;i<3;i+=2)
            for(int j=0;j<3;j+=2)
                if(board[i][j]==' '){
                    board[i][j]='O';
                    return;
                }

        // Any remaining
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(board[i][j]==' '){
                    board[i][j]='O';
                    return;
                }
    };

    while(true)
    {
        printboard();

        cout<<"Enter row(1-3): ";
        cin>>row;
        cout<<"Enter column(1-3): ";
        cin>>col;

        row--; col--;

        if(row<0 || row>2 || col<0 || col>2 || board[row][col]!=' ')
        {
            cout<<"Invalid move! Try again.\n";
            continue;
        }

        board[row][col]='X';

        if(checkWin('X')){
            printboard();
            cout<<"Congrats! You won \n";
            score = 10;
            break;
        }

        if(checkDraw()){
            printboard();
            cout<<"It's a draw!\n";
            score=5;
            break;
        }

        computerMove();

        if(checkWin('O')){
            printboard();
            cout<<"You lost \n";
            score=0;
            break;
        }

        if(checkDraw()){
            printboard();
            cout<<"It's a draw!\n"; 
            score=5;
            break;
        }
    }
   
    cout << "Your score for this game: " << score << endl;

    return score;   
   }  
   int cardgame(int d){
    int size, perRow; 
  cout<<"*********************** "<<endl;
  cout<<"* Matching pairs game * "<<endl;
  cout<<"***********************"<<endl; 

    if(d == 1) { 
        size = 9; 
        perRow = 3; 
    }
    else if(d == 2) { 
        size = 16; 
        perRow = 4; 
    }
    else {
        cout << "Invalid difficulty!\n";
        return 0;
    }

    int board[16];
    bool revealed[16] = {false};

    // Initialize
    if(d == 1)
    {
        int temp[9] = {1,1,2,2,3,3,4,4,0};
        for(int i=0; i<9; i++) board[i] = temp[i];
    }
    else
    {
        int temp[16] = {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8};
        for(int i=0; i<16; i++) board[i] = temp[i];
    }

    // Shuffle
    srand(time(0));
    for(int i=0; i<size; i++)
    {
        int j = rand() % size;
        swap(board[i], board[j]);
    }

    auto display = [&]()
    {
        cout << "\n--- BOARD ---\n";
        for(int i=0; i<size; i++)
        {
            if(revealed[i]) cout << "[" << board[i] << "] ";
            else cout << "[*] ";
            if((i+1) % perRow == 0) cout << endl;
        }
        cout << "-------------\n";
    };

    auto allMatched = [&]()
    {
        if(d==1)
        {
            int count = 0;
            for(int i=0; i<size; i++) if(revealed[i]) count++;
            return (count >= 8);
        }
        else
        {
            for(int i=0; i<size; i++)
                if(!revealed[i]) return false;
            return true;
        }
    };

    int c1, c2;
    while(true)
    {
        display();
        cout << "Enter 1st index (0-" << size-1 << "): ";
        cin >> c1;
        cout << "Enter 2nd index (0-" << size-1 << "): ";
        cin >> c2;

        if(c1<0 || c1>=size || c2<0 || c2>=size || c1==c2 || revealed[c1] || revealed[c2])
        {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        revealed[c1] = true;
        revealed[c2] = true;
        display();

        if(board[c1] == board[c2])
            cout << "Match found!\n";
        else
        {
            cout << "Not a match.\n";
            revealed[c1] = false;
            revealed[c2] = false;
        }

        if(allMatched())
        {
            cout << "\nCongratulations! You found all pairs!\n";
            break;
        }
    }

    // Score return
    int score = (d == 1) ? 8: 10;
    cout << "Your score for this game: " << score << endl;
    return score;
}
  

   int main()
    { 
    cout<<"                        *************************************************************************************\n";
    cout<<"                                                    WELCOME TO MINI GAME ARCADE!\n";
    cout<<"                        *************************************************************************************\n";
    cout << "Enter your name : ";
    string name;
    cin >> name;

    int choice;
    int difficulty = 1;
    int score = 0;
    int a = 0;
    bool played[6][10] = {false};

    cout << "\nHello " << name << "! Let's start playing.\n";

    // First game choice from user
    cout << "\nWhich game would you like to play?\n";
    cout << "1. Word Scramble\n";
    cout << "2. Word Search\n";
    cout << "3. Sudoku\n";
    cout << "4. Tic Tac Toe\n";
    cout << "5. Matching pair\n"; 
    do {
    cout << "Enter your choice(1-5): ";
    cin >> choice; 
    if(choice < 1 || choice >5) cout<<"Invalid choice!\n"; }while(choice < 1 || choice >5);

    do {
        if(choice == 1)
            score = wordscramble(difficulty);
        else if(choice == 2)
            score = wordsearch(difficulty);
        else if(choice == 3)
            score = sudoku(difficulty);
        else if(choice == 4)
            score = tictactoe(difficulty);
        else if(choice == 5)
            score = cardgame(difficulty); 
            
        if(score >= 0) {
            played[choice][difficulty] = true;
            totalScore += score;    
            gamesPlayed++;  }
            
        totalScore += score;    
        gamesPlayed++;         
       // next game suggestion acc to USER performance
        if (score > bestPercent) {
            bestPercent = score;
            if(choice == 1) bestGame = "Word Scramble";
            else if(choice == 2) bestGame = "Word Search";
            else if(choice == 3) bestGame = "Sudoku";
            else if(choice == 4) bestGame = "Tic Tac Toe";
            else if(choice == 5) bestGame = "Card Game";
        }

        a++;
          int lastGame = choice;
          int lastScore = score;
            
           if(lastScore >= 8) {
		    difficulty++; 
			cout << "Great job! Increasing difficulty level for next game.\n"; } 
           else if(lastScore < 4){
		    difficulty--;
		    cout << "Keep practicing! Lowering difficulty level  for next game.\n"; } 
		   else {
            cout << "Good effort! Difficulty level stays the same.\n";}

           if(difficulty < 1) difficulty = 1;
           if(difficulty > 3) difficulty = 3; 
            
        choice = randomgame(difficulty,played); 
        
    } while(a < 5); 
    //PERFORMANCE REPORT 
    if(a==5) {
     showReport(); }
    cout << "\nThanks for playing, " << name << "!\n";
    return 0;
	}
