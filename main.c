#include <stdio.h>
#include <stdlib.h>
#include<string.h>


int i,j,main_exit;
void display();
void new_entry();
void erase();
void edit();
void close();
void menu();
struct{
    char name[30];
    char gender[15];
    char mail[30];
    char hostelblock[20];
    char location[15];
    char phone[15];
    char Roomno[7];
    char rollno[20];
}add,upd,check,rem;

int main()
{

    menu();
    return 0;
}
void menu(){
         int memb;
         printf("\n----------------------------------------------------------------------------------------------------------\n");
         printf("\t\t\t\t\t\WELCOME TO ALLSAFE HOSTEL\n");
         printf("-----------------------------------------------------------------------------------------------------------\n");
         printf("\n\t\t1.Administrator\n\t\t2.User\n");
         scanf("%d",&memb);
         if(memb == 1){
             printf("\n1>>New Entry\n2>>Display\n3>>Remove room\n4>>Edit\n5>>Close\n");
             int choice;
             scanf("%d",&choice);
             switch(choice){
                 case 1:new_entry();
                 break;
                 case 2:display();
                 break;
                 case 3:erase();
                 break;
                 case 4: edit();
                 break;
                 case 5:close();
                 break;
        }
    }

       else if(memb == 2){
          printf("\n1>>Display\n2>>New Entry\n");
          int choice;
          scanf("%d", &choice);
          switch(choice){
              case 1:display();
              break;
              case 2:new_entry();
              break;

        }
    }

      else{
          printf("Invalid Entry");
    }
}
// to view occupants in the room
void display(){
	system("CLS");
    FILE *view;
    view=fopen("record.txt","r");
    int test=0;


    printf("\nROLL NO.\tNAME\t\tPHONE\n");
    while(fscanf(view, "%s %s %s %s %s %s %s", add.gender, add.hostelblock, add.name, add.mail,add.phone, add.rollno, add.Roomno)!=EOF){
            printf("\n%s\t\t%s\t\t%s\n",add.rollno,add.name,add.phone);
            test++;
     }
     fclose(view);
     if(test==0){
        printf("\nNo Records");
     }
     view_invalid_list:
     printf("Enter 1 to go to main menu and 0 to exit>>");
     scanf("%d", &main_exit);
     if (main_exit==1){
         menu();
     }
     else if(main == 0)
        close();
     else{
        printf("Invalid Entry");
        goto view_invalid_list;}
}

void new_entry(){
    system("CLS");
    int choice;
    FILE *ptr,*hostel;

    ptr=fopen("record.txt","a+");
    roll_no:
    printf("\n------------------------ADD STUDENT'\S DATA---------------");
    printf("\nEnter Roll number>>");
    scanf("%s", check.rollno);
    while(fscanf(ptr,"%s %s %s %s %s %s %s\n", add.gender, add.location, add.name, add.mail, add.phone, add.rollno, add.Roomno)!= EOF){
        if(strcmp(check.rollno, add.rollno)==0){
            printf("\nStudent roll number is already in use");
            goto roll_no;}
    }
    strcpy(add.rollno,check.rollno);
    printf("\nEnter your name>>");
    scanf("%s", add.name);
    printf("\nEnter your location>>");
    scanf("%s",add.location);
    printf("\nEnter your gender>>");
    scanf("%s",add.gender);
    printf("\nEnter your mail address>>");
    scanf("%s",add.mail);
    printf("\nEnter your phone number>>");
    scanf("%s",add.phone);
    printf("\nEnter your room number>>");
    scanf("%s",add.Roomno);
    printf("\nEnter Block number you want BH-1, BH-2, BH-3>>");
    scanf("%s",add.hostelblock);
        fprintf(ptr,"%s \n %s \n %s \n%s \n%s \n%s \n%s\n", add.gender, add.location, add.name, add.mail, add.phone, add.rollno, add.Roomno);

    if(strcmp(add.hostelblock,"BH-1")==0){
        hostel = fopen("BH-1.txt", "+a");
        fprintf(hostel, "%s\n", add.hostelblock);
        fclose(hostel);
    }
    else if(strcmp(add.hostelblock, "BH-2")==0){
        hostel = fopen("BH-2.txt", "+a");
        fprintf(hostel, "%s\n", add.hostelblock);
        fclose(hostel);
    }
    else if(strcmp(add.hostelblock, "BH-3")==0){
        hostel = fopen("BH-3.txt", "+a");
        fprintf(hostel, "%s\n", add.hostelblock);
        fclose(hostel);
    }
    fclose(ptr);
    printf("\nStudent added succesfully\n");
    add_invalid:
    printf("Enter 1 to go back to main menu or 0 to exit\n");
    scanf("%d", &main_exit);
    if(main_exit==1)
        menu();
    else
        goto add_invalid;
}
void erase(){
    system('CLS');
    int test = 0;
    FILE *old, *newrec;
    old = fopen("record.txt", "r");
    newrec = fopen("new.txt", "w");
    printf("Enter the roll no. of the students you want to delete\n");
    scanf("%s", &rem.rollno);
    while(fscanf(old, "%s %s %s %s %s %s %s\n", add.gender, add.location, add.name, add.hostelblock, add.phone, add.rollno, add.Roomno)!= EOF){
        if(strcmp(add.rollno,rem.rollno)==1)
            fprintf(newrec,"%s %s %s %s %s %s %s\n", add.gender, add.location, add.name, add.mail, add.phone, add.rollno, add.Roomno);
        else{
            test ++;
            printf("\nStudent successfully removed\n");
        }
    }
    fclose(old);
    fclose(newrec);
    remove("record.txt");
    rename("new.txt", "record.txt");
    if(test == 0)
        printf("\nRecord not found\n");
    erase_invalid:
        printf("Enter 0 to try again 1 to go to main menu and 2 to exit");
        scanf("%d", &main_exit);
        if(main_exit==1)
            menu();
        else if(main_exit==2)
            close();
        else if(main_exit==0)
            erase();
        else{
            printf("\nInvalid\n");
            goto erase_invalid;
        }
}
void edit(){
    system('CLS');
    int choice, test = 0;
    FILE *old, *newrec;
    old = fopen("record.txt", "r");
    newrec = fopen("new.txt", "w");
    printf("Enter the roll no. of the students you want to change\n");
    scanf("%s", upd.rollno);
    while(fscanf(old, "%s %s %s %s %s %s %s\n", add.gender, add.location, add.name, add.mail, add.phone, add.rollno, add.Roomno)!= EOF){
        if(strcmp(add.rollno,upd.rollno)==1){
           test = 1;
           printf("What do you want to change\1.Room no\n2.Phone\(Enter 1 or 2 to change room number or phone)");
           scanf("%d", &choice);
           if(choice == 1){
                printf("Enter the room no>>");

                scanf("%s", upd.Roomno);
                fprintf(newrec,"%s %s %s %s %s %s %s\n", add.gender, add.location, add.name, add.mail, add.phone, add.rollno, upd.Roomno);
                printf("Changes saved");}
            else if(choice==2){
                printf("Enter phone you want to change>>");
                scanf("%s", upd.phone);
                fprintf(newrec,"%s %s %s %s %s %s %s\n", add.gender, add.location, add.name, add.mail, upd.phone, add.rollno, add.Roomno);
                printf("Changes saved");
            }
            else
                 fprintf(newrec,"%s %s %s %s %s %s %s\n", add.gender, add.location, add.name, add.mail, add.phone, add.rollno, add.Roomno);
           }
    }

    fclose(old);
    fclose(newrec);
    remove("record.txt");
    rename("new.txt", "record.txt");
    if(test != 0)
        printf("\nRecord not found\n");
    edit_invalid:
        printf("Enter 0 to try again 1 to go to main menu and 2 to exit");
        scanf("%d", &main_exit);
        if(main_exit==1)
            menu();
        else if(main_exit==2)
            close();
        else if(main_exit==0)
            edit();
        else{
            printf("\nInvalid\n");
            goto edit_invalid;
        }
}

// close the program
void close(){
    system('CLS');
    printf("\nThank you for Visiting All Safe\nHAVE A GOOD DAY\n");
}
