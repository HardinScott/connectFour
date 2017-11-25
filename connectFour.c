#include <stdio.h>
#include <stdlib.h>

int main(){
    int board[6][7]= {0};
    int playerTurn = 1;
    int usrInput;

    void showBoard(){
	printf("1234567\n");
	for(int i = 0; i < 6; i++){
	    for(int j = 0; j < 7; j++){
		printf("%d", board[i][j]);
	    }
	    printf("\n");
	}
    }

    int winCondition(){
	int counter = 0;
	for(int i = 5; i >= 0; i--){
	    for(int j = 0; j < 7; j++){
		if(board[i][j] != 0){
		    for(int k = 0; k < 4; k++){
			if(board[i][j] == board[i - k][j]){
			    counter++;
			}
			else{
			    counter = 0;
			    break;
			}
		    }
		    if(counter == 4){
			return 1;
		    }
		    for(int k = 0; k < 4; k++){
			if(board[i][j] == board[i][j + k]){
			    counter++;
			}
			else{
			    counter = 0;
			    break;
			}
		    }
		    if(counter == 4){
			return 1;
		    }
		    for(int k = 0; k < 4; k++){
			if(board[i][j] == board[i - k][j - k]){
			    counter++;
			}
			else{
			    counter = 0;
			    break;
			}
		    }
		    if(counter == 4){
			return 1;
		    }
		    for(int k = 0; k < 4; k++){
			if(board[i][j] == board[i - k][j + k]){
			    counter++;
			}
			else{
			    counter = 0;
			    break;
			}
		    }
		    if(counter == 4){
			return 1;
		    }
		}
	    }
	}
    }
    
    void changePlayer(){
	if(playerTurn == 1){
	    playerTurn++;
	}
	else{
	    playerTurn--;
	}
    }

    void turn(){
	printf("Player %d, select a column to place your token: ", playerTurn);
	LOOP:scanf("%d", &usrInput);
	usrInput--;
	if(usrInput < 0 || usrInput > 6){
	    printf("Please enter a number between 1 and 7: ");
	    goto LOOP;
	}
	if(board[0][usrInput] != 0){
	    printf("Column Full, please select another: ");
	    goto LOOP;
	}
	for(int k = 0; k < 6; k++){
	    if(board[k][usrInput] != 0){
		board[k - 1][usrInput] = playerTurn;
		break;
	    }
	    else{
		if(k == 5){
		    board[k][usrInput] = playerTurn;
		}
	    }
	}
	changePlayer();
    }
    
    while(winCondition() != 1){
	system("clear");
	showBoard();
	turn();
    }
    system("clear");
    showBoard();
    changePlayer();
    printf("Player %d wins.\n", playerTurn);
}
