#include<ncurses.h>
#include<stdio.h>


struct block
{
	int x,y;
}typedef block;


int check(char a[3][3],int i,int j)
{
	if(i==j)
	{
		if(a[1][1]==a[2][2] && a[2][2]==a[0][0] && a[0][0]==a[1][1])
			return 1;

		else if(  (a[i][1]==a[i][2] && a[i][2]==a[i][0] && a[i][0]==a[1][1])  || (a[1][j]==a[2][j] && a[2][j]==a[0][j] && a[0][j]==a[1][j]) )
			return 1;

		else if(a[1][1]==a[0][2] && a[0][2]==a[2][0] && a[2][0]==a[1][1])
			return 1;

		else return 0;
	}
	else
	{
		if(  (a[i][1]==a[i][2] && a[i][2]==a[i][0] && a[i][0]==a[i][1])  || (a[1][j]==a[2][j] && a[2][j]==a[0][j] && a[0][j]==a[1][j]) )
			return 1;

		else if(a[1][1]==a[0][2] && a[0][2]==a[2][0] && a[2][0]==a[1][1])
			return 1;

		else return 0;

	}
}




int main()
{

	

 initscr();
 noecho();


 start_color();
		init_pair(1,COLOR_RED,COLOR_BLACK);
		init_pair(2,COLOR_GREEN,COLOR_BLACK);
		init_pair(3,COLOR_RED,COLOR_YELLOW);
		init_pair(4,COLOR_YELLOW,COLOR_BLACK);
		init_pair(5,COLOR_BLUE,COLOR_BLACK);
		init_pair(6,COLOR_GREEN,COLOR_BLUE);
		init_pair(8,COLOR_GREEN,COLOR_WHITE);
		init_pair(7,COLOR_RED,COLOR_WHITE);
		init_pair(9,COLOR_WHITE,COLOR_BLACK);


 int l,
	 m,
	 t=0,
	 pos;

 getmaxyx(stdscr,m,l);

 int ltemp=l/2,
	 mtemp=m/2;

	block arr[10];

	arr[1].x=0,		
	arr[1].y=0,

	arr[2].x=0,
	arr[2].y=1,

	arr[3].x=0,
	arr[3].y=2,

	arr[4].x=1,
	arr[4].y=0,

	arr[5].x=1,
	arr[5].y=1,

	arr[6].x=1,
	arr[6].y=2,

	arr[7].x=2,
	arr[7].y=0,

	arr[8].x=2,
	arr[8].y=1,

	arr[9].x=2,
	arr[9].y=2;

	char a[3][3],
		 c='1',
		 sym;


	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			a[i][j]=c++;


		attron(COLOR_PAIR(2));
		mvprintw(mtemp-12,ltemp-4," TIC TAC TOE");
		attron(COLOR_PAIR(7));
		mvprintw(mtemp-10,ltemp-3,"Player 1: X ");
		attron(COLOR_PAIR(8));
		mvprintw(mtemp-10+1,ltemp-3,"Player 2: O ");

		
		for(int i=0;i<3;i++)
		{
			mtemp=(m/2)+i+i+i;
			for(int j=0;j<3;j++)
			{

				if(a[i][j]=='X')
				attron(COLOR_PAIR(1)),	
				mvprintw(mtemp,ltemp+j+j+j+j,"%c",a[i][j]);

				else if(a[i][j]=='O')
				attron(COLOR_PAIR(2)),	
				mvprintw(mtemp,ltemp+j+j+j+j,"%c",a[i][j]);

				else
				{

				attron(COLOR_PAIR(9)),	
				mvprintw(mtemp,ltemp+j+j+j+j,"%c",a[i][j]);

				}


			}
		}



		for(int i=1;i<10 && !t;i++)
		{
			if(i%2)
			{
				sym='X';
				attron(COLOR_PAIR(1));
				mvprintw(mtemp+5,ltemp-4,"Turn of PLAYER : 1 -- X ");

			}
			else
			{

				sym='O',
				attron(COLOR_PAIR(2)),	

			 	mvprintw(mtemp+5,ltemp-4,"Turn of PLAYER : 2 -- O ");
			}

			attron(COLOR_PAIR(4)),
			mvprintw(mtemp+7,ltemp-10,"Enter the Position You want");
			scanw("%d",&pos);

			while(a[arr[pos].x][arr[pos].y]=='X'  ||  a[arr[pos].x][arr[pos].y]=='O')
			{
				attron(COLOR_PAIR(1));
				mvprintw(mtemp+7,ltemp-10,"plz enter a valid Position:");
				scanw("%d",&pos);
			}

			//mvprintw(mtemp+8,ltemp-10," ");

			a[arr[pos].x][arr[pos].y]=sym;

			t=check(&a[0],arr[pos].x,arr[pos].y);

			

			for(int i=0;i<3;i++)
		{
			mtemp=(m/2)+i+i+i;
			for(int j=0;j<3;j++)
			{

				if(a[i][j]=='X')
				attron(COLOR_PAIR(1)),
				attron(A_BOLD),	
				mvprintw(mtemp,ltemp+j+j+j+j,"%c",a[i][j]);

				else if(a[i][j]=='O')
				attron(COLOR_PAIR(2)),
				attron(A_BOLD),
				mvprintw(mtemp,ltemp+j+j+j+j,"%c",a[i][j]);

				else
				{

				attron(COLOR_PAIR(9)),	
				mvprintw(mtemp,ltemp+j+j+j+j,"%c",a[i][j]);

				}


			}
		}


		}



		attron(COLOR_PAIR(6));
			if(t)
			{

				if(sym=='O'){

					refresh();
					mvprintw(mtemp-10,ltemp-12,"Woo Hoo! PLAYER :2 Is The WINNER :)");
					
				}
				else
				{
					refresh();
					mvprintw(mtemp-10,ltemp-12,"Woo Hoo! PLAYER :1 Is The WINNER :)");
				}

				mvprintw(mtemp-8,ltemp-3,"THANK YOU:)");
			}

		else
		mvprintw(mtemp-10,ltemp-3," GAME OVER "),
		mvprintw(mtemp-8,ltemp-3,"THANK YOU:)");


getch();

endwin();





}