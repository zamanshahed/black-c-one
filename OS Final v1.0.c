#include<stdio.h>
#include<windows.h>
#include <time.h>


void wlcm(); /** Welcome **/
void menu(); /** MENU **/
void systemready(); /**Getting System Ready**/
void stopwatch();/**StopWatch**/
void home();/**Home**/
void tm();/**Time show**/
void RefrshTime();/**refreshTimeFunction**/
void contacts();/**ContactsDatabase**/
void game();/**Game**/
void dateview();/**ViewDates**/
void piano(int d);/**Piano**/
void countdowntimer();/**count down timer**/



int main()
{
    wlcm();

    system("CLS");
    systemready();

    system("CLS");
    home();

    system("CLS");
    menu();

}


/******************
*  WELCOME Screen *
******************/
void wlcm()
{
    system("COLOR 4E");
    int i, j;
    char s[126]={"\n\n\n\t***************\n\t*  WELCOME TO *\n\t* BLACK-C.one *\n\t***************\n\n\n\n\n  The TINY virtual Mobile view OS!\n"};
    for(i=0;i<126;i++)
    {
        printf("%C", s[i]);
        j=i*15;
        Beep(j, 75);

        system("COLOR 46");

        Sleep(75);
        system("COLOR 4B");
        Sleep(75);
    }

}


/***********************
* Getting SYSTEM Ready *
***********************/
void systemready()
{
    Sleep(500);
    system("CLS");
    char s[53]={"Please  wait...We are Getting System Ready for you:\n\n"};
    int i;
    for(i=0;i<53; i++)
    {
        system("COLOR 3B");
        printf("%c", s[i]);
        Sleep(70);

    }

    for(i=0;i<101;i++)
    {
        printf("\n\n\n\n\n    LOADING  %d percent", i);
        system("COLOR 36");
        Sleep(10);
        system("COLOR 3B");
        system("CLS");

    }


    system("CLS");
    system("COLOR 4F");

    printf("\n\n\n\n\n\tSystem is ready to work..!");

    Sleep(1500);

}

/*********
*  Menu  *
*********/
void menu()
{
    char choise;
    printf("......  Menu  ......\n\n");
    printf("\t1.Stop Watch\n"); /**item 01**/
    printf("\t2.Clock\n");/**Clock**/
    printf("\t3.Math Game!\n");/**Game**/
    printf("\t4.Beep Beep Piano!\n");
    printf("\t5.CountDown timer!\n");

    printf("\th.Home\n");/**Home**/
    printf("\tx.Exit\n");/**ShutDown**/

    choise=getche();
    system("CLS");
    switch(choise)
    {

    case '1':
    {
        system("COLOR 3B");
        stopwatch();
        break;
    }


    case 'x':
        {

            system("COLOR 3B");
            printf("\n\tShutting Down...!\n\n\n\n\n");
            char s[50]={"    ________________________________"};
            int i;
            for(i=0;i<50;i++)
            {
            printf("%c", s[i]);
            Sleep(90);
            }
            system("CLS");
            exit(0);


        }

        case'h':
        {

            return home();
            break;
        }

        case '2':
            {
                tm();
                break;
            }

        case '3':
            {
                game();
                break;
            }
        case '4':
            {

                system("CLS");
                system("COLOR 3B");

                int f;
                printf("Enter the duration(milliseconds<5000) of tones:\n\n");
                scanf("%d", &f);
                piano(f);
                break;
            }
        case '5':
            {
                 countdowntimer();
                 break;
            }

    default:
        {

            system("COLOR 4F");
            printf("\n\tInvalid  Enter!!\n\n\n\tWatch CAREFULLY and try again...\n\n\n");
            Sleep(2000);

            system("CLS");
            menu();
        }



    }

}




/************
* STOPWATCH *
************/

void stopwatch()
{
    int j, m=0, s=0, h=0,i, ms=0 ;

   for(h=0; h<11; h++)
   {
       for(m=0; m<60; m++)
       {
           for(s=0; s<60; s++)
           {
               char c;
               printf("      BLACK-C   Stopwatch\n\t     V1.0\n\n\n\tH:%d  M:%d  S:%d\n\n\n\n\nInstructions:\nPress any key to exit Stopwatch\n\nPress p to pause\n\n", h, m, s);
               Sleep(1000);

               if (kbhit())
               {
                   if('p'==getch())
                   {
                       system("pause");
                   }else
                   {
                        system("CLS");
                        menu();
                    }
               }
               system("CLS");
           }
       }
   }
}

/*******
* Home *
*******/
void home()
{

    system("CLS");
    system("COLOR 3B");
    printf("N:x\t\t     B:80\n\n\n\n\n\n\tNo sim!\n\n\n\n\n\n");


    dateview();



    printf("\n\n\n\nMenu(m)\t      Contacts(c)");



    char choise;
    choise=getche();
    system("CLS");
    switch(choise)
    {
    case 'm':
        {
            menu();
            break;
        }


    case 'c':
        {
            contacts();
            break;
        }

            default:
        {
            system("CLS");
            home();
        }
    }



    Sleep(500);
    system("CLS");
    home();
}

/*****
*TIME*
*****/
void tm()
{

    struct tm *local, *gm;
    time_t t;

    t = time(NULL);
    local=localtime(&t);
    printf("  BLACK.C   Clock\n\tv1.0\n\n\n\n  Time==> %d: %d: %d\n\n\n\n\n\n\nPress any key to exit Clock\n\n", local->tm_hour, local->tm_min, local->tm_sec);

    if(kbhit())
    {

        home();
    }else
    {
        RefrshTime();
    }



}




/***********
* Contacts *
***********/

void contacts()
{
            char b;
            printf("Sorry No contacts found!\n\n\n\n\n\n\nPress h to return HOME\n\n");
            b=getche();
            system("CLS");
            switch(b)
            {
            case 'h':
                {
                    home();
                    break;
                }
            default:
                 {

            system("COLOR 4F");
            printf("\n\tInvalid  Enter!!\n\n\n\tWatch CAREFULLY and try again...\n\n\n");
            Sleep(2000);

            system("CLS");
            contacts();
                 }

            }
}


/**Refresh the time of clock**/
void RefrshTime()
{
    Sleep(940);
    system("CLS");
    tm();
}

/************
* Math Game *
************/
void game()
{
    int a[66]={5, 6, 7, 8, 9, 0, 4, 3, 2, 1, 5, 6, 7, 8, 9, 0, 4, 3, 2, 1, 5, 6, 7, 8, 9, 0, 4, 3, 2, 1, 5, 6, 7, 8, 9, 0, 4, 3, 2, 1,5, 6, 7, 8, 9, 0, 4, 3, 2, 1,5, 6, 7, 8, 9, 0, 4, 3, 2, 1, 0, 2};
    int b[66]={5, 6, 7, 8, 9, 0, 4, 3, 2, 1, 5, 6, 7, 8, 9, 0, 4, 3, 2, 1, 5, 6, 7, 8, 9, 0, 4, 3, 2, 1, 5, 6, 7, 8, 9, 0, 4, 3, 2, 1,5, 6, 7, 8, 9, 0, 4, 3, 2, 1,5, 6, 7, 8, 9, 0, 4, 3, 2, 1, 0, 2};
    int i, j, r, c;

    struct tm *local, *gm;
    time_t t;

    t = time(NULL);
    local=localtime(&t);


    i=local->tm_sec;
    j=i+1;
    r=a[i]+a[j];
    printf("%d + %d = ?\n\n", a[i], a[j]);

    scanf("%d", &c);
    printf("\n\n\n\n\n\n\n\n\n\nTime: %d: %d", local->tm_hour, local->tm_min, local->tm_sec);

    if(c==r)
    {

            system("CLS");

            printf("\n\n\n\t   Great..!!\n\n\n\n\n\n\n");
            Sleep(1000);
            system("CLS");

            game();
    }else
    {
        printf("Game Over!\n\n");
        return 0;
    }
}


/**Show System date on home screen**/
void dateview()
{

    struct tm *local, *gm;
    time_t t;

    t = time(NULL);
    local=localtime(&t);
    printf(" Date(D/M/Y): %d/%d/%d\n", local->tm_mday, local->tm_mon+1, local->tm_year+1900);

    }


/********
* Piano *
********/

void piano(int d)
{


    if(d<5000)
    {
        system("CLS");
        printf("\n\tBEEP  BEEP\n\t  Piano\n\t  v1.0\n\n\n\ninstructions:\nUse numbers (1,2,3,4,5,6,7,8,9 and 0) to perform piano sounds.\n\n\nPress any other key to exit.\n\n\t\tKey-->");
    char choise;
    choise=getche();



    switch(choise)
    {
        case '1':
        {
            system("COLOR 1E");
            Beep(200, d);

            piano(d);
        }
        case '2':
        {
            system("COLOR 2E");
            Beep(400, d);

            piano(d);
        }
        case '3':
        {
            system("COLOR 3E");
            Beep(600, d);

            piano(d);
        }
        case '4':
        {
            system("COLOR 4E");
            Beep(800, d);

            piano(d);
        }
        case '5':
        {
            system("COLOR 5E");
            Beep(1000, d);

            piano(d);
        }
        case '6':
        {
            system("COLOR AE");
            Beep(1200, d);

            piano(d);
        }
        case '7':
        {
            system("COLOR 6E");
            Beep(1400, d);

            piano(d);
        }
        case '8':
        {
            system("COLOR 7E");
            Beep(1600, d);

            piano(d);
        }
        case '9':
        {
            system("COLOR 8E");
            Beep(1800, d);

            piano(d);
        }
        case '0':
        {
            system("COLOR 9E");
            Beep(2000, d);

            piano(d);
        }
        default:
        {

            system("CLS");
            system("COLOR 4F");
            printf("\n\n\n\nBeep Beep Piano closed...\n\n\n");
            Sleep(1200);
            home();

        }
    }

    }
}



/******************
* Countdown Timer *
******************/
void countdowntimer()
{
    int h=0, m=0, s=0, i, j, k;

    printf("Enter Hour Minutes and Seconds:");
    scanf("%d %d %d", &k, &j, &i);

    for(h=k; h>=0; h--)
    {
        for(m=j; m>=0; m--)
        {
            for(s=i; s>=0; s--)
            {
                system("CLS");
                printf("H:%d  M:%d  S:%d", h, m, s);
                Sleep(470);
                system("COLOR 3B");
                Sleep(470);
                system("COLOR 2B");
                if(s==0)
                {
                    printf("Ended..!\n\n\n");
                    Sleep(1000);
                    system("CLS");
                    menu();
                }
                else
                {
                    continue;
                }
                }
                system("CLS");

            }
        }
}




































































































